const int LEN = 26;
enum colonna {sx, dx};                              // sx = 0, dx = 1

class Rotore {
    private:
        char *_sx, *_dx;
        int _off = 0;

        // UTILITY
        void copiaArray(const char*, char*&);
        void stampaArray(char*);           

    public:
        Rotore(const char*, const char*, char);     // in ingresso do colonna sinistra e destra
        int trovaPos(char, colonna);                // dati lettera e colonna ne trova la posizione, tenendo conto dell'offset
        char trovaLet(int, colonna);                // dati posizione e colonna trova la lettera
        int cambia(int, colonna);                   // funzionamento del rotore
        void stampaTutto();             
};
/*
class Enigma {
    private:

    public:
};*/