#include <iostream>
using namespace std;
int main()
{
    double x=0.9, y=0.5, z=0.1;

    double* p1=&x;
    double* p2=&y;
    double* p3=&z;

    double** pp;

    pp = &p1;

    p2 = p3;
    p1 = p2;

    cout << **pp;
    return 0;
}
