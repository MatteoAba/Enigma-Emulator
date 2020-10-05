#include <iostream>
#include "../struttura.h"
using namespace std;

void testRiflettore()
{
    char let;
    int pos;
    
    // TEST CREAZIONE
    cout << "Impostare la lettera di partenza [A-Z] : "; 
    cin >> let;
    Riflettore R(let);

    cout << "\nPROVA STAMPA RIFLETTORE" << endl;
    R.stampaTutto();

    // TEST FUNZIONAMENTO
    cout << "\n\nInserire la lettera in input al riflettore: ";
    cin >> let;
    pos = R.trovaPos(let, dx);
    pos = R.rifletti(pos);
    let = R.trovaLet(pos, dx);
    cout << "La lettera in uscita e' " << let << " nella posizione " << pos << endl;
}