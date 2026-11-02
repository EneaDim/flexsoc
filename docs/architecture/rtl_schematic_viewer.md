# FlexSoC RTL Schematic Viewer — architecture & first implementation

**Status: initial working AST-backed viewer; advanced RTL connectivity and production-scale benchmarks pending.**

## Inspector and symbol clarity — patch 023 (2 November 2026)

- The actual Canvas workbench now identifies Slang `Concatenation` projections
  with a compact **CONCAT** glyph rather than ambiguous `{ }` artwork. This
  identifies an AST operation, **not** proven bit mapping or an electrical cell.
- Instance input pins classified as constants show an **external** value label
  only when an explicit scalar literal is recorded in the elaborated Slang
  expression. Otherwise the label reads `CONST` without inventing a value.
  Generated groups require unanimous, proven literal values across members.
- The resizable right inspector separates **Overview**, **Connections**,
  **References**, **SystemVerilog**, **Lint** and **Paths**. Connections indicate
  direct, partial and non-rendered AST dependencies; the source panel explains
  missing or non-unique provenance instead of implying exact cross-probing.
  References expose only compiler-backed locations and retain existing
  file-level limits. Full compiler metadata remains available under the
  Overview evidence expander.
- Browser startup diagnostics retain browser-provided error stacks/locations
  when available. The prior WSL screenshot with `JavaScript error @ ?:?`
  could **not** be reproduced by the offline Chromium smoke test; this change
  does not claim to have identified its original root cause.
- Verified by `python3 -m pytest tests/rtl_viewer -q` with a browser fixture
  that loads the deployed HTML, JS and CSS into Chromium. That fixture mocks
  API responses; native Neovim, real local browser-to-server networking and
  full Ethernet RTL compilation still need validation on the user's WSL.

## Validation candidate after patch 015 (30 October 2026)

The actively served viewer follows **Slang AST → scoped graph with explicit
source provenance → ELK.js → Canvas**. Increments 009–015 distinguish register
Q feedback from the combinational next-state path to D. Supported expression
operators, bounded procedural MUXes, ordered nonblocking writes, and
**process-local blocking temporaries** are lowered from AST identities only.
For example, `tmp = q + 1; q <= tmp;` may project `Q → ADD → D` when the
`tmp` declaration and both write kinds are explicit. A blocking write to the
register itself, an uninitialized temporary, a conditional temporary write,
missing scheduling metadata, or ambiguous/multiple writers must **not** be
represented as a proven electrical connection. Unknown D values are marked
unresolved. This is a compiler-backed expression visualization, **not**
synthesis-equivalence evidence.

### WSL acceptance sequence

After applying all incremental packages through 015, from `~/github/flexsoc`:

```bash
# 1. Regressions (uses the active environment; no pip needed).
python3 -m pytest tests/rtl_viewer -q

# 2. Actual Slang elaboration + structural audit: do NOT substitute mock AST.
slang --version
python3 scripts/rtl_viewer.py --root examples/rtl_schematic_dsp \
  --top DSP --file DSP.sv --file DSP_core.sv --file DSP_lane.sv \
  --check --report /tmp/flexsoc-rtl-dsp-audit.json

# 3. Serve the same real design on localhost (Ctrl+C to stop).
python3 scripts/rtl_viewer.py --root examples/rtl_schematic_dsp \
  --top DSP --file DSP.sv --file DSP_core.sv --file DSP_lane.sv \
  --enable-neovim --port 8765
```

Open `http://127.0.0.1:8765` in a browser. The native Neovim pane needs
`nvim` and Python `msgpack` in the same WSL environment; if unavailable,
the read-only source viewer remains usable. Verify (1) hierarchy drill-down,
(2) ELK node/pin/wire endpoints, (3) source pane and source cross-probe,
(4) Q→operator→D net selection on a sequential RTL example,
(5) explicit unknown D for unsupported procedural forms,
(6) lint provenance when attaching an actual run, (7) keyboard navigation,
and (8) Neovim startup/mappings in your own environment. A successful UI
load alone is not evidence of compiler-backed connectivity.

In this development environment Slang and Neovim executables are **not
installed**. Tests use synthetic compiler-shaped ASTs and published AST
excerpts, real bundled ELK, and browser fixtures. Production Slang elaboration,
real Neovim, and full FlexSoC flow execution remain separate WSL acceptance
gates; do not mark them as verified based on mocked test data. The main viewer
and IDE extension still require one-source frontend consolidation and realistic
large-graph performance measurements before a production-complete declaration.

## Existing FlexSoC runs: directory-based selection (increment 018)

For a populated run such as `workspace/runs/ethernet/rtlviewer_axi_lite`, the
canonical directory identifies `WORKSPACE`, `RUN_TOP`, `RUN_ID`, and the default
`TOP` (the run owner). There is no need to type these four values separately:

```bash
cd ~/github/flexsoc
fx settings "$PWD/workspace/runs/ethernet/rtlviewer_axi_lite"
fx settings --workdir "$PWD/workspace"

# Inspect the existing Slang AST without recompilation.
python3 scripts/rtl_viewer.py \
  --run-dir "$PWD/workspace/runs/ethernet/rtlviewer_axi_lite" \
  --enable-neovim --port 8766
```

`fx settings <run-directory>` **persists** the selected identity in the
workspace's `.flexsoc/settings.json`. It preserves other configured settings
(PDK, clocking, interface, tool choices); none of these can be inferred safely
from folder names. `--run-dir` is **read-only**: it loads the run's existing
`dv/slang_hier/ast.json` and attaches that run for evidence inspection, without
editing settings, running Slang, or rewriting artifacts. Imported AST is
reported as imported/unverified, not a newly validated elaboration.

An arbitrary directory or a run without the Slang AST is rejected explicitly;
`--root/--top` with filelists remains supported for a fresh Slang elaboration.

### Shared source provenance and native Neovim (increment 019)

