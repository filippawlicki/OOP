#define _USE_MATH_DEFINES

#include "Kolo.h"

#include <iostream>
#include <math.h>

using namespace std;

Kolo::Kolo(double r) : r(r) {
  cout << "Kontruktor Kola(" << r << ")" << endl;
}

double Kolo::GetR() const {
  return r;
}

void Kolo::SetR(double r) {
  this -> r = r;
}

double Kolo::Obwod() {
  return M_PI * 2 * r;
}

double Kolo::Pole() {
  return M_PI * (r * r);
}

void Kolo::Wypisz(std::ostream& out) const {
  cout << "Kolo o promieniu r =" << r << endl;
}

Kolo::~Kolo() {
  cout << "Destruktor Kola(" << r << ")" << endl;
}