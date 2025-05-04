#include <iostream>
using namespace std;

class TestA
{
public:

    TestA() : _a(0) {} // Costruttore predefinito

    TestA(int a) : _a(a) {} // Costruttore con parametro intero

   TestA(const TestA& a) : _a(a._a)
    {
        cout<<"costruttore di copia: "<<_a<<endl;
    } // Costruttore di copia


private:
    int _a;
};


//classe composta: uno dei suoi attributti è un oggetto di classe TestA
class TestB
{
public:
    TestB();
    TestB(TestA& p, int n);

private:
    TestA _t;
    const int _c;
};


TestB::TestB() : _t(), _c(0) // Costruttore predefinito
{
    cout<<"Test B created with c= "<<_c<<endl;
}

TestB::TestB(TestA& p, int n)
    : _t(p), _c(n)
{
    cout<<"Test B created with c= "<<_c<<endl;
} // Costruttore con parametro

int main()
{
    cout <<"TestA"<<endl;

    TestA ta(25);

    //cout <<"TestB1"<<endl;

    //TestB tb1;

    cout <<"TestB2"<<endl;
    TestB tb2(ta, 8);

    return 0;
}
