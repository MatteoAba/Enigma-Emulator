#include <iostream>
#include "../costanti.h"
#include "../struttura.h"
using namespace std;

void testRotore()
{    
    int pos1, pos2;
    char let1, let2;

    // TEST CREAZIONE
    cout << "Che rotore usare? [1/2/3] : ";
    cin >> pos1;
    cout << "Impostare la lettera di partenza [A-Z] : "; 
    cin >> let1;
    Rotore R(ROT[--pos1], LAYOUT, let1);

    cout << "\nPROVA STAMPA ARRAY" << endl;
    R.stampaTutto();


    // TEST RICERCA DI POSIZIONE E LETTERA
    pos1 = R.trovaPos('A', dx);             
    pos2 = R.trovaPos('A', sx);

    printf("\nPosizione A in dx: %d", pos1);
    printf("\nPosizione A in sx: %d", pos2);
    
    let1 = R.trovaLet(pos1, dx);
    let2 = R.trovaLet(pos2, sx);

    printf("\nLettera a dx nella posizione %d: %c", pos1, let1);
    printf("\nLettera a sx nella posizione %d: %c", pos2, let2);

    // TEST FUNZIONAMENTO
    cout << "\n\nInserire la lettera in input al rotore: ";
    cin >> let1;
    pos1 = R.trovaPos(let1, dx);
    pos2 = R.trovaPos(let1, sx);
    pos1 = R.cambia(pos1, dx);
    pos2 = R.cambia(pos2, sx);
    cout << "Se inserita a destra uscira in posizione: " << pos1 << endl; 
    cout << "Se inserita a sinistra uscira in posizione: " << pos2 << endl;
}