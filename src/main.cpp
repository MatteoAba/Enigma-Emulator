#include <iostream>
#include "struttura.h"
using namespace std;

void traduzione(Enigma*);
void setting(Enigma*);

int main()
{
    Enigma E;
    int scelta = 4;

    cout << "+---------------------------------+" << endl;
    cout << "| Impostazione Iniziale di Enigma |" << endl;
    cout << "+---------------------------------+" << endl;
    setting(&E);

    while (scelta) {
        // azione
        cout << "+--+---------------------+--+" << endl; 
        cout << "|>>| EMULATORE DI ENIGMA |<<|"<< endl;
        cout << "+--+---------------------+--+" << endl;
        cout << "|  1) Traduci una stringa   |" << endl;
        cout << "|  2) Setta la Macchina     |" << endl;
        cout << "|  3) Esci                  |" << endl;
        cout << "+---------------------------+ " << endl;
        cout << " -> Cosa vuoi fare? : ";
        cin >> scelta;
    
        // funzioni relative
        switch (scelta) {
            case 1:
                traduzione(&E);
                break;
            
            case 2:
                setting(&E);
                break;

            case 3:
                scelta = 0;
                break;

            default:
                scelta = 4;
                cout << "Comando non valido!" << endl;
                break;
            }
    }

    return 0;
}

void traduzione(Enigma *E)
{
    char let;
    vector<char> str;
    printf("\nInserisci la stringa da tradurre. (mettere # come ultimo carattere) : ");
    
    do {
        // cin >> let;
        scanf (" %c",&let);
        if (let == '#')
            break;
        str.push_back(let);
    } while(1);
    E->esecuzione(str);
}

void setting(Enigma *E)
{
    chiave key;

    // genero la chiave
    printf("\nInserisci l'ordine dei rotori, ES. [1 2 3] : ");
    cin >> key.ordine[0] >> key.ordine[1] >> key.ordine[2];
    printf("\nInserisci le lettere di partenza, nell'ordine [RIF ROS ROC ROD] : ");
    cin >> key.letRif >> key.letRot[0] >> key.letRot[1] >> key.letRot[2]; 

    // setto Enigma e controllo lo stato
    E->setta(key);
    cout << "Impostazione Completata" << endl;
}