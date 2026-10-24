# FlexSoC RTL Schematic Viewer — architecture & first implementation

**Status: initial working AST-backed viewer; advanced RTL connectivity and production-scale benchmarks pending.**

## Product contract

One Slang elaboration is the source of truth; RTL text is **never** parsed with regex to infer graph connectivity, instance names or generate expansion. The compiler runs with `--ast-json --ast-json-source-info`; the Python graph adapter consumes compiled AST objects, not filenames or guessed source patterns. The browser requests graph slices by hierarchy scope, not a monolithic rendered SVG. The web UI has no cloud services and no mandatory Node/npm build step.

The user can point at **any folder layout** using `--root`, explicit `--file` flags or Slang `-F` filelists, include paths and defines. No implicit requirements such as matching module and file names. The graph is elaborated for the chosen top and parameters, not created by scanning all `*.sv` files.

### Architecture (as implemented)

```text
User RTL / -F filelists  ->  slang (compile + elaborate)
                         ->  AST JSON  (source locations, instances, members)
                         ->  RtlDesign (stable scoped IDs, lazily projected per module)
                         ->  localhost /api/overview|diagram|source|follow|cone|lint
                         ->  Canvas2D viewport  |  SystemVerilog source / Slang diagnostics
```

- **SlangProject** (compiler.py): explicit top, source, macros and include paths, subprocess without shell, fails closed if compilation fails. `--ast` permits importing an existing Slang AST without re-elaboration, but an imported file is labeled *unverified*.
- **RtlDesign** (model.py): indexes the elaborated hierarchy, builds module-local nodes and only AST-proven dependencies, stores stable IDs `instance/path::sig:name`, and materializes individual module graph slices on request. Slang ephemeral memory addresses are removed from revision hashing.
- **ViewerServer** (server.py): Python standard-library HTTP API, loopback only by default; bounded node budgets and source file sandbox. No exposed arbitrary filesystem API. Remote bind requires an explicit warning flag, without authentication (do not expose to untrusted networks).
- **Workbench** (web/): compact electronic-design styling, Canvas2D drawing with viewport rejection, SVG/DOM-free diagram objects, zoom/pan, back/breadcrumb, module drill down, generate stacks by default, explicit explode, persisted in-memory pan/zoom and layout cache per hierarchy path, selection/pin, CTRL/Cmd signal tracking if binding is proven, accessible button list, contextual right-click `View SystemVerilog` and `Module lint`, adjacent RTL source pane, AST source line navigation, bounded module-local From→To query.
- **Lint hook**: reads a Slang lint summary from `--run` when available, matching canonical source file paths, not signal name. Diagnostic attribution is conservatively **file-level** until Slang source ranges are available for all tool versions. No lint/CDR/STA overlays are implemented.

## Run

From the FlexSoC repository root with Python 3.10+:

```bash
# Compile and elaborate the three-file DSP, then open localhost:8765
python scripts/rtl_viewer.py --root examples/rtl_schematic_dsp --top DSP \
  --file DSP.sv --file DSP_core.sv --file DSP_lane.sv

# Existing elaboration from fx slang_hier, with optional Slang lint run
python scripts/rtl_viewer.py --root /path/to/project --top your_top \
  --ast /path/to/run/dv/slang_hier/ast.json --run /path/to/run

# Vendor/open-source IP with arbitrary paths and dependencies:
python scripts/rtl_viewer.py --root /path/to/ip --top your_top \
  --filelist rtl/rtl.f --include rtl/include --define USE_FEATURE=1

# No Slang available? Preview ONLY (a clearly unverified, manually authored AST fixture):
python scripts/rtl_viewer.py --root examples/rtl_schematic_dsp --top DSP \
  --ast examples/rtl_schematic_dsp/DSP.mock_ast.json
```

