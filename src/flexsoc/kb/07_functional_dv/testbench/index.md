# Testbench & Plugins

- Il backend ospita discovery, configurazione, esecuzione e raccolta di evidenze in modo indipendente dal protocollo.
- Ogni IP può dichiarare plugin Cocotb con driver/master, monitor e scoreboard propri (per esempio un master AXI-Lite per la regmap).
- Il solo caricamento di un plugin non costituisce un test superato: sono necessari stimoli, osservazioni, assert e prova di esecuzione nel simulatore.
