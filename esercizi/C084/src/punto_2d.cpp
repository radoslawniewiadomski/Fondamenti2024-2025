#include "punto_2d.h"
#include <cmath>


/////////////////////////////////////////////////////////////////////
// Costruttori
/////////////////////////////////////////////////////////////////////

Punto2D::Punto2D()
: _x(0.0), _y(0.0)
{
}

Punto2D::Punto2D(double x, double y)
: _x(x), _y(y)
{
}

Punto2D::Punto2D(const Punto2D& p)
: _x(p._x), _y(p._y)
{
}


/////////////////////////////////////////////////////////////////////
// Distruttore
/////////////////////////////////////////////////////////////////////

Punto2D::~Punto2D()
{
}


/////////////////////////////////////////////////////////////////////
// Selettori
/////////////////////////////////////////////////////////////////////

double Punto2D::getX() const
{
	return _x;
}

double Punto2D::getY() const
{
	return _y;
}


/////////////////////////////////////////////////////////////////////
// Modificatori
/////////////////////////////////////////////////////////////////////

void Punto2D::setX(double x)
{
	_x = x;
}

void Punto2D::setY(double y)
{
	_y = y;
}


/////////////////////////////////////////////////////////////////////
// Operazioni
/////////////////////////////////////////////////////////////////////

double Punto2D::distanza(Punto2D p) const
{
	return sqrt((_x - p._x)*(_x - p._x) + (_y - p._y)*(_y - p._y));
}


/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati
/////////////////////////////////////////////////////////////////////

Punto2D Punto2D::operator + (Punto2D p)
{
	return Punto2D(_x + p._x, _y + p._y);
}

Punto2D Punto2D::operator - (Punto2D p)
{
	return Punto2D(_x - p._x, _y - p._y);
}

Punto2D Punto2D::operator * (double s)
{
	return Punto2D(s * _x, s * _y);
}

const Punto2D& Punto2D::operator = (const Punto2D& p)
{
	if (&p != this) {
		_x = p._x;
		_y = p._y;
	}
	return *this;
}

ostream& operator << (ostream& os, const Punto2D& p)
{
	os << "(" << p._x << "," << p._y << ")";
	return os;
}

istream& operator >> (istream& is, Punto2D& p)
{
	is >> p._x >> p._y;
	return is;
}
