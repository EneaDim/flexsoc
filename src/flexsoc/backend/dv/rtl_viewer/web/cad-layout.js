'use strict';
/* Pure, deterministic scope-local layout. A net is routed once as a hyperedge. */
(function(root, factory) {
  const api = factory();
  if (typeof module === 'object' && module.exports) module.exports = api;
  else root.FlexCADLayout = api;
})(typeof globalThis !== 'undefined' ? globalThis : this, function() {
  const step = 26, pinMargin = 48, width = 238;
  const input = d => ['input', 'in', 'ref'].includes(d);
  const output = d => ['output', 'out'].includes(d);
  function compute(schematic) {
    if (schematic.schema !== 'flexsoc.rtl_viewer.schematic.v1') throw Error('Unsupported schematic schema');
    const components = [], pins = new Map(), nets = [];
    const byComponent = new Map();
    for (const component of schematic.components) byComponent.set(component.id, []);
    for (const pin of schematic.pins) {
      if (!byComponent.has(pin.component)) throw Error('Pin references missing component: ' + pin.id);
      byComponent.get(pin.component).push(pin);
    }
    // Preserve elaborated order and retain every instance, even if module types repeat.
    // Size each symbol from its own pin density. Global maximum pin counts
    // create huge, mostly empty rows on mixed-size SoC scopes.
    let nextY = 110;
    schematic.components.forEach(c => {
      const entries = byComponent.get(c.id);
      const left = entries.filter(p => !output(p.direction));
      const right = entries.filter(p => output(p.direction));
      const x = 340, y = nextY;
      const h = Math.max(100, Math.max(left.length, right.length) * step + pinMargin * 2);
      nextY += h + 52; // reserved clearance for labels and local routing
      components.push({...c, x, y, w: width, h});
      left.forEach((p, j) => pins.set(p.id, {...p, x, y: y + pinMargin + j * step, side:'left'}));
      right.forEach((p, j) => pins.set(p.id, {...p, x:x + width, y: y + pinMargin + j * step, side:'right'}));
    });
    // Scope inputs belong on the west edge; scope outputs belong on the east.
    // This is a presentation convention only: electrical membership is entirely
    // determined by schematic.nets[].terminals, never by the pin's placement.
    // Keep external output terminals strictly east of every wire trunk.
    // Width is determined by the semantic net count, not guessed connections.
    const wireLaneStart = 340 + width + 55;
    const wireLaneEnd = wireLaneStart + Math.max(0, schematic.nets.length - 1) * 22;
    const rightEdge = Math.max(640, wireLaneEnd + 115,
      ...components.map(c => c.x + c.w + 110));
    // Align external ports with the elaborated terminals of their own nets.
    // This is *placement only*; terminals are never matched by signal names.
    const targets = new Map();
    for (const net of schematic.nets) {
      const internal = net.terminals.map(t => pins.get(t.pin)).filter(Boolean);
      if (!internal.length) continue;
      const ys = internal.map(p => p.y).sort((a,b) => a-b);
      const middle = ys[Math.floor((ys.length-1)/2)];
      for (const terminal of net.terminals) {
        if (!targets.has(terminal.pin)) targets.set(terminal.pin, []);
        targets.get(terminal.pin).push(middle);
      }
    }
    for (const side of ['left','right']) {
      const ports = schematic.ports.filter(p => (output(p.direction)?'right':'left')===side);
      const wanted = ports.map((p,i) => {
        const positions = (targets.get(p.id)||[]).sort((a,b)=>a-b);
        return {p, i, ideal:positions.length ? positions[Math.floor((positions.length-1)/2)] : 100+i*36};
      }).sort((a,b)=>a.ideal-b.ideal||a.i-b.i);
      let previous=-Infinity;
      // Preserve order but guarantee enough space for port labels and glyphs.
      for (const item of wanted) {
        const y=Math.max(100,item.ideal,previous+36);
        pins.set(item.p.id,{...item.p,x:side==='right'?rightEdge:28,y,side,scopePort:true});
        previous=y;
      }
    }
    // One geometrical stub per *semantic pin*, even if multiple net records
    // refer to that pin. A fork starts at the stub end, never on the symbol.
    // The graph and individual net memberships remain unchanged.
    const externalInputNets = schematic.nets.filter(net => net.terminals.some(t => {
      const p = pins.get(t.pin); return p?.scopePort && p.side === 'left';
    }));
    const inputRanks = new Map(externalInputNets.map((n,i) => [n.id,i]));
    // Put scope-input routing lanes between external inputs and instance inputs.
    // Reserve clearance for a short forward-going stub at each input.
    const leftStart = 105, leftEnd = 292;
    const leftSpacing = externalInputNets.length > 1
      ? Math.min(14,(leftEnd-leftStart)/(externalInputNets.length-1)) : 14;
    const usedStubs = new Map();
    const componentRects = new Map(components.map(c => [c.id,c]));
    function breakout(pin) {
      // Scope inputs source the flow to the east, scope outputs receive it
      // from the west. Instance ports follow their own declared side.
      const dx = pin.scopePort ? (pin.side === 'left' ? 18 : -18)
        : (pin.side === 'right' ? 18 : -18);
      return [pin.x+dx,pin.y];
    }
    schematic.nets.forEach((net, i) => {
      const ends = net.terminals.map(t => ({...t, position:pins.get(t.pin)}));
      if (ends.some(e => !e.position)) throw Error('Unknown terminal on net ' + net.id);
      if (!ends.length) return;
      const ys = ends.map(e => e.position.y);
      const trunkX = inputRanks.has(net.id)
        ? leftEnd - inputRanks.get(net.id)*leftSpacing
        : wireLaneStart + i*22;
      const lo = Math.min(...ys), hi = Math.max(...ys);
      const branches = ends.map(e => {
        const p=e.position, stem=breakout(p);
        const old=usedStubs.get(e.pin);
        if (old && (old[0]!==stem[0] || old[1]!==stem[1]))
          throw Error('Inconsistent pin breakout: '+e.pin);
        usedStubs.set(e.pin,stem);
        // Branches start at the shared breakout. A backward route, if required
        // by a feedback relation, never turns directly at the pin boundary.
        let route=[stem,[trunkX,p.y]];
        const rect=componentRects.get(p.component);
        // Never let a branch reverse through its own component body.
        // Local escape corridors precede global lane routing.
        if(rect && p.side==='left' && trunkX>p.x){
          const escape=rect.y-20;
          route=[stem,[stem[0],escape],[trunkX,escape],[trunkX,p.y]];
        } else if(rect && p.side==='right' && trunkX<p.x){
          const escape=rect.y+rect.h+20;
          route=[stem,[stem[0],escape],[trunkX,escape],[trunkX,p.y]];
        }
        return {pin:e.pin,mapping:e.mapping,points:route};
      });
      nets.push({...net, trunk:[[trunkX,lo],[trunkX,hi]], branches,
        junctions:[...new Set(ys)].filter(y => (y>lo && y<hi) || ends.filter(e=>e.position.y===y).length>1).map(y => [trunkX,y])});
    });
    const stubs=[...usedStubs].map(([pin,to]) => {
      const p=pins.get(pin);return {pin,points:[[p.x,p.y],to]};
    });
    // Electrical junctions belong only to a single semantic net. Intersections
    // between different nets are visual crossings, never implicit connectivity.
    // Trunks are already ordered by their unique routing lanes. Binary-search
    // only lanes geometrically spanned by a branch, rather than checking every
    // net for every terminal (quadratic on large designs).
    const trunks = nets.map(n => ({net:n.id, x:n.trunk[0][0],
      lo:n.trunk[0][1], hi:n.trunk[1][1]})).sort((a,b) => a.x-b.x);
    function lowerBound(x) {
      let low=0, high=trunks.length;
      while(low<high){const mid=(low+high)>>>1;
        if(trunks[mid].x < x)low=mid+1;else high=mid;}
      return low;
    }
    const crossings = [], seen = new Set();
    for(const branchNet of nets)for(const branch of branchNet.branches){
      const [[x0,y0],[x1,y1]] = branch.points;
      if(y0!==y1||x0===x1)continue;
      const left=Math.min(x0,x1)+7, right=Math.max(x0,x1)-7;
      for(let i=lowerBound(left);i<trunks.length&&trunks[i].x<right;i++){
        const trunk=trunks[i];
        if(trunk.net===branchNet.id||y0<=trunk.lo+7||y0>=trunk.hi-7)continue;
        const key=JSON.stringify([trunk.x,y0,branchNet.id,trunk.net]);
        if(seen.has(key))continue;
        seen.add(key);
        crossings.push({x:trunk.x,y:y0,net:branchNet.id,over:trunk.net});
      }
    }
    crossings.sort((a,b)=>a.x-b.x||a.y-b.y||String(a.net).localeCompare(String(b.net)));
    return {components, pins:[...pins.values()], nets, stubs, crossings,
      bounds:{w:Math.max(950, ...components.map(c=>c.x+c.w+70), ...nets.map(n=>n.trunk[0][0]+90), ...pins.values().map(p=>p.x+90)),
              h:Math.max(400, ...components.map(c=>c.y+c.h+70), ...pins.values().map(p=>p.y+80))}};
  }
  return {compute};
});
