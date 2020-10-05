# Emulatore Enigma

Emulatore della macchina utilizzata dai nazisti per criptare i messaggi durante la seconda guerra mondiale. Per vedere il funzionamento base della macchina leggere [How It Works](docs/HowItWorks.md).

## Per Iniziare

Per compilare l'emulatore sarà necessario semplicemente un compilatore C++.

### Ottenere l'emulatore

Sarà necessario semplicemente clonare il repository.

```
git clone https://github.com/MatteoAba/EmulatoreEnigma.git
```

### Avviare l'emulatore

Per compilare e avviare l'emulatore su windows si esegua:

```
cd EmulatoreEnigma
g++ main.cpp rotore.cpp riflettore.cpp enigma.cpp test\testEnigma.cpp -o emulatore
emulatore
```

## Licenza

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
