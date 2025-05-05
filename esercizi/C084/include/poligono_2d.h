#ifndef __POLIGONO_2D_H__
#define __POLIGONO_2D_H__


#include "punto_2D.h"
#include <iostream>

using namespace std;


class Poligono2D
{
public:

	// Costruttori
	Poligono2D(int numVertici);
	Poligono2D(const Poligono2D& p);

	// Distruttore
	~Poligono2D();

	// Operazioni
	int GetNumVertici() const;
	double GetPerimetro() const;

	// Operatori sovraccaricati
	Poligono2D operator * (double s);
	const Poligono2D& operator = (const Poligono2D& p);
	Punto2D& operator [] (int indice);
	friend ostream& operator << (ostream& os, const Poligono2D& p);
	friend istream& operator >> (istream& is, Poligono2D& p);

protected:

	// Costruttore di default
	Poligono2D();

private:
	Punto2D* _poligono;
	int _numVertici;
};


#endif
