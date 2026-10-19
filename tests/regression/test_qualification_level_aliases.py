from flexsoc.backend.release.qualification import QualificationFlow

def test_l1_l2_aliases():
    assert QualificationFlow.normalize_qualification_level("L1") == 1
    assert QualificationFlow.normalize_qualification_level("l2") == 2
    assert QualificationFlow.normalize_qualification_level("contract") == 1
    assert QualificationFlow.normalize_qualification_level("rtl") == 2
    assert QualificationFlow.normalize_qualification_level("auto") is None
