# FlexSoC RTL Explorer — VS Code / Cursor (preview)

Open a folder containing SystemVerilog sources and install the extension in the **workspace extension host** (in WSL, use *Install in WSL*). The extension relies on FlexSoC's local Python viewer backend and `slang` in PATH; there is no regex RTL fallback.

1. Configure `flexsoc.rtlExplorer.repository` to your FlexSoC checkout (or open the checkout itself).
2. Optionally configure `flexsoc.rtlExplorer.filelists`, `includes`, and `defines` for a project with many files. Otherwise select the source files from Quick Pick.
3. Run **FlexSoC: Open RTL Schematic** from the Command Palette (or from a `.sv` / `.v` editor context menu).
4. Supply the elaboration top; view the hierarchical schematic, contextual RTL and lint panels.

The extension spawns `python3 scripts/rtl_viewer.py` with `--port 0`, then serves local graph queries through **extension-host ↔ webview message passing**. No public listener, no external CDN, and no remote RTL upload. Slang, Python and sources must be available in the *same* extension-host environment. Cursor supports VS Code extension APIs but must be verified on the specific Cursor release.

## Build/install from source

From the repository root:

```sh
python scripts/package_rtl_viewer_extension.py
cd extensions/flexsoc-rtl-explorer
npm test
npx --yes @vscode/vsce package --no-dependencies
```

The `media/` folder is populated by the packaging helper; do not edit it directly. Install the generated `.vsix` from the Extensions menu, including in Cursor where supported.

**Preview limits:** not yet a marketplace-certified extension; Slang's AST model does not guarantee bit-exact cones; no bundled Slang binary. The extension does not modify files or run a simulation.
