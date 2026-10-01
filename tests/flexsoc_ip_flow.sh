#!/usr/bin/env bash
# Source from the repository root:
#   source tests/flexsoc_ip_flow.sh
#
# Full reusable IP qualification flow:
#   ip_load -> interface collateral -> RTL DV/formal -> SKY130 + IHP
#   -> 3 GLS tests x min/typ/max -> qualification -> ip_save.
#

_flexsoc_ip_flow_impl() {
    if [ "$#" -ne 8 ]; then
        echo "usage:"
        echo "  flexsoc_ip_flow IP TARGET_ITF LOAD_ITF LOAD_VERSION SAVE_VERSION GLS1 GLS2 GLS3"
        echo
        echo "examples:"
        echo "  flexsoc_ip_flow uart tlul tlul 1.0.0 1.0.0 smoke corners parity_error"
        echo "  flexsoc_ip_flow rv_timer reg_iface tlul 1.0.0 1.0.0 smoke corners interrupt_test"
        echo "  flexsoc_ip_flow cordic tlul tlul - 1.0.0 smoke corners quadrant_sweep"
        return 2
    fi

    local IP="$1"
    local TARGET_ITF="$2"
    local LOAD_ITF="$3"
    local LOAD_VERSION="$4"
    local SAVE_VERSION="$5"
    local GLS1="$6"
    local GLS2="$7"
    local GLS3="$8"

    local REPO="${FLEXSOC_REPO_ROOT:-$HOME/github/flexsoc}"
    local ROOT="${FLEXSOC_IP_FLOW_ROOT:-/tmp/flexsoc-ip-release}"
    local RUN_ID="${FLEXSOC_IP_FLOW_RUN_ID:-release}"
    local LIBRARY_ROOT="$REPO/hw/ips"
    local WS="$ROOT/$IP-$TARGET_ITF"
    local RUN="$WS/runs/$IP/$RUN_ID"
    local GLS_TESTS="$GLS1,$GLS2,$GLS3"
    local GLS_TIMING_MODES="min,typ,max"
    local GLS_BACKEND="sv"
    local ORS=""
    local MODEL=""
    local MODEL_SHA_PRE=""
    local MODEL_SHA_POST=""
    local PDK=""
    local HOLD_MARGIN=""
    local PHYS_RC=0
    local PHYSICAL_REVIEW=0
    local SAVED=""
    local LEAK=""
    local FLOW_MODE="${FLEXSOC_IP_FLOW_MODE:-full}"
    local SAVE_QUAL_LEVEL="auto"

    cd "$REPO" || return 1

    case "$FLOW_MODE" in
        full) SAVE_QUAL_LEVEL="auto" ;;
        pre-pnr) SAVE_QUAL_LEVEL="technology" ;;
        *)
            echo "[STOP] unsupported FLEXSOC_IP_FLOW_MODE=$FLOW_MODE (expected full or pre-pnr)"
            return 2
            ;;
    esac

    case "$TARGET_ITF" in
        tlul|reg_iface|axi_lite) ;;
        *)
            echo "[STOP] unsupported TARGET_ITF=$TARGET_ITF"
            return 2
            ;;
    esac

    case "$LOAD_ITF" in
        tlul|reg_iface|axi_lite) ;;
        *)
            echo "[STOP] unsupported LOAD_ITF=$LOAD_ITF"
            return 2
            ;;
    esac

    if [ "$GLS1" = "$GLS2" ] || [ "$GLS1" = "$GLS3" ] || [ "$GLS2" = "$GLS3" ]; then
        echo "[STOP] GLS1/GLS2/GLS3 must be three distinct tests"
        return 2
    fi

    if [ -n "${FLEXSOC_E2E_ORS:-}" ]; then
        ORS="$FLEXSOC_E2E_ORS"
    elif [ -n "${ORFS_ROOT:-}" ] && [ -f "$ORFS_ROOT/Makefile" ]; then
        ORS="$ORFS_ROOT"
    elif [ -n "${ORFS_ROOT:-}" ] && [ -f "$ORFS_ROOT/flow/Makefile" ]; then
        ORS="$ORFS_ROOT/flow"
    else
        ORS="$HOME/OpenROAD-flow-scripts/flow"
    fi

    if [ "$FLOW_MODE" = "full" ] && [ ! -f "$ORS/Makefile" ]; then
        echo "[STOP] OpenROAD-flow-scripts flow not found:"
        echo "$ORS"
        return 1
    fi

    echo
    echo "================================================================"
    echo "FLEXSOC IP LOAD / QUALIFY / SAVE"
    echo "================================================================"
    echo "IP            : $IP"
    echo "load interface: $LOAD_ITF"
    echo "target iface  : $TARGET_ITF"
    echo "load version  : $LOAD_VERSION"
    echo "save version  : $SAVE_VERSION"
    echo "GLS tests     : $GLS_TESTS"
    echo "GLS timing    : min,typ,max  (FF,TT,SS)"
    echo "GLS count     : 9 post-syn + 9 post-implementation per PDK"
    echo "GLS backend   : $GLS_BACKEND"
    echo "workspace     : $WS"
    echo "================================================================"

    rm -rf "$WS"
    mkdir -p "$WS" || return 1

    echo
    echo "=== BASE SETTINGS ==="

    fx settings --reset \
        TOP="$IP" \
        RUN_TOP="$IP" \
        RUN_ID="$RUN_ID" \
        IP_NAME="$IP" \
        REG_ITF="$LOAD_ITF" \
        N_CLOCKS=1 \
        CLOCK_DOMAINS=core:clk_i:rst_ni:10:low \
        "CLOCK_RELATIONSHIPS=" \
        TARGET_OPT=delay1 \
        'REGRESSION_BACKENDS=sv cocotb' \
        GLS_BACKEND="$GLS_BACKEND" \
        TEST_NAMES="$GLS_TESTS" \
        TIMING_MODES="$GLS_TIMING_MODES" \
        SDF_STRICT=1 \
        POWER_TEST_NAMES="$GLS_TESTS" \
        POWER_GLS_BACKENDS="$GLS_BACKEND" \
        POWER_TIMING_MODES="$GLS_TIMING_MODES" \
        "ORS=$ORS" \
        PNR_HOLD_SLACK_MARGIN=0.05 \
        QUAL_LEVEL=auto \
        "IP_LIBRARY_ROOT=$LIBRARY_ROOT" \
        --workdir "$WS" || return 1

    if [ "$LOAD_VERSION" != "-" ]; then
        fx settings \
            IP_VERSION="$LOAD_VERSION" \
            --workdir "$WS" || return 1
    fi

    echo
    echo "=== TOOL / VENDOR CHECK ==="

    fx doctor --workdir "$WS" || return 1

    fx fetch \
        --set VENDOR=opentitan_reggen \
        --workdir "$WS" || return 1

    if [ "$LOAD_ITF" = "tlul" ] || [ "$TARGET_ITF" = "tlul" ]; then
        fx fetch \
            --set VENDOR=lowrisc_ip \
            --workdir "$WS" || return 1
    fi

    if [ "$LOAD_ITF" = "axi_lite" ] || [ "$TARGET_ITF" = "axi_lite" ]; then
        fx fetch \
            --set VENDOR=pulp_register_interface \
            --workdir "$WS" || return 1
        fx fetch \
            --set VENDOR=pulp_common_cells \
            --workdir "$WS" || return 1
        fx fetch \
            --set VENDOR=pulp_axi \
            --workdir "$WS" || return 1
    fi

    echo
    _FLEXSOC_FLOW_STAGE="ip_load"
    echo "=== IP LOAD ==="

    if [ "$LOAD_VERSION" = "-" ]; then
        fx ip_load \
            --set IP_NAME="$IP" \
            --set REG_ITF="$LOAD_ITF" \
            --set IP_LIBRARY_ROOT="$LIBRARY_ROOT" \
            --workdir "$WS" || return 1
    else
        fx ip_load \
            --set IP_NAME="$IP" \
            --set IP_VERSION="$LOAD_VERSION" \
            --set REG_ITF="$LOAD_ITF" \
            --set IP_LIBRARY_ROOT="$LIBRARY_ROOT" \
            --workdir "$WS" || return 1
    fi

    if [ "$FLOW_MODE" = "pre-pnr" ]; then
        echo
        echo "=== PRE-PNR: DROP LOADED PHYSICAL EVIDENCE ==="
        rm -rf "$RUN/impl" "$RUN/signoff/sky130/post_impl" "$RUN/signoff/ihp-sg13g2/post_impl"
    fi

    MODEL="$RUN/dv/functional/model/${IP}_tests.py"

    if [ ! -f "$MODEL" ]; then
        echo "[STOP] authoritative Python tests missing:"
        echo "$MODEL"
        return 1
    fi

    MODEL_SHA_PRE="$(sha256sum "$MODEL")"
    MODEL_SHA_PRE="${MODEL_SHA_PRE%% *}"
    echo "[python-model] PRE $MODEL_SHA_PRE $MODEL"

    echo
    echo "=== TARGET INTERFACE / RELEASE IDENTITY ==="

    fx settings \
        IP_NAME="$IP" \
        IP_VERSION="$SAVE_VERSION" \
        REG_ITF="$TARGET_ITF" \
        GLS_BACKEND="$GLS_BACKEND" \
        TEST_NAMES="$GLS_TESTS" \
        TIMING_MODES="$GLS_TIMING_MODES" \
        SDF_STRICT=1 \
        POWER_TEST_NAMES="$GLS_TESTS" \
        POWER_GLS_BACKENDS="$GLS_BACKEND" \
        POWER_TIMING_MODES="$GLS_TIMING_MODES" \
        --workdir "$WS" || return 1

    if [ "$TARGET_ITF" != "$LOAD_ITF" ]; then
        echo
        echo "=== INTERFACE MIGRATION: $LOAD_ITF -> $TARGET_ITF ==="
        rm -f \
            "$RUN/ip.json" \
            "$RUN/meta/contract.json"
    fi

    echo
    _FLEXSOC_FLOW_STAGE="interface_collateral"
    echo "=== MACHINE-OWNED INTERFACE COLLATERAL ==="

    fx reg doc driver top_from_core flist \
        --force \
        --workdir "$WS" || return 1

    fx sdc \
        --setup \
        --force \
        --workdir "$WS" || return 1

    echo
    _FLEXSOC_FLOW_STAGE="lint"
    echo "=== LINT / STRUCTURAL ==="

    fx lint \
        --workdir "$WS" || return 1

    fx lint \
        --summary \
        --workdir "$WS" || return 1


    fx slang_hier \
        --set "SLANG_ROOT=$RUN/rtl" \
        --set "SLANG_TOP_FILE=$RUN/rtl/$IP.sv" \
        --set "SLANG_SEARCH_ARGS=" \
        --workdir "$WS" || return 1

    fx cdc_rdc \
        --setup \
        --force \
        --workdir "$WS" || return 1

    fx cdc_rdc \
        --workdir "$WS" || return 1

    fx cdc_rdc \
        --summary \
        --workdir "$WS" || return 1

    echo
    echo "=== AUTHORITATIVE PYTHON -> GENERATED TESTS ==="

    rm -rf "$RUN/dv/functional/tests"

    fx regmap_py \
        --force \
        --workdir "$WS" || return 1

    fx tests_gen \
        --force \
        --workdir "$WS" || return 1

    fx tests \
        --workdir "$WS" || return 1

    MODEL_SHA_POST="$(sha256sum "$MODEL")"
    MODEL_SHA_POST="${MODEL_SHA_POST%% *}"
    echo "[python-model] POST $MODEL_SHA_POST $MODEL"

    if [ "$MODEL_SHA_PRE" != "$MODEL_SHA_POST" ]; then
        echo "[STOP] authoritative Python model changed during generation"
        return 1
    fi

    for TEST in "$GLS1" "$GLS2" "$GLS3"; do
        if [ ! -d "$RUN/dv/functional/tests/$TEST" ]; then
            echo "[STOP] selected GLS test does not exist: $TEST"
            return 1
        fi
    done

    echo
    _FLEXSOC_FLOW_STAGE="rtl_regression"
    echo "=== RTL REGRESSION: ALL GENERATED TESTS ==="

    rm -rf \
        "$RUN/dv/functional/tb/sv" \
        "$RUN/dv/functional/tb/cocotb" \
        "$RUN/dv/functional/sim" \
        "$RUN/dv/functional/coverage"

    fx tb \
        --setup \
        --force \
        --workdir "$WS" || return 1

    fx cocotb \
        --setup \
        --force \
        --workdir "$WS" || return 1

    fx regression \
        --workdir "$WS" || return 1
    fx regression --summary --workdir "$WS" || return 1
    fx regression --show --workdir "$WS" || return 1
    fx regression --debug --workdir "$WS" || return 1

    fx coverage \
        --workdir "$WS" || return 1
    fx coverage --summary --workdir "$WS" || return 1

    echo
    _FLEXSOC_FLOW_STAGE="formal"
    echo "=== FORMAL SETUP: PRESERVE AUTHORED COLLATERAL ==="

    fx formal \
        --setup \
        --workdir "$WS" || {
        echo "[STOP] formal setup failed; no --force was used"
        return 1
    }

    echo
    _FLEXSOC_FLOW_STAGE="formal"
    echo "=== FORMAL RUN ==="

    fx formal --workdir "$WS" || return 1
    fx formal --summary --workdir "$WS" || return 1
    fx formal --show --workdir "$WS" || return 1
    fx formal --debug --workdir "$WS" || return 1

    echo
    echo "================================================================"
    echo "TECHNOLOGY FLOWS"
    echo "================================================================"

    for PDK in sky130 ihp-sg13g2; do
        echo
        echo "----------------------------------------------------------------"
        echo "$IP / $TARGET_ITF / $PDK"
        echo "----------------------------------------------------------------"

        fx pdk use "$PDK" \
            --workdir "$WS" || return 1

        HOLD_MARGIN="${FLEXSOC_PNR_HOLD_SLACK_MARGIN:-0.05}"

        fx settings \
            PNR_HOLD_SLACK_MARGIN="$HOLD_MARGIN" \
            --workdir "$WS" || return 1

        fx pdk info "$PDK" \
            --workdir "$WS" || return 1

        echo
        echo "=== REFRESH MACHINE-OWNED TB / $PDK ==="

        fx tb \
            --setup \
            --force \
            --workdir "$WS" || return 1

        fx cocotb \
            --setup \
            --force \
            --workdir "$WS" || return 1

        echo
        _FLEXSOC_FLOW_STAGE="synthesis"
        echo "=== SYNTHESIS / $PDK ==="

        fx syn \
            --setup \
            --force \
            --workdir "$WS" || return 1

        fx syn \
            --workdir "$WS" || return 1

        fx syn --summary \
            --workdir "$WS" || return 1

        fx syn --show \
            --workdir "$WS" || return 1

        fx syn --debug \
            --workdir "$WS" || return 1

        _FLEXSOC_FLOW_STAGE="post_syn"
        echo "=== POST-SYN SIGNOFF / $PDK ==="

        fx signoff \
            --setup \
            --force \
            --workdir "$WS" || return 1

        fx sdf \
            --workdir "$WS" || return 1

        fx sta \
            --workdir "$WS" || return 1
        fx sta --summary --workdir "$WS" || return 1
        fx sta --show --workdir "$WS" || return 1
        fx sta --debug --workdir "$WS" || return 1

        fx power-estimate \
            --workdir "$WS" || return 1
        fx power-estimate --summary --workdir "$WS" || return 1
        fx power-estimate --show --workdir "$WS" || return 1
        fx power-estimate --debug --workdir "$WS" || return 1

        echo
        _FLEXSOC_FLOW_STAGE="post_syn"
        echo "=== POST-SYN GLS: 3 TESTS x FF/TT/SS = 9 RUNS ==="

        fx sim --post-syn --all \
            --set GLS_BACKEND="$GLS_BACKEND" \
            --set TIMING_MODES="$GLS_TIMING_MODES" \
            --set TEST_NAMES="$GLS_TESTS" \
            --set SDF_STRICT=1 \
            --workdir "$WS" || return 1
        fx sim --post-syn --all --summary --set GLS_BACKEND="$GLS_BACKEND" --workdir "$WS" || return 1
        fx sim --post-syn --all --show --set GLS_BACKEND="$GLS_BACKEND" --workdir "$WS" || return 1
        fx sim --post-syn --all --debug --set GLS_BACKEND="$GLS_BACKEND" --workdir "$WS" || return 1

        echo
        _FLEXSOC_FLOW_STAGE="post_syn"
        echo "=== POST-SYN POWER / FUSION: SAME 3 x 3 MATRIX ==="

        fx power-analysis --all \
            --set POWER_TEST_NAMES="$GLS_TESTS" \
            --set POWER_GLS_BACKENDS="$GLS_BACKEND" \
            --set POWER_TIMING_MODES="$GLS_TIMING_MODES" \
            --workdir "$WS" || return 1
        fx power-analysis --all --summary --workdir "$WS" || return 1
        fx power-analysis --all --show --workdir "$WS" || return 1
        fx power-analysis --all --debug --workdir "$WS" || return 1

        fx fusion --all \
            --set POWER_TEST_NAMES="$GLS_TESTS" \
            --set POWER_GLS_BACKENDS="$GLS_BACKEND" \
            --set POWER_TIMING_MODES="$GLS_TIMING_MODES" \
            --workdir "$WS" || return 1
        fx fusion --all --summary --workdir "$WS" || return 1
        fx fusion --all --show --workdir "$WS" || return 1
        fx fusion --all --debug --workdir "$WS" || return 1

        if [ "$FLOW_MODE" = "pre-pnr" ]; then
            echo
            echo "=== PRE-PNR COMPLETE / $PDK ==="
            continue
        fi

        if [ "$FLOW_MODE" = "pre-pnr" ]; then
            echo
            _FLEXSOC_FLOW_STAGE="qualification"
            _FLEXSOC_FLOW_STAGE="eqy_setup"
            echo
            echo "=== EQY SETUP / $PDK ==="
            fx eqy --setup --force --workdir "$WS" || return 1
            echo
            echo "=== PRE-PNR QUALIFICATION / $PDK ==="
            fx manifest --workdir "$WS" || return 1
            fx manifest_show --workdir "$WS" || return 1
            fx metrics --workdir "$WS" || return 1
            fx check --workdir "$WS" || return 1
            fx qualify --set IP_NAME="$IP" --set IP_VERSION="$SAVE_VERSION" --set REG_ITF="$TARGET_ITF" --set QUAL_LEVEL=technology --workdir "$WS" || return 1
            continue
        fi

        echo
        echo "=== PNR / $PDK ==="

        fx pnr \
            --setup \
            --force \
            --workdir "$WS" || return 1

        fx pnr \
            --workdir "$WS" || return 1
        fx pnr --summary --workdir "$WS" || return 1
        fx pnr --show --workdir "$WS" || return 1
        fx pnr --debug --workdir "$WS" || return 1

        echo
        echo "=== PHYSICAL SIGNOFF / $PDK ==="

        fx physical_signoff \
            --workdir "$WS"
        PHYS_RC=$?

        if [ "$PHYS_RC" -ne 0 ]; then
            PHYSICAL_REVIEW=1
            echo "[REVIEW] physical_signoff RC=$PHYS_RC"
            echo "[REVIEW] continuing with post-implementation timing/power qualification"
            echo "[REVIEW] physical signoff != STA PASS"
        fi

        if [ -f "$RUN/signoff/$PDK/post_impl/physical/summary.json" ]; then
            fx physical_signoff --summary --workdir "$WS" || return 1
            fx physical_signoff --show --workdir "$WS" || return 1
            fx physical_signoff --debug --workdir "$WS" || return 1
        fi

        echo
        echo "=== POST-IMPLEMENTATION SIGNOFF / $PDK ==="

        fx signoff_post_impl \
            --setup \
            --force \
            --workdir "$WS" || return 1

        fx sdf_post_impl \
            --workdir "$WS" || return 1

        fx sta --post-impl \
            --workdir "$WS" || return 1
        fx sta --post-impl --summary --workdir "$WS" || return 1
        fx sta --post-impl --show --workdir "$WS" || return 1
        fx sta --post-impl --debug --workdir "$WS" || return 1

        echo
        echo "=== POST-IMPLEMENTATION GLS: 3 TESTS x FF/TT/SS = 9 RUNS ==="

        fx sim --post-impl --all \
            --set GLS_BACKEND="$GLS_BACKEND" \
            --set TIMING_MODES="$GLS_TIMING_MODES" \
            --set TEST_NAMES="$GLS_TESTS" \
            --set SDF_STRICT=1 \
            --workdir "$WS" || return 1
        fx sim --post-impl --all --summary --set GLS_BACKEND="$GLS_BACKEND" --workdir "$WS" || return 1
        fx sim --post-impl --all --show --set GLS_BACKEND="$GLS_BACKEND" --workdir "$WS" || return 1
        fx sim --post-impl --all --debug --set GLS_BACKEND="$GLS_BACKEND" --workdir "$WS" || return 1

        fx power-estimate --post-impl \
            --workdir "$WS" || return 1
        fx power-estimate --post-impl --summary --workdir "$WS" || return 1
        fx power-estimate --post-impl --show --workdir "$WS" || return 1
        fx power-estimate --post-impl --debug --workdir "$WS" || return 1

        echo
        _FLEXSOC_FLOW_STAGE="power"
        echo "=== POST-IMPLEMENTATION POWER / FUSION: SAME 3 x 3 MATRIX ==="

        fx power-analysis --post-impl --all \
            --set POWER_TEST_NAMES="$GLS_TESTS" \
            --set POWER_GLS_BACKENDS="$GLS_BACKEND" \
            --set POWER_TIMING_MODES="$GLS_TIMING_MODES" \
            --workdir "$WS" || return 1
        fx power-analysis --post-impl --all --summary --workdir "$WS" || return 1
        fx power-analysis --post-impl --all --show --workdir "$WS" || return 1
        fx power-analysis --post-impl --all --debug --workdir "$WS" || return 1

        fx fusion --post-impl --all \
            --set POWER_TEST_NAMES="$GLS_TESTS" \
            --set POWER_GLS_BACKENDS="$GLS_BACKEND" \
            --set POWER_TIMING_MODES="$GLS_TIMING_MODES" \
            --workdir "$WS" || return 1
        fx fusion --post-impl --all --summary --workdir "$WS" || return 1
        fx fusion --post-impl --all --show --workdir "$WS" || return 1
        fx fusion --post-impl --all --debug --workdir "$WS" || return 1

        echo
        _FLEXSOC_FLOW_STAGE="qualification"
        echo "=== REPORTING / QUALIFICATION / $PDK ==="

        fx manifest --workdir "$WS" || return 1
        fx manifest_show --workdir "$WS" || return 1
        fx metrics --workdir "$WS" || return 1
        fx check --workdir "$WS" || return 1

        fx qualify \
            --set IP_NAME="$IP" \
            --set IP_VERSION="$SAVE_VERSION" \
            --set REG_ITF="$TARGET_ITF" \
            --set QUAL_LEVEL=auto \
            --workdir "$WS" || return 1
    done

    echo
    echo "================================================================"
    echo "IP SAVE: AFTER BOTH TECHNOLOGY FLOWS"
    echo "================================================================"

    for PDK in sky130 ihp-sg13g2; do
        fx pdk use "$PDK" \
            --workdir "$WS" || return 1

        HOLD_MARGIN="${FLEXSOC_PNR_HOLD_SLACK_MARGIN:-0.05}"

        fx settings \
            PNR_HOLD_SLACK_MARGIN="$HOLD_MARGIN" \
            --workdir "$WS" || return 1

        _FLEXSOC_FLOW_STAGE="ip_save"
        _FLEXSOC_FLOW_SAVE="RUNNING"
        fx ip_save \
            --force \
            --set IP_NAME="$IP" \
            --set IP_VERSION="$SAVE_VERSION" \
            --set REG_ITF="$TARGET_ITF" \
            --set IP_LIBRARY_ROOT="$LIBRARY_ROOT" \
            --set QUAL_LEVEL="$SAVE_QUAL_LEVEL" \
            --workdir "$WS" || return 1
        _FLEXSOC_FLOW_SAVE="PASS"
    done

    SAVED="$LIBRARY_ROOT/$IP/$SAVE_VERSION/interfaces/$TARGET_ITF"

    echo
    echo "=== PACKAGE HYGIENE ==="

    if [ ! -d "$SAVED" ]; then
        echo "[STOP] saved interface missing:"
        echo "$SAVED"
        return 1
    fi

    LEAK="$(find "$SAVED" -type f -name '*.sdf' -print -quit)"
    if [ -n "$LEAK" ]; then
        echo "[STOP] packaged SDF found:"
        echo "$LEAK"
        return 1
    fi

    LEAK="$(find "$SAVED" -type d -name sim_build -print -quit)"
    if [ -n "$LEAK" ]; then
        echo "[STOP] packaged sim_build found:"
        echo "$LEAK"
        return 1
    fi

    LEAK="$(find "$SAVED" -type d -name obj_dir -print -quit)"
    if [ -n "$LEAK" ]; then
        echo "[STOP] packaged obj_dir found:"
        echo "$LEAK"
        return 1
    fi

    for PDK in sky130 ihp-sg13g2; do
        if [ ! -f "$SAVED/signoff/$PDK/post_syn/sdf/write_sdf.tcl" ]; then
            echo "[STOP] missing post-syn write_sdf.tcl for $PDK"
            return 1
        fi

        if [ "$FLOW_MODE" = "pre-pnr" ]; then
            if [ -d "$SAVED/impl/$PDK" ] || [ -d "$SAVED/signoff/$PDK/post_impl" ]; then
                echo "[STOP] unexpected post-implementation evidence in pre-pnr package for $PDK"
                return 1
            fi
        elif [ ! -f "$SAVED/signoff/$PDK/post_impl/sdf/write_sdf.tcl" ]; then
            echo "[STOP] missing post-implementation write_sdf.tcl for $PDK"
            return 1
        fi
    done

    echo
    echo "================================================================"
    echo "FLOW COMPLETE"
    echo "================================================================"
    echo "IP              : $IP"
    echo "interface       : $TARGET_ITF"
    echo "GLS tests       : $GLS_TESTS"
    echo "GLS post-syn    : 9 per PDK (3 tests x min,typ,max)"
    echo "GLS post-implementation    : 9 per PDK (3 tests x min,typ,max)"
    echo "EQY             : SETUP ONLY"
    echo "physical review : $PHYSICAL_REVIEW"
    echo "saved           : $SAVED"
    echo "workspace       : $WS"
    echo "================================================================"

    return 0
}

