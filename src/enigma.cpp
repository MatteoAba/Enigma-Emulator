#include <iostream>
#include "struttura.h"
using namespace std;

Enigma::Enigma()
{
    for (int i = 0; i < 3; ++i) {
        _rots[i] = NULL;
        _ordine[i] = 0;
    }

    _rif = NULL;
}

