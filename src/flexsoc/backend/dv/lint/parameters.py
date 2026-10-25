"""Read already-elaborated Slang parameter evidence; never evaluate HDL in Python."""

from __future__ import annotations

import json
from pathlib import Path
from typing import Any, Iterator, Mapping

from rich.console import Console
from rich.table import Table


class ParameterView:
    """Project elaborated AST parameters onto module and instance hierarchies."""

    CHILDREN = ("members", "body", "instances", "symbols", "design", "compilation", "topInstances")

    @classmethod
    def collect(cls, root: Any) -> list[dict[str, Any]]:
        """Return parameter values as recorded by Slang, including localparams.

        Instance paths are inferred only from explicit nested Instance symbols.
        Unattached parameters remain in the package / compilation scope.
        """
        found: list[dict[str, Any]] = []
        seen: set[int] = set()

        def walk(node: Any, instance: str = "", module: str = "", scope: str = "") -> None:
            if isinstance(node, list):
                for part in node:
                    walk(part, instance, module, scope)
                return
            if not isinstance(node, dict):
                return
            ident = id(node)
            if ident in seen:
                return
            seen.add(ident)
            kind = str(node.get("kind") or "")
            name = str(node.get("name") or "")
            if kind == "Instance":
                instance = f"{instance}.{name}" if instance and name else (name or instance)
                module = str(node.get("moduleName") or node.get("definition") or node.get("type") or module)
                scope = "instance"
            elif kind in {"Package", "PackageSymbol"}:
                scope = "package"
                module = name
                instance = ""
            elif kind in {"Module", "ModuleDefinition"}:
                module = name or module
                if not instance:
                    scope = "definition"
            if kind == "Parameter":
                initializer = node.get("initializer")
                initial = initializer if isinstance(initializer, dict) else {}
                found.append({
                    "instance": instance,
                    "module": module,
                    "scope": scope or "compilation",
                    "kind": "localparam" if node.get("isLocal") else "parameter",
                    "name": name,
                    "type": str(node.get("type") or ""),
                    "value": node.get("value"),
                    "expression_kind": str(initial.get("kind") or ""),
                    "expression_constant": initial.get("constant"),
                    "file": str(node.get("source_file") or ""),
                    "line": node.get("source_line"),
                    "column": node.get("source_column"),
                })
                return  # Do not misclassify initializer expressions as child symbols.
            for key in cls.CHILDREN:
                if key in node:
                    walk(node[key], instance, module, scope)
            # Slang nests InstanceBody and other scopes under different keys.
            for key, value in node.items():
                if key not in cls.CHILDREN and key not in {"initializer", "source", "type", "value", "constant", "addr", "attributes"} and isinstance(value, (dict, list)):
                    walk(value, instance, module, scope)

        walk(root)
        return sorted(found, key=lambda item: (
            item["scope"] != "instance", item["instance"], item["module"],
            item["file"], int(item["line"] or 0), item["name"],
        ))

    @staticmethod
    def filter(rows: list[dict[str, Any]], selector: str | None) -> list[dict[str, Any]]:
        if not selector:
            return rows
        needle = selector.casefold()
        return [row for row in rows if needle in {
            str(row["module"]).casefold(), str(row["instance"]).casefold(),
            str(row["instance"]).rsplit(".", 1)[-1].casefold(),
        }]

    @classmethod
    def load(cls, ast: Path, selector: str | None = None) -> dict[str, Any]:
        if not ast.is_file():
            raise FileNotFoundError(f"Slang AST not found: {ast}; run `fx slang_hier` first")
        rows = cls.filter(cls.collect(json.loads(ast.read_text(encoding="utf-8"))), selector)
        return {"source": str(ast), "filter": selector, "total": len(rows), "parameters": rows}

    @staticmethod
    def render(data: Mapping[str, Any], console: Console) -> None:
        console.print(f"[bold]Elaborated RTL parameters[/bold] · {data['total']} · filter={data['filter'] or 'all'}")
        grouped: dict[str, list[Mapping[str, Any]]] = {}
        for row in data["parameters"]:
            group = str(row["instance"] or f"{row['scope']}:{row['module'] or '<unknown>'}")
            grouped.setdefault(group, []).append(row)
        for group, rows in grouped.items():
            console.print(f"\n[bold cyan]{group}[/bold cyan]")
            table = Table(box=None, show_edge=False, pad_edge=False, header_style="bold")
            for column in ("Kind", "Name", "Type", "Value", "Expr kind", "File", "Line", "Column"):
                table.add_column(column, overflow="fold")
            for row in rows:
                table.add_row(*(
                    str(row.get(field) if row.get(field) is not None else "-")
                    for field in ("kind", "name", "type", "value", "expression_kind", "file", "line", "column")
                ))
            console.print(table)