# Validate the retained IP set without running implementation or release.
# Start from each IP's native TL-UL release so interface migration cannot hide
# a design/package problem.
flexsoc_ip_pre_pnr_suite() {
    local failures=0
    local rc=0
    local -a rows=()

    FLEXSOC_IP_FLOW_MODE=pre-pnr flexsoc_ip_flow uart tlul tlul 1.0.0 1.0.0 smoke corners parity_error
    rc=$?
    rows+=("uart|tlul|${_FLEXSOC_LAST_RESULT}|${_FLEXSOC_LAST_STAGE}|${_FLEXSOC_LAST_SAVE}")
    [ "$rc" -eq 0 ] || failures=$((failures + 1))

    FLEXSOC_IP_FLOW_MODE=pre-pnr flexsoc_ip_flow uart_master tlul tlul 1.0.0 1.0.0 smoke host_read host_write
    rc=$?
    rows+=("uart_master|tlul|${_FLEXSOC_LAST_RESULT}|${_FLEXSOC_LAST_STAGE}|${_FLEXSOC_LAST_SAVE}")
    [ "$rc" -eq 0 ] || failures=$((failures + 1))

    FLEXSOC_IP_FLOW_MODE=pre-pnr flexsoc_ip_flow gpio tlul tlul 1.0.0 1.0.0 smoke corners interrupt_levels
    rc=$?
    rows+=("gpio|tlul|${_FLEXSOC_LAST_RESULT}|${_FLEXSOC_LAST_STAGE}|${_FLEXSOC_LAST_SAVE}")
    [ "$rc" -eq 0 ] || failures=$((failures + 1))

    FLEXSOC_IP_FLOW_MODE=pre-pnr flexsoc_ip_flow rv_timer tlul tlul 1.0.0 1.0.0 smoke corners interrupt_test
    rc=$?
    rows+=("rv_timer|tlul|${_FLEXSOC_LAST_RESULT}|${_FLEXSOC_LAST_STAGE}|${_FLEXSOC_LAST_SAVE}")
    [ "$rc" -eq 0 ] || failures=$((failures + 1))

    _flexsoc_print_suite_summary "TL-UL PRE-PNR / L4 + IP SAVE" "$failures" "${rows[@]}"
    [ "$failures" -eq 0 ]
}

