#include "Prostopadl.h"
#include "Prostokat.h"

#include <iostream>

using namespace std;

Prostopadl::Prostopadl(double a, double b, double h): a(a), b(b), h(h) {
    cout << "Konstruktor Prostopadloscianu(" << a << ", " << b << ", " << h << ")" << endl;
    cout << "Pole Calkowite (" << a << ", " << b << ", " << h << "): " << PolePowierzchniCalkowitej() << endl;
    cout << "Pole Boczne (" << a << ", " << b << ", " << h << "): " << PolePowierzchniCalkowitej() << endl;
}

Prostopadl::Prostopadl(double a): a(a), b(a), h(a) {
    cout << "Konstruktor Prostopadloscianu(" << a << ", " << b << ", " << h << ")" << endl;
    cout << "Pole Calkowite Szescianu (" << a << ", " << b << ", " << h << "): " << PolePowierzchniCalkowitej() << endl;
    cout << "Pole Boczne Szescianu (" << a << ", " << b << ", " << h << "): " << PolePowierzchniCalkowitej() << endl;
}

Prostopadl::Prostopadl(): a(1), b(1), h(1) {
    cout << "Konstruktor Prostopadloscianu(" << a << ", " << b << ", " << h << ")" << endl;
    cout << "Pole Calkowite Szescianu(1) (" << a << ", " << b << ", " << h << "): " << PolePowierzchniCalkowitej() << endl;
    cout << "Pole Boczne Szescianu(1) (" << a << ", " << b << ", " << h << "): " << PolePowierzchniCalkowitej() << endl;
}

double Prostopadl::GetA() const {
    return a;
}

double Prostopadl::GetB() const {
    return b;
}

double Prostopadl::GetH() const {
    return h;
}

void Prostopadl::SetA(double a) {
    this -> a = a;
}


void Prostopadl::SetB(double b) {
    this -> b = b;
}


void Prostopadl::SetH(double h) {
    this -> h = h;
}

double Prostopadl::PolePowierzchniBocznej() {
    Prostokat bokA(a , h);
    Prostokat bokB(b, h);
    return bokA.Pole() * 2 + bokB.Pole() * 2;
}

double Prostopadl::PolePowierzchniCalkowitej() {
    Prostokat bokA(a , h);
    Prostokat bokB(b, h);
    Prostokat podstawa(a, b);
    return bokA.Pole() * 2 + bokB.Pole() * 2 + podstawa.Pole() * 2;
}

void Prostopadl::Wypisz(std::ostream& out) const {
    cout << "Prostopadloscian o bokach a = " << a << ", b = " << b << ", h = " << h << endl;
}

Prostopadl::~Prostopadl() {
    cout << "Destruktor Prostopadloscianu(" << a << ", " << b << ", " << h << ")" << endl;
}

