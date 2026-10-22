"""Known-answer RV timer model checks sharing real RTL scenario settings."""
import pytest
from rv_timer_model import RvTimerModel
import scenarios


@pytest.mark.parametrize("case_id", scenarios.MODEL_CASES)
def test_model_case(case_id):
    if case_id == "timer":
        cfg = scenarios.TIMER
        timer = RvTimerModel(active=cfg.active, prescaler=cfg.prescaler,
                             step=cfg.step, mtime=cfg.mtime,
                             compare=cfg.compare, irq_enable=cfg.irq_enable)
        assert timer.cycle() == {"tick": 1, "mtime": 1, "irq_state": 1, "irq": 1}
        timer.write_compare(0xFFFFFFFF)
        assert timer.irq_state is False
        assert timer.cycle()["irq"] == 0
    elif case_id == "reconfig":
        before, after = scenarios.RECONFIG_BEFORE, scenarios.RECONFIG_AFTER
        timer = RvTimerModel(active=before.active, prescaler=before.prescaler,
                             step=before.step, mtime=before.mtime,
                             compare=before.compare, irq_enable=before.irq_enable)
        assert timer.cycle()["mtime"] == before.mtime
        timer.prescaler, timer.step = after.prescaler, after.step
        timer.mtime, timer.compare = after.mtime, after.compare
        assert timer.cycle()["mtime"] == after.mtime
        assert timer.irq_state is False
    else:
        raise AssertionError(case_id)
