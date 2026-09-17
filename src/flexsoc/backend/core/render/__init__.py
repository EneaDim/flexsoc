"""Canonical report rendering and package-owned template access."""

from .show import ShowDocument, ShowRenderer, ShowSpec
from .templates import Templates, templates

__all__ = ["ShowDocument", "ShowRenderer", "ShowSpec", "Templates", "templates"]
