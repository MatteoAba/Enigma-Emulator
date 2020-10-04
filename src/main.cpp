#include <iostream>
#include "costanti.h"
#include "struttura.h"
using namespace std;

int main()
{
    Rotore R(RotI, LAYOUT);

    int pos1 = R.trovaPos('A', dx);
    int pos2 = R.trovaPos('A', sx);

    printf("Posizione A in dx: %d", pos1);
    printf("\nPosizione A in sx: %d", pos2);

    pos1 = 9;                                       // DEBUG
    pos2 = 0;                                       // DEBUG
    
    char let1 = R.trovaLet(pos1, dx);
    char let2 = R.trovaLet(pos1, sx);

    printf("\nLettera a dx nella posizione %d: %c", pos1, let1);
    printf("\nLettera a sx nella posizione %d: %c", pos2, let2);
    
    return 0;
}