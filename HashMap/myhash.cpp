#include <iostream>
#include<string>
#include"myhash.h"
#include <fstream>
#include <sstream>
using namespace std;
myhash::myhash() {
for (int i=0; i<rozmTab; i++)
{
    hashTab[i]=new obiekt;
    hashTab[i]->imie="empty";
    hashTab[i]->nazwisko="empty";
    hashTab[i]->inny=NULL;


}
}
void myhash::dodajObiekt(std::string imie, std::string nazwisko)
{
    int indeks= Hash(imie);
    if(hashTab[indeks]->imie=="empty"){
        hashTab[indeks]->imie=imie;
        hashTab[indeks]->nazwisko=nazwisko;
    }
    else
    {
        obiekt* wskaznik=hashTab[indeks];
        obiekt* n=new obiekt;
        n->imie=imie;
        n->nazwisko=nazwisko;
        n->inny=NULL;
        while(wskaznik->inny !=NULL)
        {
            wskaznik=wskaznik->inny;
        }
        wskaznik->inny=n;
    }
}
int myhash::Hash(string klucz)
{
    int myhash=0;
    int indeks;//rozmiar tablicy

    for(int i=0; i<klucz.length(); i++)//dodaje wszystkie wartosci ascii do siebie
    {
        myhash=myhash+(int)klucz[i];
    }
    indeks = myhash % rozmTab; //indeksem w tablicy jest reszta z dzielenia


    return indeks;
}
void myhash::usunObiekt(string imie)
{
    int indeks = Hash(imie);

    obiekt* usunwsk;
    obiekt* w1;
    obiekt* w2;

    //przypadek 0 - kubełek jest pusty
    if(hashTab[indeks]->imie =="pusty" && hashTab[indeks]->nazwisko =="pusty")
    {
        cout << imie<< "nie ma w tablicy" <<endl;
    }
    //przypadek 1 - tylko 1 nazwisko w pudełku i ma pasujące imie
    else if(hashTab[indeks]->imie == imie && hashTab[indeks]->inny == NULL  )
    {
        hashTab[indeks]->imie = "puste";
        hashTab[indeks]->nazwisko = "puste";
        cout<<imie<<"usunięto z tablicy"<<endl;
    }
    //przypadek 2 - pierwsze nazwisko pasuje do imienia ale w kubełku sa jeszcze inne nazwiska
    else if(hashTab[indeks]->imie == imie)
    {
        usunwsk = hashTab[indeks];
        hashTab[indeks] = hashTab[indeks]->inny;
        delete usunwsk;
        cout<<imie<<"usunięto z tablicy"<<endl;
    }
    //przypadek 3 - kubełek ma kilka nazwisk ale pierwsze nie pasuje do imienia
    else
    {
        w1 = hashTab[indeks]->inny;
        w2 = hashTab[indeks];

        while(w1!=NULL && w1->imie != imie){
            w2=w1;
            w1=w2->inny;
        }
        //przpadek 3.1 - zadne nie pasuje
        if(w1==NULL)
        {
            cout << imie<< "nie ma w tablicy" <<endl;
        }
        //przypadek 3.2 - znajduje dopasowanie w ktoryms z kolejnych nazwisk
        else
        {
            usunwsk=w1;
            w1=w1->inny;
            w2->inny=w1;
            delete usunwsk;
            cout<<imie<<"usunięto z tablicy"<<endl;
        }
    }




}
void myhash::znajdzNazwisko(std::string imie)
{
    int indeks= Hash(imie);
    bool znajdzImie=false;
    string nazwisko;
    obiekt* wskaznik=hashTab[indeks];
    while(wskaznik!=NULL)
    {
        if(wskaznik->imie==imie)
        {
            znajdzImie=true;
            nazwisko=wskaznik->nazwisko;
        }
        wskaznik=wskaznik->inny;
    }
    if(znajdzImie == true)
    {
        cout<<"Nazwisko: "<<nazwisko<<endl;
    }
    else
    {
        cout<<imie<<"nie ma takiego imienia"<<endl;
    }
}



void myhash::czyscTablice() {
    for (int i = 0; i < 100000; ++i) {
        obiekt* wskaznik = hashTab[i];
        while (wskaznik != nullptr) {
            obiekt* usunwsk = wskaznik;
            wskaznik = wskaznik->inny;
            delete usunwsk;
        }
        hashTab[i] = nullptr;
    }
}

bool myhash::czyTablicaPusta() {
    for (int i = 0; i < rozmTab; i++) {
        if (hashTab[i] != nullptr) {
            return false;
        }
    }
    return true;
}

