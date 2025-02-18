#include <iostream>
using namespace std;
int main()

{
    int x = 1;
    int& y = x;	// y è un riferimento a x

    cout << x << endl;	// stampa 1
    cout << y << endl;	// stampa 1

    x++;
    cout << x << endl;	// stampa 2
    cout << y << endl;	// stampa 2

    y++;
    cout << x << endl;	// stampa 3
    cout << y << endl;	// stampa 3
    return 0;
}
