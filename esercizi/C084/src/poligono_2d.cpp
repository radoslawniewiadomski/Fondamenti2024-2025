#include "poligono_2d.h"


/////////////////////////////////////////////////////////////////////
// Costruttori
/////////////////////////////////////////////////////////////////////

Poligono2D::Poligono2D()
{
	_poligono = NULL;
	_numVertici = 0;
}

Poligono2D::Poligono2D(int numVertici)
{
	if (numVertici > 0) {
		_poligono = new Punto2D[numVertici];
		_numVertici = numVertici;
	}
	else {
		_poligono = NULL;
		_numVertici = 0;
	}
}

Poligono2D::Poligono2D(const Poligono2D& p)
{
	if (p._numVertici > 0 && p._poligono != NULL) {
		_poligono = new Punto2D[p._numVertici];
		for (int k = 0; k < p._numVertici; k++)
			_poligono[k] = p._poligono[k];
		_numVertici = p._numVertici;
	}
	else {
		_poligono = NULL;
		_numVertici = 0;
	}
}


/////////////////////////////////////////////////////////////////////
// Distruttore
/////////////////////////////////////////////////////////////////////

Poligono2D::~Poligono2D()
{
	if (_poligono != NULL) {
		delete [] _poligono;
	}
}


/////////////////////////////////////////////////////////////////////
// Operazioni
/////////////////////////////////////////////////////////////////////

int Poligono2D::GetNumVertici() const
{
	return _numVertici;
}

double Poligono2D::GetPerimetro() const
{
	double perimetro = 0.0;
	if (_poligono != NULL) {
		for (int k = 0; k < (_numVertici - 1); k++)
			perimetro += _poligono[k].distanza(_poligono[k + 1]);
		perimetro += _poligono[0].distanza(_poligono[_numVertici - 1]);
	}
	return perimetro;
}


/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati
/////////////////////////////////////////////////////////////////////

Poligono2D Poligono2D::operator * (double s)
{
	Poligono2D p(_numVertici);
	if (_poligono != NULL) {
		for (int k = 0; k < _numVertici; k++)
			p._poligono[k] = _poligono[k] * s;
	}
	return p;
}

const Poligono2D& Poligono2D::operator = (const Poligono2D& p)
{
	if (&p != this) {
		if (p._numVertici > 0 && p._poligono != NULL) {
			if (_poligono != NULL) {
				delete [] _poligono;
				_poligono = NULL;
			}
			_poligono = new Punto2D[p._numVertici];
			for (int k = 0; k < p._numVertici; k++)
				_poligono[k] = p._poligono[k];
			_numVertici = p._numVertici;
		}
		else {
			_poligono = NULL;
			_numVertici = 0;
		}
	}
	return *this;
}

Punto2D& Poligono2D::operator [] (int indice)
{
	return _poligono[indice];
}

ostream& operator << (ostream& os, const Poligono2D& p)
{
	if (p._poligono != NULL)
		for (int k = 0; k < p._numVertici; k++)
			os << p._poligono[k] << ' ';
	return os;
}

istream& operator >> (istream& is, Poligono2D& p)
{
	if (p._poligono != NULL)
		for (int k = 0; k < p._numVertici; k++)
			is >> p._poligono[k];
	return is;
}

