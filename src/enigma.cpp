#include <iostream>
#include "struttura.h"
using namespace std;

Enigma::Enigma()
{
    for (int i = 0; i < 3; ++i) {
        _rots[i] = NULL;
        _ordine[i] = 0;
    }

    _rif = NULL;
}

void Enigma::setta(chiave key)
{
    // se gia settato lo resetto
    if (_rif) {
        for (int i = 0; i < 3; ++i) {
            _ordine[i] = 0;
            delete _rots[i];
        }
        delete _rif;
    }
    
    // creo il tre rotori
    for (int i = 0; i < 3; ++i) {
        _ordine[i] = key.ordine[i];
        _rots[i] = new Rotore(ROT[_ordine[i] - 1], LAYOUT, key.letRot[i]);
    }

    // creo il riflettore
    _rif = new Riflettore(key.letRif);
}

void Enigma::stampaStato()
{
    printf("\n| STATO DELLA MACCHINA |\n");

    // ordine rotori
    printf("\nORDINE ROTORI:");
    printf("\n| ROS = %d | ROC = %d | ROD = %d |\n", _ordine[0], _ordine[1], _ordine[2]);

    // stato riflettore
    printf("\nSTATO RIFLETTORE:\n");
    _rif->stampaTutto();

    // stato rotori
    printf("\nSTATO ROS:\n");
    _rots[0]->stampaTutto();
    printf("\nSTATO ROC:\n");
    _rots[1]->stampaTutto();
    printf("\nSTATO ROD:\n");
    _rots[2]->stampaTutto();
}


char Enigma::traduci(char let)
{
    // se è uno spazio, non lo traduco
    if (let == '-')
        return ' ';
    
    // ricavo la posizione della lettera da mandare in input al primo rotore
    int pos;
    for (pos = 0; pos < LEN; ++pos)
        if (LAYOUT[pos] == let)
            break;

    // primo passaggio dai rotori (input a dx, output a sx)
    pos = _rots[2]->cambia(pos, dx);
    pos = _rots[1]->cambia(pos, dx);   
    pos = _rots[0]->cambia(pos, dx);

    // passo dal riflettore
    pos = _rif->rifletti(pos);

    // secondo passaggio dai rotori (input a sx, output a dx)
    pos = _rots[0]->cambia(pos, sx);
    pos = _rots[1]->cambia(pos, sx);
    pos = _rots[2]->cambia(pos, sx);

    // estraggo la lettera tradotta
    let = LAYOUT[pos];

    // aggiorno la posizione di rotori
    bool upd = _rots[2]->update();
    if (upd) upd = _rots[1]->update();
    if (upd) _rots[0]->update();

    return let;
}

void Enigma::esecuzione(vector<char> str)
{
    cout << "Traduzione : ";
    int n = str.size();

    for (int i = 0; i < n; ++i) {
        cout << traduci(str[i]);
    }
    cout << endl << endl;
}