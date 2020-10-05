#include "struttura.h"

int Riflettore::rifletti(int pos)
{
    // trovo la lettera di input
    char let = trovaLet(pos, dx);

    // trovo la sua posizione nella colonna di sinistra
    pos = trovaPos(let, sx);

    // questa posizione è l'output
    return pos;
}