#include <iostream>
using namespace std;

int main()
{
    int a =4;
    int b =8;
    int* pa=&a;
    //int* pb =&b;

    //cout<<pa<<endl;
    //cout<<pb<<endl;

    cout<<*pa<<endl; //stampa 4 sul terminale
    pa++;
    cout<<*pa<<endl; //cosa viene stampato? Perche?

    cout<<&a<<endl;

    cout<<&b<<endl;
    return 0;
}
