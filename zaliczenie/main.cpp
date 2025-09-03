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
        // cout << "2. Obliczenie rezystancji rezystora, cewki lub kondensatora (prad staly lub zmienny)" << endl;
        cout << "3. Obliczenie rezystancji z regresji liniowej" << endl;
        //  cout << "4. Obliczenie rezystancji zastepczej w oczku" << endl;
        cout << "5. Oblicz wyznacznik macierzy" << endl;
        cout << "0. Wyjscie z programu" << endl;
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
                cout <<"rezystor";
                goto menu;
            case 3:
                menereg();
                goto menu;
            case 4:
                cout<<"zastepcza";
                goto menu;
            case 5:
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
