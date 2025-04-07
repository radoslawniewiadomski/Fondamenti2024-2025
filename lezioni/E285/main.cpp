#include <iostream>
#include <cstring>
using namespace std;

class TestA {
public:
    TestA();  // Costruttore predefinito
    TestA(int a, const char* nome);  // Costruttore con parametro intero e nome
    TestA(const TestA& a);  // Costruttore di copia
    ~TestA();  // Distruttore

private:
    int _a;
    char* _nome;  // attributo per il nome
};

TestA::TestA() : _a(0), _nome(nullptr) { // Inizializza _nome a nullptr
    cout << "Costruttore predefinito TestA" << endl;
}

TestA::TestA(int a, const char* nome) : _a(a) {
    _nome = new char[strlen(nome) + 1];  // Alloca memoria per il nome
    strcpy(_nome, nome);  // Copia il nome
    cout << "Costruttore con parametro TestA: " << _a << ", Nome: " << _nome << endl;
}

TestA::TestA(const TestA& a) : _a(a._a) {
    _nome = new char[strlen(a._nome) + 1];  // Alloca memoria per il nome
    strcpy(_nome, a._nome);  // Copia il nome
    cout << "Costruttore di copia TestA: " << _nome << endl;
}

TestA::~TestA() {
    cout << "Distruttore TestA chiamato del: " << _nome << endl;
     delete[] _nome;  // Libera la memoria allocata per il nome
}

// Classe TestB, che contiene un oggetto di tipo TestA
//tEST B E la classe composta
class TestB {

public:
    TestB();  // Costruttore predefinito
    TestB(TestA& p, int n, const char* nome);  // Costruttore con parametro TestA, intero e nome
    TestB(const TestB& b);  // Costruttore di copia
    ~TestB();  // Distruttore

private:
    TestA _t;
    const int _c;
    char* _nome;  // attributo per il nome
};

TestB::TestB() : _t(), _c(0), _nome(nullptr) {  // Inizializza _nome a nullptr
    cout << "TestB creato con c = " << _c << endl;
}

TestB::TestB(TestA& p, int n, const char* nome) : _t(p), _c(n) {
    _nome = new char[strlen(nome) + 1];  // Alloca memoria per il nome
    strcpy(_nome, nome);  // Copia il nome
    cout << "TestB creato con c = " << _c << ", Nome: " << _nome << endl;
}

TestB::TestB(const TestB& b) : _t(b._t), _c(b._c) {
    _nome = new char[strlen(b._nome) + 1];  // Alloca memoria per il nome
    strcpy(_nome, b._nome);  // Copia il nome
    cout << "Costruttore di copia TestB: " << _nome << endl;
}

TestB::~TestB() {
    cout << "Distruttore TestB chiamato: " << _nome << endl;
        delete[] _nome;  // Libera la memoria allocata per il nome
}

int main() {
    cout << "TestA" << endl;
    TestA ta(25, "OggettoA");

    //cout << "TestB1" << endl;
    //TestB tb1;

    cout << "TestB2" << endl;
    TestB tb2(ta, 8, "OggettoB2");

    return 0;
}
