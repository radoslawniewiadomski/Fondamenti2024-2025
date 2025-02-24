#include <iostream>
using namespace std;

int main()
{
    int a = 11;
    int b = 12;
    int c = 13;

    int* p [3];

    cout<<&a<<", "<<&b<<", "<<&c<<", "<<endl;

    p[0] =&a;
    p[1] =&b;
    p[2] =&c;

/*

    //cambiare tree valori
    for (int i=0; i < 3; i++)
    {
        ( *p[i]        )++;
    }

*/

     //errore
     for (int i=0;i < 3; i++){
         *p[i]++;
     }


    //STAMPARE  3 VALORI
    for (int i=0; i < 3; i++)
    {
        cout<< *p[i]  <<", ";
    }

    cout <<endl;

    //stampare 3 indirizzi
    for (int i=0; i < 3; i++)
    {
        cout<< p[i] <<", ";
    }

}
