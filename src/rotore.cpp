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

Rotore::Rotore(const char *s, const char *d)
{
    copiaArray(s, _sx);
    copiaArray(d, _dx);
}

int Rotore::trovaPos(char let, colonna col)
{
    char *pun = (col) ? _dx : _sx;
    int i;

    for (i = 0; i < LEN; ++i)
        if (pun[i] == let)
            break;
    
    return i;
}

char Rotore::trovaLet(int pos, colonna col)
{
    if (col)
        return _dx[pos];
        
    return _sx[pos];
}

void Rotore::stampaArray(char *pun)
{
    for (int i = 0; i < LEN; ++i)
        cout << pun[i] << ' ';
    cout << endl;
}

void Rotore::stampaTutto()
{   
    stampaArray(_dx);
    stampaArray(_sx);
}