`--run-dir` continues to load the existing AST without re-elaboration. The
run's `rtl/` remains the primary source root. When that run is inside the
FlexSoC checkout, an additional **explicitly bounded** lookup permits
compiler-supplied source paths under the same repository (for example shared
IP in `hw/ips/` or `vendor/`). This fixes external-IP modules whose source
locations were previously rejected as "not project-local". The viewer does
**not** search by basename, parse RTL to guess file locations, follow symlinks
outside trusted roots, or serve files outside those roots. For a run outside
the checkout, authorize additional directories yourself:

```bash
python3 scripts/rtl_viewer.py \
  --run-dir /path/to/workspace/runs/ethernet/rtlviewer_axi_lite \
  --source-root /path/to/authorized/shared-ip \
  --enable-neovim --port 8766
```

A source missing from every authorized root remains unresolved and Neovim
cannot be started for that scope. The panel now reports that distinction. The
Neovim `redraw` decoder consumes the full event batch sent by `ext_linegrid`
(MessagePack-RPC), rather than only the first item. This does not substitute
for end-to-end verification with the user's installed Neovim and settings.

**Important:** these changes resolve *source file lookup and native editor
rendering*, not missing AST operator inputs in Ethernet. Incomplete/ambiguous
operand dependencies must still be reviewed against the actual Slang AST.

### Operator symbols and unsupported connections

The symbol catalog accepts explicitly recognized AST operation names such as
`BinaryAnd`, `BinaryOr`, and `BinaryXor` in addition to other Slang spellings.
Conversions receive a compact **type-adapter** glyph, not an assumed physical
cell. The inversion triangle and bubble are contained within the canonical
ELK terminal geometry. MUX inputs use A·0/B·1 to label select alternatives;
**only compiler-proven literals** are displayed as constants. Full AST source
paths stay in the inspector instead of crossing the symbol face.

A missing port or expression input is never silently connected by the painter.
`const`, `?`, and explicit unresolved markers are distinct statuses; missing
inputs in Ethernet must be evaluated against that run's actual elaborated AST,
not fixed by guessing a wire from the net name.

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

## RTL symbol readability — patch 006 (30 October 2026)

The active Canvas painter now uses an explicit **Slang operator label** catalog
shared with `symbol-geometry.js`. Recognized AST operations (arithmetic,
comparison, Boolean/bitwise AND/OR/XOR, unary NOT, conversions) receive
legible expression symbols; unknown operations remain visibly labeled `OP`
with a shortened original AST operation name, rather than appearing as an
arbitrary mathematical function or a fabricated standard cell. These are
**expression depictions**, not a post-synthesis cell netlist.

The D/Q sequential symbol reserves a separate lower control band so the
name does not overlap clock/reset terminals. A falling-edge bubble is drawn
only when `sequentialTiming` contains a matching compiler-backed
`NegEdge` with verified clock (`clock`/`single_event`) or asynchronous reset
(`async_reset`) role. Ambiguous event roles do **not** produce a false
polarity marker. ELK and Canvas still use the same canonical pin anchors.

Tests include Node Canvas command traces, real bundled-ELK wire endpoints and
Chromium rendering with synthetic AST labels. These do not prove new Slang
elaboration coverage or completeness of logic-synthesis symbol extraction.
Run `python3 -m pytest tests/rtl_viewer -q` for regression.

## Active architecture after patch 003 (30 October 2026)

The main RTL View at `src/flexsoc/backend/dv/rtl_viewer/web/` is **Slang
AST → graph projection → ELK.js → Canvas2D**. `symbol-geometry.js` defines
one anchor contract for all graph roles, including module `port` output
bindings and source/target `inout` pins. `elk-adapter.js` builds stable,
identifier-sorted ELK input with a single adjacency pass; geometry no longer
depends on JSON enumeration order. It does not reinterpret the semantic graph.

`layout-engine.js` is now a small adapter: it validates ELK output and finds
visual bridges only where **different net IDs** cross orthogonally away from
wire endpoints. Bridges never modify route polylines or add a junction to the
semantic graph. The number of drawn bridges is bounded; the UI explicitly
reports when the display limit is reached. ELK remains the only active layout
and router. The formerly dormant net-tree router and lane-refinement code
have been removed from this main web workbench. The separate legacy
`router.js` is retained for compatibility tests and the unmerged IDE extension,
not invoked for layout in the main web app.

The `net` field represents an RTL relationship identifier, **not** a proven
post-synthesis copper equivalence class. A drawn visual crossing must not be
read as a confirmed electrical junction. ELK may still produce congested
crossings on realistic SoCs; this increment does not claim globally optimal
routing or measured frame-rate improvements. Test with:

```bash
python3 -m pytest tests/rtl_viewer -q
python3 -m pytest tests/rtl_viewer/test_elk_layout_refactor_003.py -q
```

The real ELK tests cover multi-output ports with equal net IDs, inout pin
anchors, stable reordering, decorative crossovers, and large input conversion.
No proprietary EDA-tool end-to-end run or Neovim editor integration was
validated by this increment.

---

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

The current **main web workbench** uses bundled ELK.js for layered placement
and orthogonal routing, with shared Canvas/ELK pin geometry (`symbol-geometry.js`).
Old router descriptions in V2–V9 below are retained as historical notes, not
claims about the current active web renderer. The standalone VS Code extension
still includes an older renderer and has not yet been unified with the web app.
The browser hit-test still linearly scans the bounded module-local edges
(`limit<=1500`). Layout workers, subgraph virtualization and a full Vim/Neovim
source editor remain planned, not delivered. Sequential
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

### FSRTL-004 — physical fanout terminal identity and layer spacing

The active `web/elk-adapter.js` distinguishes **semantic edge identity** from
**physical terminal identity**. Several proven assignments/port bindings may
leave the same glyph terminal on the same net. ELK now receives one shared
source port for those edges (while keeping each original simple edge). The
source's pin is never named after a *downstream* module port. Named outputs
of module/generate instances remain separate, even when source net labels
coincide; different net labels also remain separate. No signal/net aliases
are synthesized and Canvas continues to use the same `symbol-geometry.js`
anchors as ELK.

