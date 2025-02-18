#include <iostream>
using namespace std;

//ATTENZIONE QUESTO CODICE E SBAGLIATO!!

int main(){
    int a = 3;
    int* p1 = &a;
    int** p2 = &p1;


    int aa[3]={1,2,3};


    cout << aa << endl;

    return 0;
}
