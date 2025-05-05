#ifndef __PUNTO2D_H__
#define __PUNTO2D_H__


#include <iostream>

using namespace std;


class Punto2D {

public:

	// Costruttori
	Punto2D();
	Punto2D(double x, double y);
	Punto2D(const Punto2D& p);

	// Distruttore
	~Punto2D();

	// Selettori
	double getX() const;
	double getY() const;

	// Modificatori
	void setX(double x);
	void setY(double x);

	// Operazioni
	double distanza(Punto2D p) const;

	// Operatori sovraccaricati
	Punto2D operator + (Punto2D p);
	Punto2D operator - (Punto2D p);
	Punto2D operator * (double s);

	const Punto2D& operator = (const Punto2D& p);
	friend ostream& operator << (ostream& os, const Punto2D& p);
	friend istream& operator >> (istream& is, Punto2D& p);

private:
	double _x;
	double _y;
};


#endif