For dense, compiler-derived fanout the ELK layer separation is increased from
120 to at most 184 layout units, based on the maximum per-source, per-net,
per-physical-pin number of edges (up to 3: 120; each additional load: +8;
maximum addition: 64). This is bounded **presentation geometry**, not a
statement about electrical load, wire length, STA, or bit-accurate bus routing.
The remaining routing and placement decisions are still delegated to ELK;
there is no secondary custom router. The fanout regression executes bundled
ELK and checks preserved edges, exact glyph terminal positions, orthogonal
routes, and stable layout under reversed AST enumeration. This rule increases
space on busy graphs but does not guarantee an optimal layout or zero wire
crossings; layout-performance benchmarks on large elaborated SoCs remain open.

### FSRTL-005 — Canvas symbol painter and label-safe module sizing

The active workbench now loads `web/symbol-painter.js` between
`symbol-geometry.js` and `app.js`. The painter owns the visual glyphs for
module/generate instances, ports, signals, operators, muxes, and sequential
registers; it does **not** own positions, routes, semantic identities or
connections. The UI passes only colors, selection state, current zoom,
visibility and compiler-derived event relationships. The painter restores
Canvas drawing state even when it returns early.

Module and generate symbols use a consistent inset chassis and header, with
legible left/right terminal columns and bounded text drawing. Named terminal
stubs terminate exactly at the shared `FlexSymbolGeometry.portRows()`
coordinates consumed by ELK. Unbound, unresolved, partial, constant and
bidirectional terminal indicators are still distinct; an unknown binding is
never drawn as a proven wire. Instance width grows deterministically with
input/output port label length (minimum 220, maximum 356 layout units) to
reduce collisions between long labels, while leaving the Slang graph intact.
Width is chosen **before** layout and is shared by ELK and Canvas. This is a
bounded readability improvement, not automatic pin reordering or a change
to routing semantics. Excessively long names are constrained within their
column; full signal names remain available in the inspector.

`tests/rtl_viewer/test_symbol_painter_005.py` checks that drawing keeps its
Canvas state balanced, does not mutate graph objects, uses the terminal
anchors and bounds long port labels. It also exercises the bundled ELK with
long module port names and verifies its routed endpoints. Browser boot tests
load the production HTML, JavaScript, Canvas renderer and bundled ELK; the
AST HTTP responses in those browser tests are fixtures rather than a real
Slang compile. Real compiler-backed cross-probing and full-flow validation
remain separate acceptance tasks.


### Workbench panels (increment 007)

The left navigator is an elaborated, paginated Slang instance tree. Its filter
searches **only already loaded instances** (including module type and instance
path); it never requests an unbounded hierarchy traversal. Use `Ctrl+K` (or
`Cmd+K`) to focus that filter, Arrow Up/Down to move among visible instances,
Arrow Right/Left to expand/collapse, and Enter to navigate. Additional pages
must be loaded before their instances can appear in filtered results.

The right inspector is read-only and shares cross-probing state with the
schematic. Its Details, SystemVerilog, Lint and From→To tabs support Left/Right,
Home and End keyboard navigation. Both side panels allow bounded resizing,
with widths persisted locally where browser storage is available. The existing
`Vim keys` control enables a **limited** line-navigation helper, not Vim or
Neovim with user mappings; full embedded Neovim remains future integration work.
No schematic placement, connectivity or source-location inference is performed
by the panels.

## Optional native Neovim inspector — patch 008

The SystemVerilog tab now offers a **Neovim** button. This is not an emulated
Vim mode: when enabled it runs a local `nvim --embed` subprocess and renders
Neovim's native `ext_linegrid` screen over MessagePack-RPC, including the
command line, status line and syntax colors supplied by Neovim. The user's
normal Neovim configuration and keymaps are loaded (no `--clean` or `-u NONE`).
A separate read-only source preview with limited "Vim keys" remains available.

Neovim is **opt-in** and does not start by itself. In WSL, install Neovim and
the optional MessagePack dependency (`python3 -m pip install msgpack`, or
`python3 -m pip install -e '.[neovim]'` when appropriate for your environment),
then launch:

```bash
# Standalone viewer: add --enable-neovim to the normal invocation.
python scripts/rtl_viewer.py --root examples/rtl_schematic_dsp --top DSP \
  --file DSP.sv --file DSP_core.sv --file DSP_lane.sv --enable-neovim

# The configured FlexSoC CLI uses an explicit environment opt-in.
FLEXSOC_RTL_NEOVIM=1 fx rtl-view
```

Only localhost `127.0.0.1` binding is supported for Neovim. The editor routes
only known hierarchy scopes to `RtlDesign.source()`. The source is copied into
an in-memory `nofile`, `readonly`, `nomodifiable` buffer: **there is no direct
write-back path to project RTL**. Native mappings and commands are available,
so custom Neovim config and shell commands execute under the viewer user's
privileges: enable only for trusted local use. Remote `--allow-remote` never
exposes editor execution. POST requests require a local Host/Origin and session
token; state queries also require the opaque token. No cloud service or
JavaScript package manager is involved.

Source-to-schematic selection uses `/api/source_symbols`, which maps a cursor
line only to explicitly located Slang signal declarations in the **current
source file and visible graph slice**. Multiple candidates are returned as
ambiguous; non-declaration lines, macro expansions and unknown provenance do
not get guessed at. Schematic and lint navigation can move the native cursor to
compiler-provided source lines. The browser fallback remains usable when
Neovim is not installed or cannot be started.

**Verification limits:** Python tests cover the MessagePack UI grid
transformation and HTTP permission boundaries; Chromium tests cover browser
interaction against a simulated Neovim RPC endpoint. A real Neovim binary is
required to verify the complete local end-to-end integration on WSL; these
mocked tests do not prove arbitrary personal plugin configurations work.


