# CORDIC Python Utilities

This directory contains the Python reference infrastructure used to support the
development and verification of the `cordic` RTL IP.

The Python code in this folder serves multiple purposes:

- provide a golden reference model for the CORDIC algorithm
- define the fixed-point numerical behavior
- generate directed and random test vectors
- produce plots and error analysis
- offer an interactive dashboard for design-space exploration and debug

The intent is to keep the Python side as the single source of truth for:
- algorithm behavior
- float-to-fixed conversion
- LUT generation
- expected outputs for verification

---

## Directory content

### cordic_model.py

Main CORDIC reference model.

This file implements:

- floating-point helpers
- fixed-point conversion helpers
- angle normalization
- CORDIC gain computation
- atan LUT generation
- iterative CORDIC model in:
  - rotation mode
  - vectoring mode
- convenience wrappers for:
  - sine/cosine
  - magnitude/atan2
- directed and random vector generation
- JSON and CSV export
- lightweight self-check against Python math

This is the main golden model and should be considered the numerical
reference for both RTL and cocotb verification.

---

### cordic_plots.py

Plotting and analysis utilities.

This file generates offline plots to inspect:

- sin / cos reference versus CORDIC
- magnitude / angle reference versus CORDIC
- absolute error versus input domain
- error histograms
- vectoring input domain sweep

Typical use cases:

- fixed-point format evaluation
- iteration count tradeoff study
- regression result inspection
- algorithm bring-up debug

Plots are saved as PNG files.

---

### cordic_dashboard.py

Interactive Streamlit dashboard.

This file provides an interactive UI to explore:

- numerical configuration
- sweep results
- error metrics
- LUT content
- directed vectors
- raw sweep tables

Typical use cases:

- design reviews
- debug sessions
- interactive accuracy analysis
- quick comparison of different format choices

---

## Recommended workflow

A typical development flow is:

1. Define the numerical configuration
   - data width
   - fractional bits
   - angle format
   - iteration count

2. Validate the model
   - print configuration
   - inspect LUT
   - run self-check

3. Generate plots
   - inspect global behavior
   - identify convergence limits
   - inspect quantization effects

4. Generate test vectors
   - directed vectors for debug
   - random vectors for regression

5. Use the same model in cocotb and RTL verification

---

## Dependencies

Minimum recommended:

- Python 3.10+

Core model:
- standard library only

Plotting:
- numpy
- matplotlib

Dashboard:
- numpy
- pandas
- plotly
- streamlit

Install everything with:

pip install numpy matplotlib pandas plotly streamlit

---

## Running the reference model

Print configuration:

python workspace/runs/cordic/dev/py/cordic_model.py --print-config

Print LUT:

python workspace/runs/cordic/dev/py/cordic_model.py --print-lut

Run self-check:

python workspace/runs/cordic/dev/py/cordic_model.py --selfcheck --count 200

---

## Generating test vectors

Directed rotation (JSON):

python workspace/runs/cordic/dev/py/cordic_model.py \
  --gen-directed-rotation-json workspace/runs/cordic/dev/sim/cordic_rotation_directed.json

Directed vectoring (JSON):

python workspace/runs/cordic/dev/py/cordic_model.py \
  --gen-directed-vectoring-json workspace/runs/cordic/dev/sim/cordic_vectoring_directed.json

Random vectoring (CSV):

python workspace/runs/cordic/dev/py/cordic_model.py \
  --gen-random-vectoring-csv workspace/runs/cordic/dev/sim/cordic_vectoring_random.csv \
  --count 500 --seed 42

---

## Generating plots

Run full analysis:

python workspace/runs/cordic/dev/py/cordic_plots.py

Only rotation mode:

python workspace/runs/cordic/dev/py/cordic_plots.py --rotation-only

Only vectoring mode:

python workspace/runs/cordic/dev/py/cordic_plots.py --vectoring-only

Custom configuration:

python workspace/runs/cordic/dev/py/cordic_plots.py \
  --iterations 12 \
  --output-dir workspace/runs/cordic/dev/report/plots_custom

---

## Running the dashboard

Start Streamlit:

streamlit run workspace/runs/cordic/dev/py/cordic_dashboard.py

The dashboard allows you to:

- change fixed-point format interactively
- change iteration count
- inspect error metrics in real time
- visualize LUT quantization
- inspect directed test vectors

---

## Notes for RTL alignment

Important aspects to keep aligned between Python and RTL:

- fixed-point format (width + fractional bits)
- iteration count
- LUT values
- arithmetic shift behavior
- gain compensation strategy

Also note:

- base CORDIC has a limited convergence range
- full [-pi, pi] support may require quadrant mapping in RTL

---

## Suggested next steps

- integrate this model in cocotb as golden reference
- export vectors for SystemVerilog testbench
- align LUT exactly with RTL implementation
- define error tolerances (LSB-based or absolute)
- add regression scripts for CI

