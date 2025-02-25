#include <iostream>
using namespace std;

//Si scriva la funzione C++ massimo che riceva come parametri i puntatori a tre numeri interi a, b e c e restituisca come valore di ritorno il puntatore al più grande dei tre numeri (un puntatore a numero intero).
//Nel caso in cui vi siano due numeri uguali, entrambi più grandi del terzo numero, la funzione restituisce il puntatore al primo dei due.
//Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione.
//Il programma chiederà all’utente di immettere da tastiera tre numeri interi, chiamerà la funzione massimo e stamperà a video il valore puntato dal puntatore che la funzione restituisce come valore di ritorno.


void swap(int* a, int* b, int* c)
{
	int tmp = *b;
	*b = *a;
	*a = *c;
	*c = tmp;
}

/*
void swap_2(int& a, int& b, int& c)
{
	int tmp = b;
	b = a;
	a = c;
	c = tmp;
}
*/

int main ()
{
	int x, y, z;
	cout << "Inserire tre numeri interi" << endl;
	cout << "Primo numero: ";
	cin >> x;
	cout << "Secondo numero: ";
	cin >> y;
	cout << "Terzo numero: ";
	cin >> z;
	cout << endl;

	swap(&x, &y, &z);

	cout << "I valori ruotati sono" << endl;
	cout << "Primo numero: " << x << endl;
	cout << "Secondo numero: " << y << endl;
	cout << "Terzo numero: " << z << endl;
	cout << endl;


	return 0;
}
