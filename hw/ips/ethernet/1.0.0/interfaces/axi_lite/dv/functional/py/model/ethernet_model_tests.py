"""Native FlexSoC 50 exact M4 Ethernet oracle tests, with recorded testplan IDs.

Every test_model_case[ID] invokes one original, SHA-pinned independent M4
assertion. No RTL / EDA evidence is inferred from these Python model cases.
"""
from __future__ import annotations
import hashlib
from pathlib import Path
import sys

import pytest

HERE = Path(__file__).resolve().parent
SOURCE_DIR = HERE
# Provenance: verify the exact original independently authored oracle body
# (prior to the added TOP metadata) and the relocated test semantics.
ORACLE_SHA256 = "dbd42d0dcc95fb7c2f4c6f9d8f56e675576b3226b860458e9bc868a79c2b3fac"
ORIGINAL_TEST_SHA256 = "809e01b7e66946b5ba6698f4a19a091d99a432fcb949f7ed694ec1b848fc289f"
model_file = SOURCE_DIR / "ethernet_model.py"
test_file = SOURCE_DIR / "test_ethernet_model.py"
if not model_file.is_file() or model_file.is_symlink() or not test_file.is_file() or test_file.is_symlink():
    raise RuntimeError("missing model or independent test")
if not model_file.read_bytes().startswith(b'"""Independent Ethernet'):
    raise RuntimeError("independent model content missing")
if hashlib.sha256(model_file.read_bytes().removesuffix(b'\nTOP = "ethernet"\n')).hexdigest() != ORACLE_SHA256:
    raise RuntimeError("independent model implementation has changed")
original_test = test_file.read_text().replace('from ethernet_model import', 'from ethernet_oracle import')
original_test = original_test.replace('import random\nimport pytest\n', "import random\nimport pytest\nsys.path.insert(0, str(Path(__file__).resolve().parent if (Path(__file__).resolve().parent / 'ethernet_oracle.py').is_file() else Path(__file__).resolve().parents[1] / 'model'))\n")
if hashlib.sha256(original_test.encode()).hexdigest() != ORIGINAL_TEST_SHA256:
    raise RuntimeError("independent model tests have changed")
import test_ethernet_model as _src

CASES = {}
for _name in sorted(vars(_src)):
    _fn = getattr(_src, _name)
    if not (_name.startswith('test_') and callable(_fn)):
        continue
    _marks = [m for m in getattr(_fn, 'pytestmark', ()) if m.name == 'parametrize']
    if len(_marks) > 1:
        raise RuntimeError(f'M15 unsupported parameter stacking in {_name}')
    if _marks:
        _mark = _marks[0]
        _params = [x.strip() for x in _mark.args[0].split(',')]
        if not _params or not all(_params):
            raise RuntimeError(f'M15 invalid parametrization for {_name}')
        for _i, _entry in enumerate(_mark.args[1]):
            if hasattr(_entry, 'values') and hasattr(_entry, 'marks'):
                if _entry.marks:
                    raise RuntimeError(f'M15 test skip/xfail requires explicit model review: {_name}[{_i}]')
                _vals = tuple(_entry.values)
            elif len(_params) == 1:
                _vals = (_entry,)
            else:
                _vals = tuple(_entry)
            if len(_vals) != len(_params):
                raise RuntimeError(f'M15 parameter arity mismatch: {_name}[{_i}]')
            _id = f'{_name}_{_i:03d}'
            if _id in CASES:
                raise RuntimeError(f'M15 duplicate case {_id}')
            CASES[_id] = (_fn, _vals)
    else:
        if _name in CASES:
            raise RuntimeError(f'M15 duplicate case {_name}')
        CASES[_name] = (_fn, ())

EXPECTED_IDS = ['test_bad_fcs_each_octet_000', 'test_bad_fcs_each_octet_001', 'test_bad_fcs_each_octet_002', 'test_bad_fcs_each_octet_003', 'test_bad_fcs_each_octet_004', 'test_bad_fcs_each_octet_005', 'test_bad_fcs_each_octet_006', 'test_crc_known_000', 'test_crc_known_001', 'test_crc_known_002', 'test_crc_known_003', 'test_csr_counter_and_irq', 'test_csr_counter_wrap', 'test_csr_pending_ack', 'test_csr_reset_clears_events', 'test_csr_reset_defaults', 'test_csr_speed_valid', 'test_ifg_rejected_000', 'test_ifg_rejected_001', 'test_ifg_rejected_002', 'test_ifg_rejected_003', 'test_ifg_valid', 'test_long_frame_roundtrip', 'test_mii_order', 'test_mii_roundtrip_000', 'test_mii_roundtrip_001', 'test_mii_roundtrip_002', 'test_no_padding_000', 'test_no_padding_001', 'test_no_padding_002', 'test_no_padding_003', 'test_no_padding_004', 'test_no_padding_005', 'test_phy_error_with_good_fcs', 'test_random_independent_crc_crosscheck', 'test_reject_bad_mii_000', 'test_reject_bad_mii_001', 'test_reject_bad_mii_002', 'test_roundtrip_pad_000', 'test_roundtrip_pad_001', 'test_roundtrip_pad_002', 'test_roundtrip_pad_003', 'test_roundtrip_pad_004', 'test_roundtrip_pad_005', 'test_roundtrip_pad_006', 'test_roundtrip_pad_007', 'test_short_or_bad_preamble', 'test_speed_unknown', 'test_speeds_000', 'test_speeds_001', 'test_speeds_002']
if sorted(CASES) != EXPECTED_IDS or len(CASES) != 51:
    raise RuntimeError(f'M15 source testcase identities changed: {sorted(CASES)}')

@pytest.mark.parametrize('case_id', EXPECTED_IDS, ids=EXPECTED_IDS)
def test_model_case(case_id):
    """Run actual original model assertion; FlexSoC collector consumes [case_id]."""
    fn, arguments = CASES[case_id]
    fn(*arguments)