### Sequential Q/D conductors and conservative D-input projection (FSRTL-009)

A SystemVerilog declaration used on both sides of a nonblocking assignment
represents one *state variable*, but two **different register terminals**.
For example, `q <= q + 1` is projected as `Q(q) → ADD(A)` and
`ADD(Y) → D(q)` with **distinct canonical net IDs**. The expression-output
net is identified by the compiler-backed operator ID (`::expr:op:<n>`),
not by the destination declaration. The original `::sig:q` identity is kept
separately as `edge.signal` for source navigation and inspection. Canvas
may merge conductor strokes only when these canonical net IDs match. ELK
routes both edges independently to the Q and D glyph anchors.

AST guard/control and dynamic-address dependencies are still returned in
`diagram.edges` and remain available for semantic inspection and cone
exploration, but have `rendered: false` where they are **not electrical
wires**; the ELK/Canvas layer must not draw them as extra D drivers. Clock
events retain their dedicated CLK/RST/EVENT terminals. Where the AST
projection yields multiple distinct data-expression drivers for one D input
(e.g. separate branches whose D-input MUX has not been lowered), the
projection marks those arcs with `routingStatus: unresolved_D_mux` and the
register with `dInputStatus`. The glyph shows `D ?` instead of falsely
drawing multiple simultaneous electrical drivers. This is a conservative
limitation, not a claim that the elaborated RTL is multiply driven. A future
compiler-backed conditional lowering can replace the unresolved D-MUX with
a proven multiplexer without changing signal identities or the layout API.

This separation applies to all AST-recognized `always_ff` registers, not
only counters; it does not infer reset / enable semantics from signal names.
Tests use AST fixture contracts and real bundled ELK, not a real Slang
compilation of every conditional statement.


### Compound AST operands and physical pin exclusivity (FSRTL-010)

A named operand of an AST operator may itself be a nontrivial expression.
For example, in `q <= (a + b) ^ c`, the outer XOR's `A` input depends on
both `a` and `b`, **but neither declaration is an authoritative physical
conductor to the XOR's A terminal**: the intermediate addition has not been
lowered into its own schematic node. Similarly, an indexed selection cannot
turn its index dependency into a second wire at the data input.

The viewer retains all Slang-derived dependencies and stable source identities
while marking unsupported expression inputs with
`routingStatus: unresolved_operand_expression` and `rendered: false`.
A generic pin collision guard also rejects multiple distinct canonical nets
on a single glyph terminal (`unresolved_operand_multiple_nets`). The operator
node reports the affected pins through `operandStatus`, and Canvas shows `?`
at each unresolved terminal. Other, independently proven inputs and the
operator output remain routed by ELK.

A simple named input (including a pass-through parenthesized wrapper)
still renders normally; a complex expression is **not silently
simplified** to a single declaration, nor are its AST facts dropped. This
policy applies to assignments in combinational and sequential processes.
This was the conservative FSRTL-010 behavior; FSRTL-011 now lowers supported
nested AST operators while preserving the same fail-closed policy for
unsupported inputs. Test coverage does not establish bit-exact hardware
equivalence.

### Nested AST expression outputs and bounded lowering (FSRTL-011)

The expression graph now recursively projects supported Slang `BinaryOp`,
`UnaryOp`, `ConditionalOp` / `ConditionalExpression`, `Conversion`, and
`Concatenation` nodes. Each *supported* nested operator gets a distinct
`::op:<n>` glyph and `::expr:op:<n>` output conductor. Thus
`q <= (a + b) ^ c` is represented as `a,b → ADD(Y) → XOR(A)`,
`c → XOR(B)`, and `XOR(Y) → D(q)`. The state declaration `q` still owns
Q, not the D-input expression net. This is a projection of compiler AST
expression dependencies, **not** synthesis or bit-level netlist equivalence.

Pin roles are shared between recursive lowering and the conservative operand
resolver. The `ConditionalOp` select pin remains `S` with `A` false / `B`
true; a conversion is a visible `CAST` operation rather than assuming its
input and output share an electrically equivalent vector. Parenthesized
expressions are transparent, but width-changing conversions are not. Literal
operands stay annotations, not invented signal nodes.

Unsupported selectors, concatenation bit mapping and unknown AST expression
forms retain the original dependency edges with `rendered: false` and a
visible `?`, rather than falsely joining separate conductors. Recursion is
bounded to 16 levels and 256 displayed operator nodes per scope; beyond the
bound, dependencies fail closed without drawing unverified wires. Existing
conditional multiwriter D-input suppression still applies after nested
expansion when the complete procedural MUX is not compiler-backed
(see FSRTL-012). Layout remains exclusively ELK; the renderer never resolves AST
semantics or merges distinct expression nets.

Regression tests cover synthetic Slang-shaped nested trees, conversion,
conditional select routing, Q/D isolation, unsupported slices, depth bounds,
and real bundled ELK anchor alignment. Slang itself was unavailable in the
patch-generation environment, so these tests **do not** prove bit-accurate
elaboration of arbitrary real RTL or synthesis-equivalent operator lowering.

### Procedural `always_ff` D-input choices (FSRTL-012)

A single-event `always_ff` with a **complete, one-level** `if/else` writing
one whole register can now be projected as a compiler-AST-derived D MUX. The
false branch connects to `A`, the true branch to `B`, and the scalar,
compiler-typed predicate to `S`; MUX `Y` is the sole routed driver of D.
The Q declaration retains its own net identity. An omitted branch explicitly
feeds Q back to the appropriate MUX input (hold behavior), not to D directly.
Nested supported expression operators in either branch retain independent
intermediate expression nets. Literal branches label the input without
inventing a signal. All guard/evidence relationships remain available.

