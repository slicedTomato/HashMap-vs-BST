#include <iostream>
#include <cstdlib>
#include<string>

using namespace std;

class myhash{
private:
    static const int rozmTab=10000;
    struct obiekt{
        string imie;
        string nazwisko;
        obiekt*inny;
    };
    obiekt* hashTab[rozmTab];
public:
    myhash();
    int Hash(string klucz);//funkcja pobierająca string i zamienia go na numer indeksu w tablicy
    void dodajObiekt(string imie, string nazwisko);
    void znajdzNazwisko(string imie);
    void usunObiekt(string imie);

    void czyscTablice();

    bool czyTablicaPusta();
};


