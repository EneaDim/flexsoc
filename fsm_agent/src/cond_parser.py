from __future__ import annotations
from dataclasses import dataclass
from typing import List, Tuple, Optional
import re

# Token types
TOK_IDENT = "IDENT"
TOK_CONST = "CONST"
TOK_NOT = "!"
TOK_AND = "&"
TOK_OR = "|"
TOK_LP = "("
TOK_RP = ")"
TOK_EOF = "EOF"

IDENT_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
CONST_RE = re.compile(r"^1'b[01]$")

@dataclass(frozen=True)
class Token:
    kind: str
    value: str
    pos: int

# AST nodes (minimal)
@dataclass(frozen=True)
class Node:
    pass

@dataclass(frozen=True)
class Ident(Node):
    name: str

@dataclass(frozen=True)
class Const(Node):
    value: str  # "1'b0" or "1'b1"

@dataclass(frozen=True)
class Not(Node):
    x: Node

@dataclass(frozen=True)
class And(Node):
    xs: Tuple[Node, ...]

@dataclass(frozen=True)
class Or(Node):
    xs: Tuple[Node, ...]

class CondParseError(ValueError):
    pass

def tokenize(expr: str) -> List[Token]:
    s = expr.strip()
    tokens: List[Token] = []
    i = 0
    while i < len(s):
        ch = s[i]
        if ch.isspace():
            i += 1
            continue
        if ch in ("!", "&", "|", "(", ")"):
            tokens.append(Token(kind=ch, value=ch, pos=i))
            i += 1
            continue

        # identifier or const
        j = i
        while j < len(s) and (s[j].isalnum() or s[j] == "_" or s[j] == "'"):
            j += 1
        word = s[i:j]
        if CONST_RE.match(word):
            tokens.append(Token(kind=TOK_CONST, value=word, pos=i))
        elif IDENT_RE.match(word):
            tokens.append(Token(kind=TOK_IDENT, value=word, pos=i))
        else:
            raise CondParseError(f"Token non valido '{word}' @pos {i} in: {expr!r}")
        i = j

    tokens.append(Token(kind=TOK_EOF, value="", pos=len(s)))
    return tokens

class Parser:
    def __init__(self, tokens: List[Token], original: str):
        self.toks = tokens
        self.i = 0
        self.original = original

    def peek(self) -> Token:
        return self.toks[self.i]

    def pop(self, kind: Optional[str] = None) -> Token:
        t = self.peek()
        if kind is not None and t.kind != kind:
            raise CondParseError(
                f"Atteso token {kind} ma trovato {t.kind} ('{t.value}') @pos {t.pos} in: {self.original!r}"
            )
        self.i += 1
        return t

    # Grammar:
    # expr      := or_expr
    # or_expr   := and_expr ( '|' and_expr )*
    # and_expr  := unary_expr ( '&' unary_expr )*
    # unary     := '!' unary | primary
    # primary   := IDENT | CONST | '(' expr ')'

    def parse_expr(self) -> Node:
        return self.parse_or()

    def parse_or(self) -> Node:
        left = self.parse_and()
        xs = [left]
        while self.peek().kind == TOK_OR:
            self.pop(TOK_OR)
            xs.append(self.parse_and())
        if len(xs) == 1:
            return xs[0]
        return Or(tuple(xs))

    def parse_and(self) -> Node:
        left = self.parse_unary()
        xs = [left]
        while self.peek().kind == TOK_AND:
            self.pop(TOK_AND)
            xs.append(self.parse_unary())
        if len(xs) == 1:
            return xs[0]
        return And(tuple(xs))

    def parse_unary(self) -> Node:
        if self.peek().kind == TOK_NOT:
            self.pop(TOK_NOT)
            return Not(self.parse_unary())
        return self.parse_primary()

    def parse_primary(self) -> Node:
        t = self.peek()
        if t.kind == TOK_IDENT:
            self.pop(TOK_IDENT)
            return Ident(t.value)
        if t.kind == TOK_CONST:
            self.pop(TOK_CONST)
            return Const(t.value)
        if t.kind == TOK_LP:
            self.pop(TOK_LP)
            n = self.parse_expr()
            self.pop(TOK_RP)
            return n
        raise CondParseError(
            f"Token inatteso {t.kind} ('{t.value}') @pos {t.pos} in: {self.original!r}"
        )

def parse_condition(expr: str) -> Node:
    toks = tokenize(expr)
    p = Parser(toks, expr)
    node = p.parse_expr()
    if p.peek().kind != TOK_EOF:
        t = p.peek()
        raise CondParseError(f"Token extra {t.kind} ('{t.value}') @pos {t.pos} in: {expr!r}")
    return node

def collect_idents(node: Node) -> List[str]:
    out: List[str] = []
    def rec(n: Node):
        if isinstance(n, Ident):
            out.append(n.name)
        elif isinstance(n, Const):
            return
        elif isinstance(n, Not):
            rec(n.x)
        elif isinstance(n, And):
            for k in n.xs:
                rec(k)
        elif isinstance(n, Or):
            for k in n.xs:
                rec(k)
        else:
            # future-proof
            return
    rec(node)
    return out
