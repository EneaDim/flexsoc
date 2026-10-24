#!/usr/bin/env python3
"""Copy the exact standalone viewer assets to the VS Code/Cursor extension media."""
from pathlib import Path
import shutil

root = Path(__file__).resolve().parents[1]
src = root / 'src/flexsoc/backend/dv/rtl_viewer/web'
dest = root / 'extensions/flexsoc-rtl-explorer/media'
dest.mkdir(parents=True, exist_ok=True)
for name in ('index.html', 'router.js', 'app.js', 'style.css'):
    shutil.copyfile(src / name, dest / name)
    print(f'{name} -> {dest.relative_to(root)}')