**Conservative eligibility rules:** the register has no other assignment
sites in the elaborated scope, each populated branch is exactly one direct
whole-declaration assignment to the same destination, and the condition is a
single AST reference with explicit scalar type (`bit`, `logic`, or `reg`).
Only a single-edge `always_ff` timing control is eligible. Vector truth
conversions, complex conditions, `case`, partial lvalues,
unsupported expression operands, other write sites, and multi-event
(asynchronous-reset-style) processes were not eligible under FSRTL-012;
FSRTL-016 now supports a strictly validated subset described below.
Other multi-event processes retain their AST facts, but guarded edges into D have
`rendered: false` and `routingStatus: unresolved_D_mux`; the register shows
`dInputStatus` / `D ?`. A syntactically guarded *single* write also fails
closed if its conditional MUX cannot be proven.

This is an RTL-level expression / dataflow visualization, not gate-level
synthesis, a proof of SystemVerilog four-state `if` equivalence, or a claim
that reset/enable hardware has been classified. Regression tests exercise
synthetic Slang-shaped ASTs, negative cases, Q/D independence, and real
bundled ELK placement / terminal alignment. End-to-end elaboration with a
real Slang executable remains a separate acceptance step.


### Bounded priority MUX trees (FSRTL-013)

The same AST-backed D-input projection now supports **bounded** `if / else if /
else` and nested procedural `if` trees. One-statement `Block` wrappers are
transparent. The adapter preflights the *entire* decision tree (selectors,
whole-register write destinations, expressions, global write-site count,
recursion depth and symbol budget) **before** creating any visual operator.
If one branch is unsupported, no part of that decision tree is presented as a
completed electrical D circuit.

Each conditional is an independent MUX (`A` = false, `B` = true, `S` =
compiler-typed 1-bit selector). Lower-priority `else if` decisions feed `A`
of their enclosing MUX, and nested decisions in a true branch feed `B`.
An unassigned path holds the register's current Q; nested Q feedback retains
its **own** net identity. Only the outermost result feeds D, so alternative
writes cannot masquerade as simultaneous electrical drivers. Control
conditions remain inspectable AST dependencies, not extra physical wires.

Boundaries are intentional: at most 16 conditional MUXes, 12 AST recursion
levels and 256 total expression operators per graph projection. The model
rejects multiple-statement branches, partial assignments, multiple register
destinations, missing/unknown predicate types, unresolved operands, additional
writers in the same scope and multi-event timing controls. Rejected paths
retain evidence and show unresolved D status rather than an invented circuit.
No RTL source parsing or synthesis-equivalent gate inference has been added.

Regression coverage: `tests/rtl_viewer/test_priority_ff_mux_013.py` uses
synthetic Slang-shaped ASTs, tests both branch priorities and negative cases,
and checks terminal endpoints using the bundled real ELK. Real Slang RTL
elaboration and complete synthesis equivalence are **not** yet validated.

### Ordered nonblocking statement sequences (FSRTL-014)

For a **single-event `always_ff`**, a compiler-provided `Block` / `List` /
`StatementList` can now be projected as an ordered next-state expression when
**every assignment in a multiple-statement sequence explicitly carries
`isNonBlocking: true`** (or `kind: NonblockingAssignment`). The last executed
nonblocking assignment to the one whole-register destination takes priority.
Right-hand-side references still read Q / the pre-edge state; assigning Q in
an earlier NBA does **not** change what a later RHS reads. A conditional
without a write inherits the *previously scheduled value*, rather than
unconditionally inserting a Q hold. This permits, for example:

```systemverilog
always_ff @(posedge clk) begin
    q <= a;
    if (sel) q <= b;
end
```

The resulting D value is a single MUX (`S=sel`, `A=a`, `B=b`), not two
independent D drivers. An unconditional later NBA overrides an earlier
conditional NBA, without retaining a fictitious MUX. Each recognized
conditional is still limited by the existing AST preflight and bounded
symbol/depth budgets.

The projection **fails closed** for sequences with blocking `=`, unspecified
scheduling metadata, mixed or partial writes, other writer sites, non-single
clock events, unmodeled statement kinds, or unsupported RHS forms. A final
literal assignment without a modeled constant source also remains unresolved.
No attempt is made to simulate blocking-variable updates or to infer them
from source text. In unsupported cases, neither intermediate conditionals nor
other sequence assignments become authoritative physical D connections.
Single-statement legacy AST fixtures retain the previously supported
behavior; this does not certify that missing scheduling metadata is safe for
multi-statement programs.

`tests/rtl_viewer/test_ordered_nba_ff_014.py` covers ordering, conditional
priority, Q feedback, negative cases and real ELK terminal alignment using
synthetic compiler-shaped ASTs. A real Slang end-to-end run is still required.

### Proven asynchronous reset with independent enable/D cones (FSRTL-016)

For a two-event `always_ff` with **exactly one matching edge-triggered reset
signal**, the renderer now separates asynchronous reset from the synchronous
D-input value. Eligibility requires a compiler-identified reset predicate
whose polarity matches the corresponding `SignalEvent` (`!rst_n` with
`NegEdge`, or a direct active-high guard with `PosEdge`), a true reset branch
containing **whole-register, explicit nonblocking constant assignments**, and
a false branch expressible using the existing bounded priority-D-MUX lowering.
Only canonical AST symbol identities authorize this mapping; nothing is
inferred from `clk`, `rst` or `en` spelling. `ExpressionStatement` wrappers
are supported for the eligible assignments.

The normal branch may write **multiple independent registers** in one block.
Each register gets an independent D expression and enable/hold MUX; its reset
value is associated with the existing RST event pin and is *not* a second
combinational D driver. Source Q, combinational output and D remain distinct.
An all-or-nothing preflight prevents a partially valid multi-register block
from creating an incomplete electrical D circuit.

The viewer still fails closed on unknown reset polarity, unsupported predicates,
partial writes, multiple procedural drivers, unknown write scheduling, complex
reset expressions, unrelated write statements, and unmodeled event lists.
No claim of synthesis equivalence or every SystemVerilog asynchronous reset
style is made. Validation currently uses Slang-shaped AST fixtures and real
vendored ELK routing; the live `DSP_lane.sv` Slang elaboration is a required
WSL acceptance test.

