#include "struttura.h"

void Rotore::copiaArray(const char *src, char *dst)
{
    src = new char[LEN];
    
    for (int i = 0; i < LEN; ++i)
        dst[i] = src[i];
}

Rotore::Rotore(const char *s, const char *d)
{
    _sx = new char[LEN];
    _dx = new char[LEN];

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