#include "Film.h"
#include<cstring>
#include <iostream>

using namespace std;

//L'inferfaccia e eguale a E139
//La definizione della classe Film e diversa

Film::Film() {
    _titolo = new char[20];
    strcpy(_titolo, "N/D");
    _durata = 0;
    _anno = 0;}

Film::Film(char* titolo, int durata, int anno) {
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
    _durata = durata;
    _anno = anno;}

Film::Film(const Film& otherFilm) {
    _titolo = new char[strlen(otherFilm._titolo) + 1];
    strcpy(_titolo, otherFilm._titolo);
    _durata = otherFilm._durata;
    _anno = otherFilm._anno;}

Film::~Film() {
    delete[] _titolo;}

char* Film::getTitolo() const {
    return _titolo;}


void Film::setTitolo(const char* titolo) {
    delete[] _titolo;
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);}

int Film::getDurata() const {
    return _durata;}

void Film::setDurata(int durata) {
    _durata = durata;}

int Film::getAnno() const {
    return _anno;}

void Film::setAnno(int anno) {
    _anno = anno;}


void Film::stampaFilm() {
    cout << "Title: " << _titolo << endl;
    cout << "Duration: " << _durata << endl;
    cout << "Year: " << _anno << endl;
}