# Validate the retained non-TLUL interface packages after the native TL-UL suite.
# UART/GPIO already have native packages. RV timer is intentionally migrated from
# the freshly qualified TL-UL package. UART Master remains TL-UL only for now.
flexsoc_ip_pre_pnr_interface_suite() {
    local failures=0
    local rc=0
    local -a rows=()

    # Remap every alternate register interface from the qualified TL-UL release.
    # Each successful run performs L4 qualification and ip_save --force into
    # hw/ips/<ip>/1.0.0/interfaces/<target>.
    FLEXSOC_IP_FLOW_MODE=pre-pnr flexsoc_ip_flow uart reg_iface tlul 1.0.0 1.0.0 smoke corners parity_error
    rc=$?
    rows+=("uart|reg_iface|${_FLEXSOC_LAST_RESULT}|${_FLEXSOC_LAST_STAGE}|${_FLEXSOC_LAST_SAVE}")
    [ "$rc" -eq 0 ] || failures=$((failures + 1))

    FLEXSOC_IP_FLOW_MODE=pre-pnr flexsoc_ip_flow uart axi_lite tlul 1.0.0 1.0.0 smoke corners parity_error
    rc=$?
    rows+=("uart|axi_lite|${_FLEXSOC_LAST_RESULT}|${_FLEXSOC_LAST_STAGE}|${_FLEXSOC_LAST_SAVE}")
    [ "$rc" -eq 0 ] || failures=$((failures + 1))

    FLEXSOC_IP_FLOW_MODE=pre-pnr flexsoc_ip_flow gpio reg_iface tlul 1.0.0 1.0.0 smoke corners interrupt_levels
    rc=$?
    rows+=("gpio|reg_iface|${_FLEXSOC_LAST_RESULT}|${_FLEXSOC_LAST_STAGE}|${_FLEXSOC_LAST_SAVE}")
    [ "$rc" -eq 0 ] || failures=$((failures + 1))

    FLEXSOC_IP_FLOW_MODE=pre-pnr flexsoc_ip_flow gpio axi_lite tlul 1.0.0 1.0.0 smoke corners interrupt_levels
    rc=$?
    rows+=("gpio|axi_lite|${_FLEXSOC_LAST_RESULT}|${_FLEXSOC_LAST_STAGE}|${_FLEXSOC_LAST_SAVE}")
    [ "$rc" -eq 0 ] || failures=$((failures + 1))

    FLEXSOC_IP_FLOW_MODE=pre-pnr flexsoc_ip_flow rv_timer reg_iface tlul 1.0.0 1.0.0 smoke corners interrupt_test
    rc=$?
    rows+=("rv_timer|reg_iface|${_FLEXSOC_LAST_RESULT}|${_FLEXSOC_LAST_STAGE}|${_FLEXSOC_LAST_SAVE}")
    [ "$rc" -eq 0 ] || failures=$((failures + 1))

    FLEXSOC_IP_FLOW_MODE=pre-pnr flexsoc_ip_flow rv_timer axi_lite tlul 1.0.0 1.0.0 smoke corners interrupt_test
    rc=$?
    rows+=("rv_timer|axi_lite|${_FLEXSOC_LAST_RESULT}|${_FLEXSOC_LAST_STAGE}|${_FLEXSOC_LAST_SAVE}")
    [ "$rc" -eq 0 ] || failures=$((failures + 1))

    _flexsoc_print_suite_summary "REGISTER-INTERFACE REMAPPING PRE-PNR / L4 + IP SAVE" "$failures" "${rows[@]}"
    [ "$failures" -eq 0 ]
}

