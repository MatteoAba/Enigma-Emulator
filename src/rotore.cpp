#include <iostream>
#include "struttura.h"
using namespace std;

void Rotore::copiaArray(const char *src, char *dst)
{
    dst = new char[LEN];
    cout << endl;                                                                  // DEBUG
    
    for (int i = 0; i < LEN; ++i) {
        dst[i] = src[i];
        cout << "src[" << i << "] = " << src[i] << " | ";                          // DEBUG
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
    cout << "\nColonna: " << col << endl;             // DEBUG
    cout << "Prova pun[9]" << pun[9];                 // DEBUG
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