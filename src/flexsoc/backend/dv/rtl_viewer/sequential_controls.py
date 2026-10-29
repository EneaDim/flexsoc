"""Conservative AST-only sequential guard extraction.

No signal naming heuristic, no synthesis claim.  A guard proves a condition is
on an assignment path, not that it is an enable or reset.
"""
from __future__ import annotations

ASSIGNMENTS = {"Assignment", "AssignmentExpression", "NonblockingAssignment"}
CONDITIONALS = {"Conditional", "ConditionalStatement", "IfStatement"}


# Only an AST literal expression is affirmative evidence of a constant RHS.
LITERALS = {"IntegerLiteral", "UnbasedUnsizedIntegerLiteral", "RealLiteral",
            "StringLiteral", "NullLiteral", "TimeLiteral"}
WRAPPERS = {"Conversion", "ImplicitConversion", "AssignmentConversion",
            "ParenthesizedExpression"}

def is_literal_rhs(expr):
    if not isinstance(expr, dict):
        return False
    kind = expr.get("kind")
    if kind in LITERALS:
        return True
    if kind in WRAPPERS:
        children = [expr[k] for k in ("operand", "expression", "value", "expr") if k in expr]
        return len(children) == 1 and is_literal_rhs(children[0])
    return False



def collect(body, symbols):
    """Return destination -> ordered guarded paths, using canonical AST symbols."""
    found = {}
    def descend(obj, guard=(), branch=()):
        if isinstance(obj, list):
            for child in obj:
                descend(child, guard, branch)
            return
        if not isinstance(obj, dict):
            return
        kind = str(obj.get('kind', ''))
        if kind in CONDITIONALS:
            cond = obj.get('conditions', obj.get('condition', obj.get('predicate')))
            signals = sorted(symbols.refs(cond))
            loc = obj.get('source_line', obj.get('source_line_start', 0))
            try:
                line = int(loc)
            except (ValueError, TypeError):
                line = 0
            condition = {'signals': signals, 'line': line, 'kind': kind}
            for keys, sense in ((('ifTrue','then'), 'true'), (('ifFalse','else'), 'false')):
                for key in keys:
                    if key in obj:
                        descend(obj[key], guard + (condition,), branch + (sense,))
            return
        if kind in ASSIGNMENTS or ('Assignment' in kind and 'Pattern' not in kind):
            lhs = obj.get('left', obj.get('lhs'))
            rhs = obj.get('right', obj.get('rhs'))
            if lhs is None or rhs is None:
                return
            src = sorted(symbols.refs(rhs))
            loc = obj.get('source_line', obj.get('source_line_start', 0))
            try:
                line = int(loc)
            except (ValueError, TypeError):
                line = 0
            item = {'line': line, 'guards': [{**g, 'branch': b} for g,b in zip(guard, branch)],
                    'rhsSignals': src, 'constantRhsCandidate': is_literal_rhs(rhs),
                    'certainty': 'ast_guard_path'}
            for target in sorted(symbols.writes(lhs)):
                if item not in found.setdefault(target, []):
                    found[target].append(item)
            return
        for v in obj.values():
            if isinstance(v, (list,dict)):
                descend(v,guard,branch)
    descend(body)
    return found