`tests/rtl_viewer/test_async_reset_enable_016.py` checks two independent
registers, direct routing of `product_d`/`accum_d` through enable MUXes,
Q feedback, reset/clock separation, AST statement wrappers, negative cases,
multiple-driver safety and actual ELK terminal anchors.

### Compiled Slang statement containers and generate navigation (FSRTL-017)

A diagnostic capture from an actual WSL Slang elaboration of
`examples/rtl_schematic_dsp/` established that statement wrappers can be
serialized as `Block.body -> Conditional`, `Block.body -> List.list`, and
`ExpressionStatement.expr -> Assignment`. The guarded next-state projection
now normalizes **only** these statement-container shapes before examining
write scheduling, reset polarity and symbol identities. Multi-statement lists
remain ordered and atomic; an unsupported member causes the D path to remain
unresolved instead of drawing a partially validated driver. The fixture
`tests/rtl_viewer/fixtures/dsp_slang_statements_017.json` preserves reduced
real Slang AST data for `DSP_core` and `DSP_lane` (not source-text parsing).
Its tests check `valid_q`, `product_q` and `accum_q` plus negative cases, and
verify ELK pin alignment. The complete uploaded elaboration was also checked
across all eight generated lanes. The fixture is a recorded compiler output,
not a claim that every pytest invocation runs Slang.

Hierarchy pagination accepts **elaborated instance scope paths** only. Generate
labels embedded within an instance path (e.g. `/u_core/g_mac`) are not
separately addressable scopes. The hierarchy UI now expands and fetches only
paths received from compiled hierarchy results, including when navigating
directly to an instance inside a generate array; the backend continues to
return HTTP 400 for genuinely invalid scope paths. Browser regression tests
verify no synthetic intermediate scope requests are issued.

### Ethernet AST field projections and port occurrences (FSRTL-021)

The Slang JSON for `axi_lite_to_reg.sv` (for example,
`axi_lite_req_i.aw_valid & axi_lite_req_i.w_valid & ~write_fifo_full`)
serializes `aw_valid` and `w_valid` as **`MemberAccess` expressions** whose
`value` contains a parent-scope declaration reference. They are not two
independent declared nets named `aw_valid` and `w_valid`.

RTL View projects an AST-identified member selection as a small `FIELD`
operator: `axi_lite_req_i → FIELD .aw_valid → AND.A`. A second, distinct
`FIELD .w_valid` value feeds the other pin. The incoming whole-struct edge is
**partial**; the viewer does not claim an exact field bit offset or a
synthesis-equivalent physical bus splice. An absent or malformed AST field
identity remains unresolved, without inventing wiring. As before, Slang is
responsible for semantic identities, ELK for geometry and Canvas for drawing.

The source-occurrence index also inspects **elaborated instance connection
expressions** outside child module bodies. An AST reference connected to a
formal `input` counts as a parent-side read; one connected to a formal
`output` counts as a parent-side write. `inout` without separate directional
evidence is not given a guessed role. These sites retain actual AST file/line
provenance, and are deduplicated with existing occurrence sites.

The compact regression fixture
`tests/rtl_viewer/fixtures/ethernet_slang_members_021.json` contains a slice
of a real Ethernet Slang elaboration (member selectors at line 107 and a FIFO
`pop_i` connection at line 128). It is not a handwritten RTL parser and does
not establish equivalence to a gate-level synthesized netlist.

### FSRTL-022 — Compact inline transforms and centered unary ports

`FIELD` selections and AST-backed `CAST` conversions now use low-profile,
left-to-right inline glyphs. A field selection displays its compiler-provided
member name (without a redundant `FIELD` header); a cast displays one short
`CAST` label. Their dimensions are bounded, including for long field names.
The inspector remains the source of full expression/type details.

`symbol-geometry.js` defines a single WEST-midpoint terminal for operators
with one AST-derived input role, including unary operators, `FIELD`, `CAST`,
and generic single-operand cases. The renderer uses the same anchor to draw
its visible input stub; the ELK adapter uses it as a fixed port location.
Binary A/B and MUX A/B/S anchor positions are unchanged. This is a geometric
change only: field bit offsets and other unproven connections remain partial
or unresolved, and Canvas does not infer new RTL semantics.

`tests/rtl_viewer/test_compact_unary_symbols_022.py` checks the actual Canvas
commands, node size policy, exact source/target ELK route endpoints on the
existing real-Ethernet-Slang-derived fixture, and non-regression of the
binary and MUX terminal roles.

### FSRTL-024 — Bidirectional source/schematic navigation and visibility audit

The RTL Inspector now has direct **Open SystemVerilog**, **Reveal schematic**,
**References**, and **Lint** actions. A source-line click (or a cursor move in
local embedded Neovim) queries `/api/source_symbols` for the **currently
selected elaborated scope**, using compiler-provided source locations and
resolved AST declaration identities. The query includes supported declaration,
read and write sites; it never matches text identifiers by spelling. A line
with multiple AST identities presents a candidate chooser rather than
arbitrarily selecting an instance or a net. A candidate must be present in
the current diagram slice before it can be revealed.

The **Source map** tab uses `/api/source_coverage` to compare scope-local AST
signal declarations with the diagram slice. It distinguishes (1) visible
signals with compiler-mapped locations, (2) visible signals without verified
locations, and (3) declarations not represented in the current diagram slice.
This is a *visibility and provenance audit*, **not** a correctness verdict:
the absence of a displayed symbol does not prove a signal is absent in
SystemVerilog; likewise a missing source location does not prove there is no
RTL declaration. Reports include graph truncation state. Source links are
shown only for locations in the module source opened by the viewer.

Lint **Find in schematic** flows through the same source-line lookup only if
the diagnostic file matches the module source; missing or ambiguous mappings
remain explicit. The source viewer remains read-only. Native Neovim continues
to be opt-in and invokes the same compiler-based probe, including ambiguity
handling. User-visible paths never change the authored RTL or Slang AST.

