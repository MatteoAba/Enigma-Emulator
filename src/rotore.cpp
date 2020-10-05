#include <iostream>
#include "struttura.h"
using namespace std;

void Rotore::copiaArray(const char *src, char *&dst)
{
    dst = new char[LEN];
    
    for (int i = 0; i < LEN; ++i) {
        dst[i] = src[i];
    }
}

Rotore::Rotore(const char *s, const char *d, char ini)
{
    copiaArray(s, _sx);
    copiaArray(d, _dx);
    _off = (ini != 'Q') ? trovaPos(ini, dx) : 0;
}

int Rotore::trovaPos(char let, colonna col)
{
    char *pun = (col) ? _dx : _sx;
    int i;

    // cerco la posizione assoluta
    for (i = 0; i < LEN; ++i)
        if (pun[i] == let)
            break;
    
    // calcolo la posizione relativa all'offset
    int pos = (i - _off) % LEN;
    pos = (pos >= 0) ? pos : pos + LEN;

    return pos;
}

char Rotore::trovaLet(int pos, colonna col)
{
    // converto la posizione relativa all'offset in posizione assoluta
    pos = (pos + _off) % LEN;
    
    if (col)
        return _dx[pos];
        
    return _sx[pos];
}

int Rotore::cambia(int i, colonna c)
{
    // data la posizione di input e la colonna d'entrata, trovo la lettera
    char input = trovaLet(i, c);

    // data la lettera trovo la posizione in output
    return trovaPos(input, (c) ? sx : dx);
}

bool Rotore::update()
{
    _off = (_off + 1) % LEN;

    // se ha completato il giro ritorna true, altrimenti false
    if (!_off) 
        return true;
    return false;
}

void Rotore::stampaArray(char *pun)
{
    for (int i = 0; i < LEN; ++i)
        cout << pun[(i + _off) % LEN] << ' ';
    cout << endl;
}

void Rotore::stampaTutto()
{   
    stampaArray(_dx);
    stampaArray(_sx);
}