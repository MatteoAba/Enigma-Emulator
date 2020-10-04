const int LEN = 26;
const char LAYOUT[26] {'Q','W','E','R','T','Z','U','I','O','A','S','D','F','G','H','J','K','P','Y','X','C','V','B','N','M','L'};
const char RotI[26] {'A','V','O','E','Y','F','W','L','D','Q','C','B','S','P','T','K','R','G','I','J','U','H','X','Z','M','N'};
const char RotII[26] {'Y','U','F','H','X','Z','M','N','J','G','O','P','A','Q','I','R','L','D','T','W','V','K','S','B','C','E'};
const char RotIII[26] {'S','T','I','O','F','M','Y','Z','E','Q','D','L','B','C','K','J','G','V','P','U','R','W','N','X','A','H'};

enum colonna {sx, dx};                      // sx = 0, dx = 1

class Rotore {
    private:
        char *_sx, *_dx;
        void copiaArray(const char*, char*);

    public:
        Rotore(const char*, const char*);   // in ingresso do colonna sinistra e destra
        int trovaPos(char, colonna);        // dati lettera e colonna ne trova la posizione
        char trovaLet(int, colonna);        // dati posizione e colonna trova la lettera
};
/*
class Enigma {
    private:

    public:
};*/