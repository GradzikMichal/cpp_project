//
// Created by Michał on 10.06.2020.
//
#include <iostream>
#include <cmath>
#include "wyznacznik.h"

using namespace std;
int x = 0;
float oblicz(float **a, int w) {
    float wynik = 0;
    float czastk = 0;
    if (w == 1) {
        cout << "wyznacznik macierzy to: " << a[0][0] << endl;
        return a[0][0];
    } else if (w == 2) {
        czastk = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
        cout << "Wyznacznik macierzy to: " << czastk << endl;
        return czastk;
    } else if (w == 3) {
        czastk = (a[0][0] * a[1][1] * a[2][2]) + (a[0][1] * a[1][2] * a[2][0]) + (a[0][2] * a[1][0] * a[2][1]) -
                 (a[0][2] * a[1][1] * a[2][0]) - (a[0][1] * a[1][0] * a[2][2]) - (a[0][0] * a[1][2] * a[2][1]);
        return czastk;
    } else {
        for (int i = 0; i < w; i++) {
            float **macierz2 = new float *[w - 1];
            for (int q = 0; q < w; q++) {
                macierz2[q] = new float[w - 1];
            }
            for (int k = 0; k < w - 1; k++) {
                for (int e = 0; e < i; e++) {
                    macierz2[k][e] = a[k + 1][e];
                }
                for (int f = i; f < w - 1; f++) {
                    macierz2[k][f] = a[k + 1][f + 1];
                }
            }
            wynik += pow((-1), i) * a[0][i] * oblicz(macierz2, w - 1);
        }
    }
    return wynik;
}
void wyznacznik() {
    cout << "Program do liczenia wyznacznika macierzy rzeczywistych" << endl;
    poczatek:
    cout << "Pamietaj ze macierz musi byc kwadratowa!!" << endl << endl;
    do {
        cout << "Podaj ilosc wierszy albo kolumn macierzy" << endl;
        cin >> x;
        if (!cin) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Podaj poprwana ilosc wierszy/kolumn" << endl;
        }
    } while (x <= 0);
    float **macierz = new float *[x];
    for (int i = 0; i < x; i++) {
        macierz[i] = new float[x];
    }
    for (int j = 0; j < x; j++) {
        for (int i = 0; i < x; i++) {
            cout << "Podaj " << i + 1 << " wyraz w wierszu nr " << j + 1 << endl;
            cin >> macierz[j][i];
        }
    }
    cout << endl << "Twoja macierz to: " << endl;
    for (int j = 0; j < x; j++) {
        for (int i = 0; i < x; i++) {
            cout << "|" << macierz[j][i];
            if (i == x - 1) {
                cout << "|";
                cout << endl;
            }
        }
    }
    cout << "Wyznacznik macierzy to: " << oblicz(macierz, x) << endl;
    int y = 0;
    delete[] macierz;
    do {
        cout << "Chcesz obliczyc jeszcze jedna macierz ?" << endl;
        cout << "1. Licz jeszcze jedna macierz!!!" << endl;
        cout << "2. Powrot do menu glownego" << endl;
        cin >> y;
        if (!cin) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Podaj poprwana wybor" << endl << endl;
        }
        switch (y) {
            case 1:
                goto poczatek;
            case 2:
                break;
        }
    } while (y != 1 && y != 2);
}