Use `--check` to elaborate and print graph information without opening HTTP. `slang` comes from [MikePopoloski/slang](https://github.com/MikePopoloski/slang/releases), **not NVIDIA shader-slang**. If the executable is missing, install its Linux release in your WSL PATH. The viewer never silently switches to a regex-based parser.

Docker only: `--listen 0.0.0.0 --allow-remote --port 8765` (publish only to the host loopback, `-p 127.0.0.1:8765:8765`).

## RTL semantics and safety boundaries

| Feature | V1 behavior | What is deliberately not inferred |
| --- | --- | --- |
| Hierarchy | Walk compiled Slang `Instance` and generate array AST objects | No guesses based on matching module or filenames |
| Generate | Group replicated **elaborated** child instances with count; expand on request | No claims about unelaborated conditional branches |
| Ports/buses | AST direction/type; names scoped to instance path | No slice-level bit mapping by naming convention |
| CTRL selection | Follow exactly one AST `NamedValue` direct port binding | No fabricated follow for concat/part-select/ambiguous bindings |
| Register | Marker for signals assigned under a recognized `AlwaysFF` procedural block | Not every procedural or inferred latch is characterized |
| Cone | BFS on explicit AST assignment dependencies in one scope, bounded paths and length | Not a timing path, does not traverse complex expressions/instances |
| Source | AST source location resolved *inside project root*; clicking code lines may focus mapped signals | Unmapped locations remain unresolved, no invented declarations |
| Lint | Optional Slang diagnostics filtered by canonical file | Not exact module/instance-specific attribution |

**Important current limitations:** Slang AST serialization evolves; this first adapter recognizes core Instance, Port, Variable, Net, basic Assignment/ProceduralBlock and GenerateBlock forms. Actual DSP AST compilation has not been verified in this environment because Slang is unavailable here. Real compiler smoke tests on WSL are an explicit acceptance gate. AST load is currently a single JSON parse at launch; lazy **graph queries** are implemented, but streaming AST and a web worker layout are future steps. Complex continuous assignments, clock/reset/enable identification, register bit slices and cross-hierarchy cone are incomplete and are never silently represented as proven. Source view is read-only but syntax coloring and full bidirectional AST reference decorations require a dedicated editor integration (Monaco candidate).

## Frontend/library research and design practice (October 2026)

| Technology / methodology | License/maintenance | Decision |
| --- | --- | --- |
| [Anthropic frontend-design skill](https://github.com/anthropics/skills/tree/main/skills/frontend-design) | Skill-specific license; read before copying | Applied intentional product-centric typography, spacing, contrast; **not copied or vendored** |
| [Slang SystemVerilog](https://www.sv-lang.com/command-line-ref.html) | Upstream license; actively developed | **Required** source-of-truth elaborator |
| [ELK.js](https://github.com/kieler/elkjs) | EPL-2.0 / documented secondary GPL licensing | Candidate for worker hierarchical port layout; not vendored in V1 |
| [React Flow](https://reactflow.dev/) | MIT; actively maintained | Benchmark alternative for smaller editable graphs; no React dependency in current Python CLI |
| [PixiJS](https://github.com/pixijs/pixijs) | MIT; actively maintained | GPU-accelerated candidate for very large designs |
| [Monaco Editor](https://github.com/microsoft/monaco-editor) | MIT; actively maintained | Candidate for read-only syntax/declaration/driver/consumer decorations |
| Current Canvas2D | Built-in browser API; no third-party licensing | Implemented as smallest working baseline, with viewport culling and in-memory layout cache |

**Why not freeze a renderer now?** A professional production decision requires *measured* 100 / 1,000 / 10,000 element benchmarks on Chrome + Firefox and real UART/GPIO/Ethernet elaborations, comparing first paint, pan/zoom p95, worker layout, heap and labels. This is pending; V1's simple three-column cached layout is not a substitute for ELK hierarchical routing.

## Scope of this delivery & acceptance

Included: DSP/DSP_core/DSP_lane with 8 generate lanes, synthetic AST fixture for offline mockup, `rtl_viewer_mockup.html` (fully self-contained and interactive), tests for topology, generate aggregation, source mapping, unresolved mappings, sequential marking, cone, compiler invocation and localhost API. All fixture outputs are explicitly **not** proof of successful compilation.

Not included: post-synthesis netlists, STA, lint/CDC overlays, Monaco, WebGL, accurate gate-level schematics, hierarchical cone slicing across arbitrary parameterized buses. No modification to the existing FlexSoC `qualify`, provenance or packaging code.

## API contract (v1)

`GET /api/overview`, `/api/diagram?path=/&explode=0&limit=320`, `/api/source?path=/`, `/api/follow?path=/&child=/foo&signal=/::sig:bar`, `/api/cone?path=/&from=...&to=...`, `/api/lint?path=/`. JSON responses are bounded and use stable hierarchy-qualified IDs; an unresolved relation has an explicit reason. All paths refer to *hierarchical scopes*, never arbitrary server file paths.

## Public Slang AST compatibility fixtures

The project includes `tests/rtl_viewer/fixtures/published_slang_adder_excerpt.json`:
a **shortened excerpt** of actual serialized AST printed in [Ming Yang's Slang
adder walkthrough](https://threelambda.com/en/2024/07/18/2024-7-18-slang-ast-hier-tree/).
It retains the real compiler's structure (separate `Port` and backing
`Variable` objects with the same name, `internalSymbol` pointers,
`ContinuousAssign` and `BinaryOp`). A test checks port directions,
expression edges and stable IDs. The [Slang official user
manual](https://www.sv-lang.com/user-manual.html#serialization-output) and
[Mike Popoloski's GitHub AST example](https://github.com/MikePopoloski/slang/discussions/1423)
independently confirm the same serialized port/variable structure.

**The excerpt is an upstream reference, not a DSP compilation.** The DSP
`*.mock_ast.json` is explicitly a hand-authored offline demo. For actual RTL
correctness, run `slang --top DSP --ast-json ... --ast-json-source-info` via
`python scripts/rtl_viewer.py --root ... --top DSP --file ...`, then run the
real-compiler acceptance test below on a machine with Slang installed.

When importing a large real design, keep Slang's instance caching enabled for
speed. Only use `--expand-cached-instances` if the serialized AST contains
incomplete repeated instance bodies; measure peak RAM because that option can
make compilation much heavier. The adapter does not infer missing bodies from
instance names.

## V2 — schematic symbols, selectable wires, complex FIR acceptance

The V2 graph slice includes AST-proven port bindings and operator symbols,
without deriving topology from RTL filenames, regex, or textual instance names.
Each graph edge has a **stable scope-qualified wire ID**, source and target,
`net` identity, original port name (where applicable), width declaration and
an aggregation count for collapsed generate groups. It denotes **logical RTL
connectivity**, *not* an equivalence-class net or a physical routed wire.
Only direct, whole-signal port bindings are resolved; bit / part selections,
concatenations and interface modports are not currently reconstructed.

| Symbol | V2 depiction | AST origin |
| --- | --- | --- |
| Input/output port | Directional pentagon, bus declaration | `Port` / `InterfacePort` |
| Intermediate signal | Wire-like stub with explicit junction | `Variable` / `Net` |
| Combinational operator | Distinct diamond | RHS AST `BinaryOp` et al. |
| Flip-flop boundary | D/Q block, clock glyph | Destination in AST `AlwaysFF` |
| Schematic module | Component with *named* left/right ports | Elaborated `Instance` + `Port` |
| Repeated generate | Offset component stack with instance count | Elaborated generate siblings |
| Routed wire | Orthogonal segments, endpoint arrow and hit-tested line | Explicit assignment or direct port binding |

Selecting a wire segment highlights all edges with the same stable local
signal ID, and Ctrl/Cmd+click pins the net. A context action lets keyboard or
touch-only users pin without the modifier. Source lines in the right panel are
individually clickable when an AST-mapped declaration line exists; opening the
inspector resizes/refits the schematic instead of overlaying it on desktop.

The current layout algorithm is a **cached lightweight rank-column layout**
with viewport culling and per-scope graph loading. It is not an ELK layout;
it can produce overlap or long detours on high-fanout graph slices. A browser
hit-test still linearly scans the bounded module-local edges (`limit<=1500`).
Advanced autorouting, worker layout, subgraph virtualization and a syntax
aware source editor remain deliberate production follow-ups. Sequential
clock/reset/enable signals are not inferred by naming; glyphs describe
register *roles*, not an unproven pin-level connectivity relationship.

### Acceptance commands

```bash
python -m pytest -q tests/rtl_viewer
python scripts/build_rtl_viewer_mockup.py --complex
python scripts/rtl_viewer.py --root examples/rtl_schematic_dsp_complex \
  --top DSP_stream --file DSP_stream.sv --file DSP_frontend.sv \
  --file DSP_fir.sv --file DSP_mul_lane.sv --file DSP_saturate.sv --check
```

`--check` with source files **requires slang**. Importing the clearly labeled
mock AST with `--ast` exercises the viewer but is not compilation validation.

## V3 — engineering workbench chrome and contextual actions

The toolbar contains **only module-independent actions**: module search,
source / lint / cone inspector views, zoom and fit. Selecting the current
module from the hierarchy or breadcrumbs remains navigation, not a graph
mutation. Generated groups no longer occupy permanent toolbar space:
right-click a stack to **Expand instances** or an individual generated
instance to **Collapse instances**. The backend now accepts
`GET /api/diagram?path=...&expand=<group>` and expands only that elaborated
group; graph layout is cached per scope / expanded-set / AST revision. The
legacy `explode` parameter remains on the internal Python graph method for
unit-test compatibility, but the V3 UI does not expose global explosion.

Context actions remain specific to the selected symbol; source, lint and
cone panels remain available globally and apply to the currently displayed
RTL module. The frontend offers keyword search of the **currently loaded**
graph, Ctrl/Cmd signal tracking, keyboard fallback and a keyboard-operable
resize handle. The inspector can be opened without destroying the saved
per-module viewport. Search does not scan or elaborate other modules.

Design methods reviewed for this revision:

- [Anthropic Frontend Design](https://github.com/anthropics/skills/blob/main/skills/frontend-design/SKILL.md): purpose-driven visual identity; no generic dashboard cards.
- [Vercel Web Interface Guidelines](https://github.com/vercel-labs/web-interface-guidelines): focus indication, labels, keyboard, and reduced motion.
- [Addy Osmani agent skills](https://github.com/addyosmani/agent-skills): test-first incremental UI, performance budgets and explicit review.

No new runtime dependencies or font downloads were introduced. Canvas2D,
module-scope loading and bounded cached layout remain unchanged. A11y
and rendering work beyond this V3 (full keyboard canvas navigation,
semantic netlist descriptions, signal-level lint mapping and a layout worker)
remain open rather than being represented as complete.

The self-contained HTML uses an **uncompiled fixture**. Real RTL elaboration
still requires Slang, as documented in the V1/V2 acceptance section.

## V4 · Directional wiring, packed/unpacked and FlexSoC themes

- The graph adapter uses only elaborated Slang connections, including variants
  serialized on child port symbols. Equal names are **not** sufficient to draw
  a wire. Direct ports and transparent conversions are resolved; AST element,
  range and member selections yield a **partial** parent-bus dependency shown
  with a dashed wire, never a fabricated bit-level map. CTRL/Cmd tracking
  crosses only unique direct bindings. More complex expressions remain unresolved.
- Slang type text is kept for labels; explicit AST `packedDimensions` and
  `unpackedDimensions` are transported separately, with no SystemVerilog-text
  parsing or inferred array extents. Directional arrowheads terminate at sinks.
- The lightweight Canvas router reserves separate x-tracks per graph edge,
  checks clearance for forward routes and uses an outer cable duct for edges
  that cross occupied columns or feed back. This reduces *overlap* but does not
  claim globally optimal crossing minimization: ELK/orthogonal router comparison
  remains future work. Render culling and per-scope layout caching remain active.
- Breadcrumbs come from actual elaborated scopes; unnamed intermediary
  generate folders are not offered as broken navigation links. The persistent
  header supports clicking any real ancestor module. Browser theme preference
  changes between FlexSoC navy/black/orange/sky dark and light without
  recompiling Slang or reloading the graph.
- Stress fixture: `examples/rtl_schematic_dsp_parallel/` contains 64 generated
  MAC lanes and unpacked arrays of packed signed words. It **must** be compiled
  via Slang to view; no hand-authored AST is presented as compiler output.
- Current limits: no bit-exact slice/concatenation mapping, no netlist equivalence,
  no guarantee of zero wire *crossings* in arbitrarily dense layouts, and no
  physical timing-path assertions. Large generate arrays remain collapsed and
  diagram response limits/culling bound the first render.

## V5 — router per modulo, corridoi e crossing bridge

Il renderer rimane Canvas 2D, mentre `web/router.js` è ora un **layout engine puro**:
prende `graph.nodes` / `graph.edges`, `boxSize` e `baseRank` e restituisce
`positions`, `edgePaths` e le coordinate delle intersezioni da rappresentare
con un piccolo *wire bridge*. Il modello RTL non viene mutato e nessuna connessione
è dedotta da nomi, sintassi testuale, colori o geometria.

1. Rank bounded e quattro sweep baricentrici alternati, ordinati in modo stabile.
2. Baseline di riga condivise fra colonne per mantenere allineate le datapath parallele
   con simboli di altezze diverse.
3. Tracks di canale allocati per intervalli verticali non sovrapposti (riuso di corsie).
4. Connessioni lunghe e feedback instradate prima nei corridoi liberi fra righe;
   fallback al canale superiore solo quando tutti i corridoi sono occupati.
5. Intersezioni perpendicolari di net distinti marcate con *wire bridge* visivo.
   Sono esclusi gli incroci dello stesso ID net; i bridge non cambiano il grafo.
6. Rendering degli edge visibili e dei bridge visibili; cache di layout per
   scope/revision/espansione, invalidata dal cambio di graph key; mockup HTML
   autonoma con lo stesso router incluso inline.

**Limiti consapevoli:** questa è una euristica di instradamento leggero, non
ELK né un router fisico. Non garantisce il minimo globale degli incroci o
l'assenza totale di segmenti sovrapposti per grafi arbitrari. La topologia
resta RTL AST-proven; `mapping=partial` sulle slice packed/unpacked indica
soltanto la dipendenza dal bus, mai un mapping bit-a-bit. I generate sono
lazy/collassati; i layout vengono ricostruiti quando un gruppo è espanso.

**Benchmark e criteri di accettazione:** `tests/rtl_viewer/test_router_v5.py`
usa 180 lane con ordine iniziale invertito e dimensioni diverse, controlla
stabilità geometrica, corsie riutilizzate, ortogonalità e isolamento dei
feedback. Chromium con il fixture DSP verifica l'HTML e le interazioni esistenti.
Le prove usano grafi sintetici, **non** un DSP elaborato con Slang reale:
serve ancora la validazione su WSL con `--check` e le RTL compilate. Un confronto
rigoroso con ELK.js in WebWorker resta una valutazione successiva; ELK ha
licenza EPL-2.0/GPL-3.0-or-later e richiederebbe una revisione di packaging
prima dell'inclusione.

## V6 — semantic connectivity, reverse flow and schematic components

The graph is **not** a topology reconstruction from signal names. `ASTReferences`
indexes elaborated `addr` and `Port.internalSymbol` identities for each scope.
Inside a module, direct assignments add `source → destination` edges. Across a
module boundary, `Instance.connections` / `portConnections` (or port-local
connection expressions) bind a *parent AST reference* to the child's port,
using the port's actual input/output direction. A differently named backing
Variable/Net is wired to its port only when `internalSymbol` matches its
actual symbol address. This prevents both false connections between unrelated
identically named nets and false disconnections of renamed ports.

Unpacked/packed `ElementSelect` and `RangeSelect` are projected as **partial**
bus dependencies. Dynamic indices, concatenations, casts with multi-source
bindings and arbitrary bit-level permutations are **not** claimed bit-exact;
Ctrl/Cmd follow remains intentionally conservative. Direction is exclusively
from RTL binding/assignment semantics. The router can draw a *backward*
(source-right / consumer-left) orthogonal edge entering the receiver on its
right face, preserving the final arrow's direction; it never reverses a data
edge to make a diagram aesthetically convenient.

The component language consists of distinct port, net, module, generate,
register, arithmetic ALU, mux and case-dispatch symbols. A self-accumulating
`always_ff` arithmetic assignment is displayed as a counter. An elaborated
enum-written state with an AST case reading it is displayed as **candidate FSM**,
not proof of FSM extraction or complete state analysis. Encoder/decoder glyphs
are supported in the renderer for future *explicitly classified* graph symbols,
not guessed from a module's text name or from a case alone. This preserves
semantic accuracy on arbitrary imported IP.

Theme and interaction: FlexSoC orange/sky/navy/graphite light/dark palettes;
responsive inspector and contextual menus with reduced-motion CSS fallback;
230 ms ease-out camera for Fit/Zoom (off when reduced motion is preferred).
Geometry and graph remain decoupled. Only visible nodes/wires are rendered;
no new frontend dependencies were added.

**Acceptance fixture:** `examples/rtl_schematic_flow_lab/DSP_flow_lab.sv` contains
renamed output/input ports, an intermediate continuous assignment, 4 generated
lanes with packed words in unpacked arrays, a sequential accumulator and a
conditional mux. `DSP_flow_lab.mock_ast.json` is *hand-authored* solely for
repeatable offline UI checks; it is **not** Slang output. Run:

```bash
PYTHONPATH=src pytest -q tests/rtl_viewer
python scripts/build_rtl_viewer_mockup.py --flow-lab
python scripts/rtl_viewer.py --root examples/rtl_schematic_flow_lab \
  --top DSP_flow_lab --file DSP_flow_lab.sv
```

The final command requires installed Slang and compiles the real SV to AST. On
systems without Slang, that integration test is skipped rather than silently
falling back to parsing SystemVerilog with regex. The host tool and browser
must still be verified together on the target WSL environment. A real
bit-accurate port/array tracer and proven encoder/decoder recognizers remain
separate tasks; a syntax-derived RTL cone is **not** a post-synthesis timing path.

## V7 — Geometry audit, sv-tests and editor-host integration (23 Oct 2026)

### Three independent validity layers

1. **Slang language/elaboration:** a valid SystemVerilog test must elaborate before a graph can exist. An intentionally invalid test is `negative_expected`, not a rendering failure. Macro-heavy tests can require their upstream-generated wrappers, includes and defines.
2. **RTL graph semantics:** `RtlDesign` projects elaborated modules, signals, assignments and actual port expressions. It never connects two pins merely because their names match. Parent/child port mappings remain partial when sliced/dynamic; no bit-exact claim is made.
3. **Layout geometry:** `router.js` owns both symbol geometry and Manhattan routing. A bounded congestion-aware pass scores foreign-symbol intersections and distinct-net conductor overlap, tries local side ducts before long upper/lower rails, and conserves the direction supplied by the RTL graph. The same JS module is loaded in the browser and by `rtl_viewer_layout_audit.js`. The latter checks orthogonality, finite symbol rectangles, foreign-symbol collisions, bridges and truncated layouts. No pass is reported for a skipped large-graph repair (`layout_partial`).

The V7 router did **not** claim an optimum layout or zero crossings for arbitrary designs: high-degree buses, bit selection, extremely dense feedback and more than 140 simultaneously visible wires required professional path planning and/or explicit hierarchical compression. V8 replaces that threshold with an indexed bounded audit (see below). A wire crossing with a bridge is not an electrical junction. An orange open-circle pin indicates that the AST provided no binding; orange does not imply an RTL error (open pins can be intentional). For source-level connectivity versus post-synthesis equivalence, use a separate future netlist viewer.

### Exhaustive corpus *instrumentation*, not fake certification

Obtain the upstream corpus (ISC license): <https://github.com/chipsalliance/sv-tests>.

```bash
# On WSL with slang, node and PyYAML installed:
git clone --depth 1 https://github.com/chipsalliance/sv-tests.git /tmp/sv-tests
cd /tmp/sv-tests && git submodule update --init --recursive && make generate-tests -j$(nproc)
cd ~/github/flexsoc
python scripts/rtl_viewer_svtests.py --suite /tmp/sv-tests --out workspace/reports/rtl_viewer_svtests.json --jobs 4
```

Without Slang, run `--inventory` and keep each result explicitly `not_run`. The program discovers all annotated `.sv` cases by default and reports results per chapter with distinct statuses: `negative_expected`, `slang_failed`, `no_elaborated_top`, `graph_truncated`, `graph_invalid`, `layout_collision`, `layout_invalid`, `layout_partial`, `layout_pass`, and infrastructure failures. `--max-tests` is only for debugging; reports disclose the discovered/tested counts and whether the inventory is complete. `layout_pass` means **AST+geometry checked**, *not* per-pixel comparison or formal functional equivalence.

Some sv-tests cases have multiple files, import packages, use generated third-party sources or are deliberately illegal. `slang_failed` is an unresolved compatibility failure, not proof that the renderer is wrong. Slang is the only RTL parser: comment-header metadata is read to choose inputs, never to invent connections. Track false-negative categories before claiming corpus coverage.

### VS Code / Cursor (preview)

`extensions/flexsoc-rtl-explorer/` provides a workspace-host extension, with a command and `.sv`/`.v` context action. It prompts for top and sources (or uses configured filelists), starts the Slang-backed Python service bound to a random **localhost** port, and hosts the existing workbench as a CSP-restricted Webview. Graph API reads are proxied by the extension host using `postMessage`: no CORS wildcard, CDN, separate TypeScript parser or direct Webview network permission. Session and subprocess die when the panel closes.

```bash
python scripts/package_rtl_viewer_extension.py
cd extensions/flexsoc-rtl-explorer
npm test
npx @vscode/vsce package --no-dependencies
```

Install the VSIX into VS Code or Cursor (and in WSL's extension host when running remotely). This is an early extension, **not yet validated on a live editor host**. Slang remains a separate project-local executable. The extension implements a filelist-driven workflow appropriate for arbitrary folder names and package/import syntax; project configuration must be explicit for nontrivial designs.

### Skill-informed design criteria

Consulted [Vercel Web Interface Guidelines](https://vercel.com/design/guidelines), [Anthropic Frontend Design](https://github.com/anthropics/skills/tree/main/skills/frontend-design) and [ELK.js](https://github.com/kieler/elkjs) before choosing the preview architecture: generous selection targets, keyboard alternatives, light/dark contrast, compositor-only motion and `prefers-reduced-motion`; geometry and Canvas must remain separable. ELK.js (EPL-2.0) is a candidate layered autorouter, **not bundled in V7**; benchmark it on actual flattened and hierarchical AST graphs before adding the dependency. No proprietary assets or unlicensed font files are included.

## V8 — Connection semantics before routing (23 Oct 2026)

**The Slang AST, not the renderer, is the authority for connectivity.** V8
isolates three responsibilities:

| Layer | Module | Invariant |
|---|---|---|
| Elaborated RTL resolution | `connectivity.SymbolTable`, `PortResolver` | Symbol address / parent scope only; never match parent and child names as a wiring heuristic |
| Directed graph | `connectivity.GraphEdges`, `RtlDesign` | Explicit driver→consumer dependencies; stable deduplicated wire IDs; graph-only cone and CTRL-follow |
| Layout and DRC | `web/router.js` | Manhattan geometry with stable port anchors and spatial-indexed collision checking; may **never** invent or reverse edges |

A write to `vector[index]` targets `vector`, **not** `index`. The index is
tracked separately as an addressing dependency. A concatenated lvalue has
multiple proven destinations. Implicit Slang `AssignmentExpression` port
connections, conversions and concatenations are projected conservatively:
only a whole-symbol identity is `direct`; non-bit-exact expressions are
`partial` and are not used to claim exact CTRL propagation. A known but
unmatched Slang symbol address is never resolved by its display name. Ports
whose `internalSymbol` points to a differently named backing declaration use
that declaration's identity regardless of AST member ordering.

A pin has four states: `bound` (proven direct whole-symbol connection),
`partial` (expression or bus dependency but unknown bit mapping, or only a
subset of generated instances bound), `unresolved` (Slang emitted a connection
expression not resolved by the adapter) and `unbound` (no connection recorded).
An unresolved pin is **not** necessarily physically open. The workbench uses
an orange question mark instead of silently drawing a false connection; the
API reports all three non-direct categories separately. A collapsed generate
is audited across **all** its instances, although only a bounded number of
instance paths is serialized for UI navigation.

The router now uses a spatial index to evaluate real symbol/wire collisions
for graphs beyond the previous 140-wire skip threshold. It tries neighboring
inter-row rails before global detours and includes detours in Fit extents. The
router still has a bounded **5,000 wire** interactive-audit budget; when that
is exceeded, the result reports `quality: not_audited` / `skipped` and must
not be called geometry PASS. For even larger graphs, navigate a narrower
hierarchical slice or supply a layout worker; do not silently pretend it was
fully checked. Zero collisions are **not** guaranteed for arbitrary graphs.

The `sv-tests` runner now reports `graph_unresolved` or
`layout_semantic_partial` when ports contain AST expressions it cannot map.
Intentional open pins, negative language tests and missing Slang are reported
separately. A layout PASS does **not** constitute bit-accurate RTL functional
equivalence or STA timing certification.

### Regression and reproducibility

```bash
python -m pytest -q tests/rtl_viewer
cd extensions/flexsoc-rtl-explorer && npm test && cd ../..
python scripts/build_rtl_viewer_mockup.py --flow-lab
# Run with the real tool in WSL to validate the Slang wire adapter:
python scripts/rtl_viewer.py --root examples/rtl_schematic_flow_lab \
  --top DSP_flow_lab --file DSP_flow_lab.sv
```

V8 tests cover renamed ports, parent symbol identity, output assignment
expressions, casts, concatenations, dynamic array selectors, 70 generated
instances with one unresolved binding, stable edge IDs, occupancy-score
parity and geometry-audited routing of 180 parallel wires. The HTML fixture
is still unverified AST and cannot substitute for the WSL Slang test.

## V9 — multi-file functional test and pin contract

The `examples/rtl_schematic_dsp_system/` design has eight independent
SystemVerilog source files with package types, registers, memory arrays, a
parallel MAC generate, arithmetic and FSM control. Slang is the *only* parser.
`RtlDesign.audit()` walks the entire elaborated hierarchy, reports source
ownership and pin states per scope, and fails strict qualification for missing
sources, unresolved/unbound ports or truncated graphs. This is a **viewer
integrity** audit, not proof of simulation behavior or equivalence.

The `OperatorResolver` projects AST operands onto explicit semantic pins:

| Operator | Source expression | Physical pin |
|---|---|---|
| MUX | `S ? TRUE : FALSE`: `FALSE` | `A` (left, upper, S=0) |
| MUX | `TRUE` | `B` (left, lower, S=1) |
| MUX | `S` | `S` (bottom, select) |
| MUX | expression output | `Y` (right) |
| Binary arithmetic | left/right operand | `A` / `B` (left, separate elevations) |
| Binary arithmetic | result | `Y` (right) |

`GraphEdges` carries the pin role as separate metadata from a *hierarchical
instance port name*. The Canvas glyph and router use the same `pinGeometry`
contract. The router must approach `S` vertically from below and `A/B` from
the left even when the source symbol is placed to the right. This keeps
physical pin identity independent of graph rank and direction.

Module source references are taken preferentially from definition members
serialized by Slang, not the enclosing *instance* source location. An absolute
or external source file outside the project is not opened or exposed by the
local server. Source-file mapping can be verified across all elaborated
submodules via the JSON audit report.

The optional end-to-end Slang test is skipped if slang is not installed.
An offline AST fixture can verify adapter and geometry invariants but must
never be reported as compiled RTL.
