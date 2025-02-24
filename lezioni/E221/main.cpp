#include <iostream>
using namespace std;

int main() {
   int* p [3];

   for (int i=0;i < 3; i++){
     int temp;
     cout<<"indirizzo di temp: "<<&temp<<endl;
     cin >> temp;
     p[i] = &temp;


   for (int i=0;i < 3; i++){
        cout << *p[i];
   }

   cout<<endl;

   for (int i=0;i < 3; i++){
        cout << p[i]<<", ";
   }

    cout<<endl;

}
