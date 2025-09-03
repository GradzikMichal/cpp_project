#include <iostream>
#include "zespolone.h"
#include "wyznacznik.h"
#include "regresja.h"
using namespace std;


int main() {
    menu:
    int x = 0;
    do {
        cout << "Witaj uzytkowniku" << endl << endl;
        cout << "Jaka czynnosc chcesz wykonac" << endl;
        cout << "1. Dzialania na liczbach zespolonych" << endl;
        cout << "2. Obliczenie rezystancji z regresji liniowej" << endl;
        cout << "3. Oblicz wyznacznik macierzy" << endl;
        cout << "40. Wyjscie z programu" << endl;
        cin >> x;
        if (!cin)
        {
            cin.clear();
            cin.ignore(100,'\n');
        }
        switch (x) {
            case 1:
                menuzes();
                cout << "Chcesz obliczyć coś jeszcze ?"<<endl;
                goto menu;
            case 2:
                menereg();
                goto menu;
            case 3:
                wyznacznik();
                goto menu;
            case 0:
                cout << "Dziekuje za skorzystanie z programu"<< endl;
                break;
            default:
                cout << "Podaj poprawny numer" << endl;
                goto menu;
        }
    }while(x<0 || x>4);
}
