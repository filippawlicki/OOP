#include "Trojkat.h"

#include <iostream>
#include <math.h>

using namespace std;

Trojkat::Trojkat(double a, double b, double c) : a(a), b(b), c(c) {
  cout << "Konstruktor Trojkata(" << a << ", " << b << ", " << c << ")" << endl;
}

double Trojkat::GetA() const {
  return a;
}

double Trojkat::GetB() const {
  return b;
}

double Trojkat::GetC() const {
  return c;
}

void Trojkat::SetA(double a) {
 this -> a = a;
}

void Trojkat::SetB(double b) {
 this -> b = b;
}

void Trojkat::SetB(double c) {
 this -> c = c;
}

double Trojkat::Obwod() {
  return a+b+c;
}

double Trojkat::Pole() {
  double p = (a+b+c)/2;
  double area = sqrt(p * (p-a) * (p - b) * (p - c));
  return area;
}

void Trojkat::Wypisz(std::ostream& out) const {
  cout << "Trojkat o bokach a = " << a << ", b = " << b << ", c = " << c << endl;
}

Trojkat::~Trojkat() {
  cout << "Destruktor Trojkata(" << a << ", " << b << ", " << c << ")" << endl;
}