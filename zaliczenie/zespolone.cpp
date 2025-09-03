//
// Created by Michał on 07.06.2020.
//
#include <iostream>
#include "zespolone.h"

using namespace std;

void wstawienie(float &a, float &b, float &c, float &d) {
    cout << "Podaj czesc rzeczywista pierwszej liczby zespolonej: "<<endl;
    cin >> a;
    cout << "Podaj czesc urojona pierwszej liczby zespolonej: "<<endl;
    cin >> b;
    cout << "Podaj czesc rzeczywista drugiej liczby zespolonej: "<<endl;
    cin >> c;
    cout << "Podaj czesc urojona drugiej liczby zespolonej: "<<endl;
    cin >> d;
}

void add() {
    float a, b, c, d;
    wstawienie(a, b, c, d);
    Dzialanie *dod = new Dodawanie(a, c, b, d);
    dod->wynik();
}

void sub() {
    float a, b, c, d;
    wstawienie(a, b, c, d);
    Dzialanie *odej = new Odejmowanie(a, c, b, d);
    odej->wynik();

}

void mnozenie() {
    float a, b, c, d;
    wstawienie(a, b, c, d);
    Dzialanie *mnoz = new Mnozenie(a, c, b, d);
    mnoz->wynik();

}

void dzielenie() {
    float a, b, c, d;
    wstawienie(a, b, c, d);
    Dzialanie *dziel = new Dzielenie(a, c, b, d);
    dziel->wynik();

}

void menuzes() {
    menu:
    int x = 0;
    do {
        cout << "Jakie dzialanie chcesz wykonac" << endl;
        cout << "1. Dodawanie" << endl;
        cout << "2. Odejmowanie" << endl;
        cout << "3. Mnozenie" << endl;
        cout << "4. Dzielenie" << endl;
        cout << "5. Cofnij" << endl;
        cin >> x;
        if (!cin) {
            cin.clear();
            cin.ignore(100, '\n');
        }

        switch (x) {
            case 1:
                add();
                goto menu;
            case 2:
                sub();
                goto menu;
            case 3:
                mnozenie();
                goto menu;
            case 4:
                dzielenie();
                goto menu;
            case 5:
                break;
            default:
                cout << "Podaj poprawny numer" << endl;
                goto menu;
        }
    } while (x <= 0 || x > 5);

}