# Recommended release calls for the current IP library:
#
# UART:
#   flexsoc_ip_flow uart tlul      tlul      1.0.0 1.0.0 smoke corners parity_error
#   flexsoc_ip_flow uart reg_iface reg_iface 1.0.0 1.0.0 smoke corners parity_error
#   flexsoc_ip_flow uart axi_lite  axi_lite  1.0.0 1.0.0 smoke corners parity_error
#
# GPIO:
#   flexsoc_ip_flow gpio tlul      tlul      1.0.0 1.0.0 smoke corners interrupt_levels
#   flexsoc_ip_flow gpio reg_iface reg_iface 1.0.0 1.0.0 smoke corners interrupt_levels
#   flexsoc_ip_flow gpio axi_lite  axi_lite  1.0.0 1.0.0 smoke corners interrupt_levels
#
# RV timer (new interfaces derive from the existing TLUL release):
#   flexsoc_ip_flow rv_timer tlul      tlul 1.0.0 1.0.0 smoke corners interrupt_test
#   flexsoc_ip_flow rv_timer reg_iface tlul 1.0.0 1.0.0 smoke corners interrupt_test
#   flexsoc_ip_flow rv_timer axi_lite  tlul 1.0.0 1.0.0 smoke corners interrupt_test
#
# UART master:
#   flexsoc_ip_flow uart_master tlul tlul 1.0.0 1.0.0 smoke host_read host_write
#
# CORDIC (legacy unversioned input -> 1.0.0 release):
#   flexsoc_ip_flow cordic tlul tlul - 1.0.0 smoke corners quadrant_sweep

