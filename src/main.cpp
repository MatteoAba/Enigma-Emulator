#include <iostream>
using namespace std;

int main()
{
    char prova = 'a';
    printf("a + 1 = %d\n", prova + 1);
    printf("a + a = %d\n", prova + 'a');

    char ris = prova + 1;
    cout << "cast implicito 'a' + 1 = " << ris;

    return 0;
}