#include <iostream>
#include <cstdlib>
#include "struttura.h"
using namespace std;

void traduzione(Enigma*);
void setting(Enigma*);
void pause();

int main()
{
    Enigma E;
    char scelta;
    bool tmp = true;

    system("CLS");
    cout << "+---------------------------------+" << endl;
    cout << "| Impostazione Iniziale di Enigma |" << endl;
    cout << "+---------------------------------+";
    setting(&E);

    while (tmp) {
        // azione
        cout << "+--+---------------------+--+" << endl; 
        cout << "|>>| EMULATORE DI ENIGMA |<<|" << endl;
        cout << "+--+---------------------+--+" << endl;
        cout << "|  1) Traduci una stringa   |" << endl;
        cout << "|  2) Setta la Macchina     |" << endl;
        cout << "|  3) Esci                  |" << endl;
        cout << "+---------------------------+" << endl;
        cout << " -> Cosa vuoi fare? : ";
        cin >> scelta;
        system("CLS");
    
        // funzioni relative
        switch (scelta) {
            case '1':
                traduzione(&E);
            break;
            
            case '2':
                setting(&E);
            break;

            case '3':
                tmp = false;
            break;

            default:
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
    printf("+---------------------------+");
    printf("\n| Traduzione di una stringa |");
    printf("\n+---------------------------+");
    printf("\n Usare:\n  -> - per inserire uno spazio\n  -> # come carattere terminatore\n");
    printf(" [ESEMPIO] FRASE-DI-PROVA#\n");
    printf("\nStringa: ");
   
    do {
        cin >> let;
        if (let == '#')
            break;
        str.push_back(let);
    } while(1);
    
    E->esecuzione(str);
    system("PAUSE");
    system("CLS");
}

void setting(Enigma *E)
{
    chiave key;

    // genero la chiave
    printf("\nInserisci l'ordine dei rotori, ES. [1 2 3] : ");
    cin >> key.ordine[0] >> key.ordine[1] >> key.ordine[2];
    printf("Inserisci le lettere di partenza, nell'ordine [RIF ROS ROC ROD] : ");
    cin >> key.letRif >> key.letRot[0] >> key.letRot[1] >> key.letRot[2]; 

    // setto Enigma e controllo lo stato
    E->setta(key);
    cout << "Impostazione Completata" << endl;
    system("PAUSE");
    system("CLS");
}

/*void pause()
{
    printf("Premi invio per continuare...");
    char tmp;
    scanf("%s", &tmp);
    printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}*/