# === FLEXSOC FLOW SUMMARY SUPPORT ===

_flexsoc_print_flow_summary() {
    local ip="$1"
    local interface="$2"
    local mode="$3"
    local result="$4"
    local stage="$5"
    local save_state="$6"
    local save_version="$7"

    echo
    echo "================================================================"
    echo "FLEXSOC IP FLOW SUMMARY"
    echo "================================================================"
    printf "%-14s : %s\n" "IP" "$ip"
    printf "%-14s : %s\n" "interface" "$interface"
    printf "%-14s : %s\n" "mode" "$mode"
    printf "%-14s : %s\n" "result" "$result"
    printf "%-14s : %s\n" "stopped_at" "$stage"
    printf "%-14s : %s\n" "ip_save" "$save_state"
    if [ "$save_state" = "PASS" ]; then
        printf "%-14s : hw/ips/%s/%s/interfaces/%s\n" "saved" "$ip" "$save_version" "$interface"
    fi
    echo "================================================================"
}

_flexsoc_print_suite_summary() {
    local title="$1"
    local failures="$2"
    shift 2

    echo
    echo "================================================================================"
    echo "FLEXSOC SUITE SUMMARY: $title"
    echo "================================================================================"
    printf "%-16s %-12s %-8s %-28s %-10s\n" "IP" "INTERFACE" "RESULT" "STOPPED_AT" "IP_SAVE"
    printf "%-16s %-12s %-8s %-28s %-10s\n" "----------------" "------------" "--------" "----------------------------" "----------"

    local row
    local ip
    local interface
    local result
    local stage
    local save_state
    for row in "$@"; do
        IFS='|' read -r ip interface result stage save_state <<< "$row"
        printf "%-16s %-12s %-8s %-28s %-10s\n" "$ip" "$interface" "$result" "$stage" "$save_state"
    done

    echo "--------------------------------------------------------------------------------"
    if [ "$failures" -eq 0 ]; then
        echo "OVERALL: PASS"
    else
        echo "OVERALL: FAIL ($failures run(s) failed)"
    fi
    echo "================================================================================"
}

