"""Minimal CORDIC vector-test viewer.

This viewer reads the standard FlexSoC files only:

* config.regs
* data_in.vec
* data_out.vec

No extra expected.json artifact is required.
"""

from __future__ import annotations

import argparse
import html
from pathlib import Path


def _count_vector_rows(path: Path) -> int:
    if not path.exists():
        return 0
    count = 0
    for line in path.read_text().splitlines():
        stripped = line.strip()
        if stripped and not stripped.startswith("#"):
            count += 1
    return count


def _read_preview(path: Path, *, limit: int = 8) -> str:
    if not path.exists():
        return "missing"
    rows = []
    for line in path.read_text().splitlines():
        stripped = line.strip()
        if stripped and not stripped.startswith("#"):
            rows.append(stripped)
        if len(rows) >= limit:
            break
    return "\n".join(rows) if rows else "empty"


def render_html(tests_dir: Path, output_html: Path) -> None:
    """Render one simple HTML summary of generated CORDIC vector tests."""

    tests = []
    for test_dir in sorted(path for path in tests_dir.iterdir() if path.is_dir()):
        data_in = test_dir / "data_in.vec"
        data_out = test_dir / "data_out.vec"
        tests.append(
            {
                "name": test_dir.name,
                "inputs": _count_vector_rows(data_in),
                "outputs": _count_vector_rows(data_out),
                "input_preview": _read_preview(data_in),
                "output_preview": _read_preview(data_out),
            }
        )

    rows = []
    for test in tests:
        status = "ok" if test["inputs"] == test["outputs"] and test["inputs"] else "check"
        rows.append(
            "<tr>"
            f"<td>{html.escape(test['name'])}</td>"
            f"<td>{test['inputs']}</td>"
            f"<td>{test['outputs']}</td>"
            f"<td>{status}</td>"
            "</tr>"
            "<tr>"
            "<td colspan='4'>"
            "<details>"
            "<summary>Preview</summary>"
            "<h4>data_in.vec</h4>"
            f"<pre>{html.escape(test['input_preview'])}</pre>"
            "<h4>data_out.vec</h4>"
            f"<pre>{html.escape(test['output_preview'])}</pre>"
            "</details>"
            "</td>"
            "</tr>"
        )

    output_html.parent.mkdir(parents=True, exist_ok=True)
    output_html.write_text(
        """<!doctype html>
<html>
<head>
  <meta charset="utf-8">
  <title>CORDIC vector tests</title>
  <style>
    body { font-family: system-ui, sans-serif; margin: 2rem; line-height: 1.4; }
    table { border-collapse: collapse; min-width: 48rem; }
    th, td { border: 1px solid #ddd; padding: 0.5rem 0.75rem; vertical-align: top; }
    th { background: #f4f4f4; text-align: left; }
    pre { background: #f7f7f7; padding: 0.75rem; overflow: auto; }
  </style>
</head>
<body>
  <h1>CORDIC vector tests</h1>
  <p>Summary generated from standard FlexSoC test files.</p>
  <table>
    <thead>
      <tr><th>Test</th><th>Input vectors</th><th>Expected vectors</th><th>Status</th></tr>
    </thead>
    <tbody>
"""
        + "\n".join(rows)
        + """
    </tbody>
  </table>
</body>
</html>
""",
    )


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("tests_dir", type=Path)
    parser.add_argument("--html", type=Path, required=True)
    args = parser.parse_args()

    render_html(args.tests_dir, args.html)
    print(f"wrote {args.html}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