Regression tests in `test_bidirectional_navigation_024.py` exercise
source-line writes and reads, ambiguous multi-signal lines, non-matches,
truncated diagram visibility, the API, and browser navigation. Ethernet's
real imported Slang AST was also inspected at lines 72, 107, 128 and 135 of
`axi_lite_to_reg.sv` for scope-local read/write provenance; this inspection
is not a new Slang compilation.

### FSRTL-028 — Independent reset-expression qualification

A multi-register asynchronous-reset `always_ff` must not lose every D
connection just because one sibling uses an unsupported reset value. Slang
can represent `q_a <= 1'b0` and `q_b <= {1'b0, 8'd12}` in the same reset
branch: the concatenation is not an ordinary literal for the conservative
reset adapter, but it does **not** invalidate `q_a`'s direct clock-side D
assignment. All reset statements must still be whole-target, explicit
nonblocking writes with distinct AST declaration identities. Each destination
qualifies its reset RHS independently; unqualified destinations remain
registers with a visible `D ?`, while qualified siblings may be routed.

Regression coverage includes the real Slang statement tree from Ethernet's
`ethernet_core.sv` (`tx_ack_meta_csr <= tx_ack_mac`,
`tx_ack_sync_csr <= tx_ack_meta_csr`), an unsupported sibling reset,
multiple-process writers and actual ELK-to-Canvas D pin alignment. This
corrects the over-broad rejection of an entire reset branch without claiming
that arbitrary aggregate reset values have been synthesized.

### FSRTL-025 — Per-register next-state lowering and source-first navigation

An `always_ff` process may update multiple registers, and not all of their
next-state expressions need be representable with the same precision. An
unsupported construct in the assignment to one register must not discard an
independently proven D-input function of another register. The async-reset
lowerer now validates and commits **each destination independently**, while
still validating all writes of that destination, clock/reset polarity, and
cross-process multiple writers. Missing or unsupported drivers continue to
show `D ?`; an unproven function is never connected directly to D.

This was tested against the **actual Slang AST statement structure** from
Ethernet's `ethernet_core.sv`: the two `rx_*_event_bin <= rx_*_event_bin +
32'd1` counters now have Q feedback through ADD and an AST-justified MUX feeding
D, while sibling Gray-code function calls remain unresolved. Literal operands
such as `32'd1` are rendered next to their input terminals, not inside the
operator chassis. These graphs model compiler-backed next-state relationships,
not gate-level synthesis equivalence.

The Source inspector's AST declaration/write/read navigation is now above the
scrollable source editor. The compact role buttons stay visible while scrolling
and a `Legend` disclosure explains the roles and keyboard shortcuts. The
`🔓 Follow` / `🔒 Locked` action determines whether a unique source-line AST
match recenters the schematic automatically. Even while locked, an explicit
**Reveal schematic** request may navigate to the selected entity.

Embedded Neovim remains optional and read-only. Its grid is a native viewport,
so touchpad/mouse wheel scrolling is sent through the authenticated localhost
MessagePack bridge as bounded `nvim_input_mouse` events; native Vim motions
and shortcuts still go through `nvim_input`. This feature was validated with a
mock Neovim process and browser smoke tests, **not** with a real Neovim binary
in the authoring environment. In WSL, test long-file scrolling and `gg`, `G`,
`Ctrl-f`, `Ctrl-b` with your own mappings.

### FSRTL-026 — Ordered concatenation inputs and replication display

Slang `Concatenation.operands` is an **ordered** AST list, not one generic `IN`
conductor. For validated lists of 1–32 expression operands, the semantic
projection now creates distinct `I0`, `I1`, … input terminals in compiler
operand order. Nested `MemberAccess`, conversions and supported expressions
are lowered recursively as separate value nodes; a literal receives an input
annotation rather than an invented wire. Unknown operands keep their own
visible `?` terminal. Out-of-contract or oversized concatenations fail closed
instead of silently dropping operands or joining distinct dependencies.

`Replication.concat` has a single expression input, and its AST-evaluated
repetition count is shown only when directly available as an unambiguous
integer. No individual replicated bit conductors or bit offsets are inferred.
The Canvas glyph's input rows, literal labels and ELK fixed ports are derived
from the same indexed pin roles; symbol height grows with the bounded number
of operands, rather than putting several unrelated wires on one input.

The real Ethernet Slang AST was checked in `ethernet_core` at line 108:
`{reg2hw.ctrl.tx_enable.q, reg2hw.ifg.q}` produces two separate compiler-
backed `MemberAccess` chains connected to the `I0` and `I1` inputs of CONCAT.
Across its 67 elaborated scopes, the imported AST yielded 94 CONCAT and 6
replication nodes without diagram-construction errors. This verifies the
projection of *existing* Slang output, not re-elaboration or synthesized netlist
equivalence. See `tests/rtl_viewer/test_concat_operands_026.py` for synthetic
Slang-shaped positive/negative cases and real bundled-ELK endpoint assertions.

### FSRTL-027 — Compiler-backed function-call value boundaries

Slang serializes a user-defined function invocation as `Call` with a
`subroutine` **address**, a typed `arguments` list and a return type. The
referenced `Subroutine` carries its address, parameter declarations, source
location and body. RTL View now indexes subroutines from the imported AST
once, verifies the address, function kind, return type, parameter count and
input directions, and renders validated calls as **opaque FUNCTION blocks**.
The input pins `I0`, `I1`, … correspond to the positional `Call.arguments` in
compiler order; the `Y` value is a distinct expression net. This is a
call/value boundary, **not** gate-level synthesis of the function body.
Function definition identity, line, argument names and return type are retained
as inspection metadata. Calls without a verified definition, tasks, void
returns, mismatched arguments and output/inout/ref parameters are not
projected into fabricated conductors.