flexsoc_ip_flow() {
    local summary_ip="${1:-unknown}"
    local summary_interface="${2:-unknown}"
    local summary_save_version="${5:-unknown}"
    local summary_mode="${FLEXSOC_IP_FLOW_MODE:-full}"

    _FLEXSOC_FLOW_STAGE="start"
    _FLEXSOC_FLOW_SAVE="NOT RUN"

    _flexsoc_ip_flow_impl "$@"
    local rc=$?

    if [ "$rc" -eq 0 ]; then
        _FLEXSOC_LAST_RESULT="PASS"
        _FLEXSOC_LAST_STAGE="complete"
        _FLEXSOC_LAST_SAVE="PASS"
    else
        _FLEXSOC_LAST_RESULT="FAIL"
        _FLEXSOC_LAST_STAGE="${_FLEXSOC_FLOW_STAGE:-unknown}"
        case "${_FLEXSOC_FLOW_SAVE:-NOT RUN}" in
            PASS) _FLEXSOC_LAST_SAVE="PASS" ;;
            RUNNING) _FLEXSOC_LAST_SAVE="FAIL" ;;
            *) _FLEXSOC_LAST_SAVE="NOT RUN" ;;
        esac
    fi

    _FLEXSOC_LAST_IP="$summary_ip"
    _FLEXSOC_LAST_INTERFACE="$summary_interface"

    _flexsoc_print_flow_summary \
        "$summary_ip" \
        "$summary_interface" \
        "$summary_mode" \
        "$_FLEXSOC_LAST_RESULT" \
        "$_FLEXSOC_LAST_STAGE" \
        "$_FLEXSOC_LAST_SAVE" \
        "$summary_save_version"

    return "$rc"
}
