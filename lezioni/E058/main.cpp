#include <iostream>
using namespace std;

void incrp(int* p, int n)
{
    *p = *p + n;
}


void incrr(int& p, int n)
{
    p = p + n;
}


int main()
{
    int a = 10;

    incrr(a, 3);
    cout<<a<<endl;


    incrp(&a, 2);
    cout<<a<<endl;


    return 0;
}
