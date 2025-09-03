//
// Created by Michał on 07.06.2020.
//

#ifndef PROJEKTZAL_ZESPOLONE_H
#define PROJEKTZAL_ZESPOLONE_H

#include <iostream>
#include <math.h>

using namespace std;

void menuzes();

class Dzialanie {
public:
    virtual float wynik() = 0;
};

class Dodawanie : public Dzialanie {
    float rzecz1, rzecz2, rzeczw, uroj1, uroj2, urojw;
public:
    Dodawanie(float a, float b, float c, float d) : rzecz1(a), rzecz2(b), uroj1(c), uroj2(d) {};

    float wynik() {
        rzeczw = rzecz1 + rzecz2;
        urojw = uroj1 + uroj2;
        if (urojw >= 0) {
            cout << rzeczw << " + i " << urojw<<endl;
        } else if (urojw < 0) {
            urojw = abs(urojw);
            cout << rzeczw << " - i " << urojw<<endl;
        } else {
            cout << rzeczw<<endl;
        }
        return 0;
    }
};

class Odejmowanie : public Dzialanie {
    float rzecz1, rzecz2, rzeczw, uroj1, uroj2, urojw;
public:
    Odejmowanie(float a, float b, float c, float d) : rzecz1(a), rzecz2(b), uroj1(c), uroj2(d) {};

    float wynik() {
        rzeczw = rzecz1 - rzecz2;
        urojw = uroj1 - uroj2;
        if (urojw >= 0) {
            cout << rzeczw << " + i " << urojw<<endl;
        } else if (urojw < 0) {
            urojw = abs(urojw);
            cout << rzeczw << " - i " << urojw<<endl;
        } else {
            cout << rzeczw<<endl;
        }
        return 0;
    }

};

class Mnozenie : public Dzialanie {
    float rzecz1, rzecz2, rzeczw, uroj1, uroj2, urojw;
public:
    Mnozenie(float a, float b, float c, float d) : rzecz1(a), rzecz2(b), uroj1(c), uroj2(d) {};

    float wynik() {
        rzeczw = (rzecz1 * rzecz2) + ((-1) * uroj1 * uroj2);
        urojw = (rzecz1 * uroj2) + (rzecz2 * uroj1);
        if (urojw >= 0) {
            cout << rzeczw << " + i " << urojw<<endl;
        } else if (urojw < 0) {
            urojw = abs(urojw);
            cout << rzeczw << " - i " << urojw<<endl;
        } else {
            cout << rzeczw<<endl;
        }
        return 0;
    }
};

class Dzielenie : public Dzialanie {
    float rzecz1, rzecz2, rzeczw, uroj1, uroj2, urojw;
public:
    Dzielenie(float a, float b, float c, float d) : rzecz1(a), rzecz2(b), uroj1(c), uroj2(d) {};

    float wynik() {

        rzeczw = ((rzecz1 * rzecz2) + (uroj1 * uroj2)) / (pow(rzecz2, 2) + pow(uroj2, 2));
        urojw = (((-1) * rzecz1 * uroj2) + (rzecz2 * uroj1)) / (pow(rzecz2, 2) + pow(uroj2, 2));
        if (urojw > 0) {
            cout << rzeczw << " + i " << urojw<<endl;
        } else if (urojw < 0) {
            urojw = abs(urojw);
            cout << rzeczw << " - i " << urojw<<endl;
        } else {
            cout << rzeczw<<endl;
        }

        return 0;
    }
};

#endif //PROJEKTZAL_ZESPOLONE_H
