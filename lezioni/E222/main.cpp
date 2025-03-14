#include <iostream>
using namespace std;

int a=0;
int b=0;
float f=0;

int add3(){
    return 3;
}

int main()
{
    int c=0;
    int d=0;
    float g=0;

    int *p = new int;
    int *q = new int;
    float *r = new float;

    cout<<"variabili globali"   <<endl;
    cout<<&a<<endl;
    cout<<&b<<endl;
    cout<<&f<<endl;

    cout<<"variabili locali"   <<endl;
    cout<<&c<<endl;
    cout<<&d<<endl;
    cout<<&g<<endl;

    cout<<"allocazione dinamica "   <<endl;
    cout<<p<<endl;
    cout<<q<<endl;
    cout<<r<<endl;

    cout<<"altre variabili locali"   <<endl;
    cout<<&p<<endl;
    cout<<&q<<endl;
    cout<<&r<<endl;

/*
    cout<<"funzioni"<<endl;
    int (*pf)() = add3;
    cout<<(void*)pf<<endl;
    pf = main;
    cout<<(void*)pf<<endl;
*/

    return 0;
}
