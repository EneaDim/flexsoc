# Coding Guidelines

**Principio:** fully object-oriented dove offre responsabilità chiare; minimale in codice, file e astrazioni, ma completo e funzionale.

- Una classe per una responsabilità reale; evitare wrapper, gerarchie e factory senza beneficio concreto.
- Preferire metodi piccoli, naming esplicito e dipendenze visibili. Ridurre duplicazioni e configurazioni implicite.
- Separare il backend generico dalle implementazioni dei protocolli/IP: le estensioni si dichiarano, non si hardcodano.
- Tenere il package ordinato: sorgenti SystemVerilog `.sv`, primitive condivise referenziate senza duplicarle, niente versioni obsolete o file generati nel catalogo.
- Non moltiplicare file di test per singoli fix: estendere test esistenti quando serve, conservando comunque le verifiche essenziali.
- Non ottimizzare il numero di linee a scapito di sicurezza, chiarezza o correttezza.
