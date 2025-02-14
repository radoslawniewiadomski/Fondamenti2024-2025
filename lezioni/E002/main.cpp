#include <iostream>
using namespace std;

//ATTENZIONE: IL CODICE NON SI COMPILA
int main()
{
    int x = 1;
    int z = 1;

    int& y; //ERRORE

    x++;
    cout << x << endl;
    return 0;
}
