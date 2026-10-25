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
    const maxPins = Math.max(1, ...Array.from(byComponent.values(), a => a.length));
    const rowHeight = Math.max(116, maxPins * step + pinMargin * 2);
    schematic.components.forEach((c, i) => {
      const entries = byComponent.get(c.id);
      const left = entries.filter(p => !output(p.direction));
      const right = entries.filter(p => output(p.direction));
      const x = 340 + i * 310, y = 110 + i * rowHeight;
      const h = Math.max(100, Math.max(left.length, right.length) * step + pinMargin * 2);
      components.push({...c, x, y, w: width, h});
      left.forEach((p, j) => pins.set(p.id, {...p, x, y: y + pinMargin + j * step, side:'left'}));
      right.forEach((p, j) => pins.set(p.id, {...p, x:x + width, y: y + pinMargin + j * step, side:'right'}));
    });
    const portX = 28;
    schematic.ports.forEach((p, i) => pins.set(p.id, {...p, x:portX, y:100 + i * 36, side:'port'}));
    // Each net receives its own vertical lane. Multiple terminal branches share
    // one trunk and only intentional shared junctions are marked as connected.
    schematic.nets.forEach((net, i) => {
      const ends = net.terminals.map(t => ({...t, position:pins.get(t.pin)}));
      if (ends.some(e => !e.position)) throw Error('Unknown terminal on net ' + net.id);
      if (!ends.length) return;
      const xs = ends.map(e => e.position.x), ys = ends.map(e => e.position.y);
      const trunkX = Math.min(...xs) + 135 + i * 22;
      const lo = Math.min(...ys), hi = Math.max(...ys);
      const branches = ends.map(e => ({pin:e.pin, mapping:e.mapping,
        points:[[e.position.x,e.position.y],[trunkX,e.position.y]]}));
      nets.push({...net, trunk:[[trunkX,lo],[trunkX,hi]], branches,
        junctions:[...new Set(ys)].filter(y => ends.filter(e=>e.position.y===y).length || (y!==lo && y!==hi)).map(y => [trunkX,y])});
    });
    return {components, pins:[...pins.values()], nets,
      bounds:{w:Math.max(950, ...components.map(c=>c.x+c.w+70), ...nets.map(n=>n.trunk[0][0]+90)),
              h:Math.max(400, ...components.map(c=>c.y+c.h+70), ...pins.values().map(p=>p.y+80))}};
  }
  return {compute};
});
