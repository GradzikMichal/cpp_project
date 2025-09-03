//
// Created by Michał on 12.06.2020.
//
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;
int i = 0;

float *wczytaj(string &sciezka, int &lines) {
    string line;
    ifstream file(sciezka);
    while (getline(file, line))i++;
    lines = i;
    file.clear();
    file.seekg(0, ios::beg);
    auto tab = new float[i * 2];
    int pos = 0;
    for (int k = 0; k < lines; k++) {
        getline(file, line);
        int delim = line.find("\t");
        string sub1 = line.substr(0, delim);
        int comma = sub1.find(',');
        sub1.replace(comma, 1, ".");
        string sub2 = line.substr(delim + 1);
        comma = sub2.find(',');
        sub2.replace(comma, 1, ".");
        float value1 = stof(sub1);
        float value2 = stof(sub2);
        tab[pos] = value1;
        tab[pos + 1] = value2;
        pos += 2;

    }
    lines *= 2;
    return tab;
}

float regresja(float *tab, int kol) {
    float sumaI = 0;
    float sumaU = 0;
    float averageI = 0;
    float averageU = 0;
    int c = kol - 1;
    if (c == 0) {
        for (int j = 0; j < i * 2; j += 2) {
            sumaI += tab[j];
            sumaU += tab[j + 1];
        }
    } else {
        for (int j = 0; j < i * 2; j += 2) {
            sumaI += tab[j + 1];
            sumaU += tab[j];
        }
    }
    cout << sumaI << endl;
    cout << sumaU << endl;
    averageI = (sumaI / i);
    averageU = (sumaU / i);

    float licznik = 0;
    float mianownik = 0;
    for (int j = 0; j <= i; j += 2) {
        licznik += (tab[j] - averageU) * (tab[j + 1] - averageI);
    }
    cout << licznik << endl;
    for (int j = 0; j <= i; j += 2) {
        mianownik += pow((tab[j] - averageU), 2);
    }
    cout << mianownik << endl;
    float a = (licznik / mianownik);
    float rez = (1 / a) * 1000;
    return rez;
}

//C:\Users\Michal\Desktop\Zeszyt1.txt
void menereg() {
    string x = "";
    int number = 0;
    cout << "Podaj sciezke do pliku: " << endl;
    cin >> x;
    float *tab = wczytaj(x, number);
    cout << "Podaj w ktorej kolumnie znajduje sie natezenie pradu I: " << endl;
    cin >> number;
    int rez = regresja(tab, number);
    cout << "Rezystancja opornika w zaokragleniu wynosi: " << rez << endl;
}



