#include <iostream>
#include "..\struttura.h"
using namespace std;

void testEnigma()
{
    Enigma E;
    chiave key;

    // genero la chiave
    printf("\nInserisci l'ordine dei rotori, ES. [1 2 3] : ");
    cin >> key.ordine[0] >> key.ordine[1] >> key.ordine[2];
    printf("\nInserisci le lettere di partenza, nell'ordine [RIF ROS ROC ROD] : ");
    cin >> key.letRif >> key.letRot[0] >> key.letRot[1] >> key.letRot[2]; 

    // setto Enigma e controllo lo stato
    E.setta(key);
    // E.stampaStato();

    // faccio una traduzione
    char str[2];
    printf("\nInserisci tre caratteri da tradurre. [A-Z A-Z A-Z] : ");
    cin >> str[0] >> str[1] >> str[2];
    E.esecuzione(str);
    // E.stampaStato();
}