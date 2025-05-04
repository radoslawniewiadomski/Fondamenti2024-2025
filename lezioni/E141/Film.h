//L'inferfaccia e eguale a E139

class Film {
    char* _titolo;
    int _durata;
    int _anno;

public:
    Film(); //costruttore default
    Film(char* titolo, int durata, int anno);
    Film(const Film& otherFilm); //costruttore  di copia
     ~Film();
    char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getDurata() const;
    void setDurata(int durata);
    int getAnno() const;
    void setAnno(int anno);
    void stampaFilm();

};

