#include "Trojkat.h"

#include <iostream>

using namespace std;

Trojkat::Trojkat(double a, double b, double c) : a(a), b(b), c(c) {
  cout << "Konstruktor Trojkata(" << a << ", " << b << ", " << c << ")" << endl;
}

double Trojkat::GetA() const {
  return a;
}