On the actual Ethernet Slang AST, `gray_of_increment(rx_bad_event_bin)` and
`gray_of_increment(rx_fcs_event_bin)` reference the `gray_of_increment`
function definition at `ethernet_core.sv:249`; their independent function-output
values feed the appropriate conditional D MUX, while the register's Q remains
separate. Tests use a reduced snapshot of the real function and always_ff
nodes and check the ELK terminal geometry. The imported Ethernet AST was also
projected across all 67 scopes (6 function-call value nodes) without failure.
No live Slang compile or gate-level equivalence is implied.

## Compound sequential predicates and D coverage — patch 029

The AST-only sequential projector accepts compiler-proven **constant reset
expressions** (including bounded packed concatenations of literal fields,
constant conversions, and constant arithmetic) without treating their bits
as extra D wires. A register's reset value qualifies independently of the
reset values of its siblings in the same `always_ff`.

For conditional clock-side updates, scalar predicates may be complete
compiler-AST expression trees (e.g. compare → NOT → logical AND). These
predicates have their **own expression nodes** feeding the MUX selector S;
no two distinct source nets are shorted onto S. The output of the MUX,
not the condition, feeds D. Dynamic indexing, missing declaration identities,
unsupported calls and untyped/vector predicates still result in explicitly
unresolved D rather than a synthesized-looking graph. Full procedural
SystemVerilog, partial writes and inferred temporary storage are not yet
claimed as completely supported.

Run `scripts/rtl_viewer.py --run-dir <run> --check --report <output.json>`
against an existing AST to inspect the audit's `totals.d_inputs` and each
`scopes[].d_inputs`. These report total / routed / unresolved FF D inputs,
plus bounded lists of unresolved symbols. They report **viewer graph
coverage**, not equivalence, timing, or physical connectivity. An unrouteable
D is a clearly identified technical gap, never a reason to add speculative
wires.

### FSRTL-030 — Compact display of Slang-proven constant expressions

A source expression with an explicit, compiler-evaluated `constant` field can
be represented as a **single constant value source** rather than a succession
of CAST, REP and CONCAT glyphs. The projection retains the original AST kind,
source line, original result type and the evaluated literal in the node's
`constantOrigin`, `line`, `constantType` and `constantValue` fields. No
runtime input is created for a compiler-proven constant. The output is still a
separate expression value connected to the original destination.

For example, the Ethernet AST at `ethernet_core.sv:198–199` reports
`PHY_MII_MODE` as `1'b0` and both `{2{PHY_MII_MODE}}` results (after conversion)
as `2'b0`. RTL View therefore shows one compact `2'b0` source for each
of `tx_mii_sync` and `rx_mii_sync`, rather than an apparently unwired
CONCAT → REP → CAST chain. The full source expression remains accessible in
SystemVerilog navigation; folding is a **presentation-level use of Slang's
elaboration result**, not a textual pattern substitution.

If the AST does not provide a bounded, explicit constant value, the normal
operator/operand graph remains unchanged. A constant attached only to an
inner node never authorizes folding its parent; unsupported or dynamic
replications continue to expose their original input pins. This does not
claim synthesis equivalence or runtime evaluation of unknown expressions.
See `tests/rtl_viewer/test_constant_expression_030.py` for tests using the
captured Ethernet AST, dynamic negative cases, and a real ELK/Canvas pin check.

### FSRTL-031 — Static packed-select values in sequential D cones

The Slang-elaborated `RangeSelect` and `ElementSelect` nodes with literal,
compiler-authored indices are now explicit **SLICE** value projections. This
unblocks AST-valid next-state paths such as
`tx_rst_reg <= {1'b0, tx_rst_reg[3:1]}` while maintaining separate Q, slice,
concatenation, and D identities. The glyph shows `[3:1]` (or `[index]`) with a
single left input, and Canvas/ELK share its centered terminal geometry. The
input edge is marked `partial`: this viewer does not prove bus-bit wiring or
netlist equivalence.

Nonliteral or out-of-range indices, unfamiliar indexed range kinds, and other
unsupported selectors **remain unresolved**; no source-text parsing or
signal-name heuristics are used. Characterization tests use a reduced *real*
Ethernet PHY Slang AST with independent TX and RX `always_ff` processes. Full
SystemVerilog coverage, dynamic selects, variable part-selects, unpacked array
semantics and synthesis equivalence are not claimed.

### Next-state projection by elaborated destination (increment 032)

RTL View does **not** treat each procedural assignment as a physical driver.
For a single-clock `always_ff`, the source of the D input is the final
scheduled value for that specific destination, preserving SystemVerilog
statement order, conditional priority, the old Q on hold paths and the
separate `CLK` event. A register's left-hand side is **not** automatically
connected to its right-hand side: the latter may require expression operators
and priority MUXes before reaching D.

For Slang processes updating multiple registers, the destination-local
projection first selects a complete AST statement subtree. A nonblocking
whole-register write to **another** destination is independent and may be
omitted (the right-hand side reads pre-edge state). All enclosing conditions
and ordering remain. The existing bounded priority-MUX lowerer then checks
*every* retained write and predicate before emitting any electrical edge.
Each destination is committed separately; failed lowering leaves `D ?`.

This is **not** a general SystemVerilog interpreter or formal equivalence
proof. Unknown procedural constructs, nonlocal blocking writes, partial
lvalues, ambiguous writer ownership and unsupported dynamic operations
remain unqualified. They must be implemented with explicit AST contracts and
positive/negative regressions before D may be displayed as resolved.
Parameter references used as predicate operands are accepted as *constant
values* only when their compiler address uniquely identifies an elaborated
parameter with a structurally constant initializer. This does not create an
electrical wire from a parameter declaration.

The `tests/rtl_viewer/test_sequential_projection_032.py` regression uses a
minimized authentic Ethernet Slang AST for a multi-destination `always_ff`
(`ethernet_rx`), plus unsafe-statement cases and real ELK routing. The
corresponding full Ethernet report is included in the patch 032 package.
Coverage denotes **renderable AST-backed D projections**, not synthesis
correctness or complete SystemVerilog language coverage.
