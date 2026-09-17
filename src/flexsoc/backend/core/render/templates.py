"""Small renderer for FlexSoC-owned scaffold templates."""

from __future__ import annotations

from pathlib import Path

from jinja2 import Environment, PackageLoader, StrictUndefined


class Templates:
    """Render or write package-owned scaffold templates."""

    def __init__(self) -> None:
        self._env = Environment(
            loader=PackageLoader("flexsoc", "templates"),
            autoescape=False,
            keep_trailing_newline=True,
            undefined=StrictUndefined,
            variable_start_string="<<:",
            variable_end_string=":>>",
            block_start_string="<<%",
            block_end_string="%>>",
            comment_start_string="<<#",
            comment_end_string="#>>",
        )

    def render(self, name: str, **values: object) -> str:
        """Render one scaffold with explicit values."""

        return self._env.get_template(name).render(**values)

    def write(self, name: str, path: Path, *, force: bool = False, **values: object) -> Path:
        """Write one scaffold, preserving an existing user-owned file unless forced."""

        output = path.expanduser().resolve()
        if output.exists() and not force:
            return output
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(self.render(name, **values), encoding="utf-8")
        return output


templates = Templates()
