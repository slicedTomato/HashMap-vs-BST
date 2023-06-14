#include <iostream>

#include <string>
#include "myhash.h"
#include <fstream>
#include <sstream>
#include <chrono>


int main() {



    myhash hashTable;

    std::ifstream file("C:/Users/48669/Downloads/imiona-i-nazwiska.csv");
    if (!file) {
        std::cout << "Nie można otworzyć pliku." << std::endl;
        return 0;
    }

    std::string line;
    int count = 0;
    auto start = std::chrono::high_resolution_clock::now();

    while (getline(file, line)&& count < 10000) {
        std::stringstream ss(line);
        std::string imie, nazwisko;
        std::string word;

        if (getline(ss, imie, ';') && getline(ss, nazwisko, ';')) {
            hashTable.dodajObiekt(imie, nazwisko);
            count++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Dodano " << count << " obiektów do tablicy w czasie: " << duration << " ms" << std::endl;

    file.close();
    std::string imieDoWyszukania = "Rak"; // Przykładowe imię do wyszukania

    start = std::chrono::high_resolution_clock::now();

    hashTable.znajdzNazwisko(imieDoWyszukania);

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << "Czas wyszukiwania nazwiska: " << duration << " microseconds" << std::endl;

    std::string imieDoUsuniecia = "Rak"; // Przykładowe imię do usunięcia

    start = std::chrono::high_resolution_clock::now();

    hashTable.usunObiekt(imieDoUsuniecia);

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << "Czas usuwania obiektu: " << duration << " microseconds" << std::endl;

    hashTable.czyscTablice(); // Wyczyść tablicę
    if (hashTable.czyTablicaPusta()) {
        std::cout << "Tablica jest pusta." << std::endl;
    } else {
        std::cout << "Tablica nie jest pusta." << std::endl;
    }
    return 0;
}




/*using namespace std;
int main() {
    int indeks;
    myhash myhashOb;
    indeks = myhashOb.Hash("Hejo");
    cout << "indeks:" << indeks << endl;

    myhash Nowa;
    Nowa.dodajObiekt("Anna", "Nowak");
    Nowa.dodajObiekt("Jan", "Kowalski");
    Nowa.dodajObiekt("Jan", "Lal");
    string imie;

    while (imie != "exit") {
        cout << "Podaj imie: ";
        cin >> imie;
        if (imie != "exit") {
            Nowa.znajdzNazwisko(imie);
        }
    }
}*/
//while(imie!= "exit")
//{
//  cout<<"Podaj imie: ";
//cin>>imie;
//if (imie!="exit"){
//  Nowa.usunObiekt(imie);
//}
//}
//}
