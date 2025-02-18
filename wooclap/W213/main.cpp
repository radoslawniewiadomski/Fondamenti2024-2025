#include <iostream>
using namespace std;

void scambia(int &n, int &m)
{
    int t;
    t = n;
    n = m;
    m = t;
}

int  main() {
    int a=1;
    int b=2;

    int* p1=&a;
    int* p2=&b;
    int** pp;
    pp = &p1;

    scambia (*p1,*p2);
    cout<<*p1<<","<<**pp;
}

