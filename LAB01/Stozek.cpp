#define _USE_MATH_DEFINES

#include "Stozek.h"
#include "Kolo.h"

#include <iostream>
#include <math.h>

using namespace std;

Stozek::Stozek(double r, double h) : r(r), h(h) {
  cout << "Konstruktor Stozka(" << r << ", " << h << ")" << endl;
}

double Stozek::GetR() const {
  return r;
}

double Stozek::GetH() const {
  return h;
}

void Stozek::SetR(double r) {
  this -> r = r;
} 

void Stozek::SetH(double h) {
  this -> h = h;
}

double Stozek::Tworzaca() {
  return sqrt((r * r) + (h * h));
}

double Stozek::PolePowierzchniBocznej() {
  return M_PI * r * Tworzaca();
}

double Stozek::PolePowierzchniCalkowitej() {
  Kolo kolo(r);
  return PolePowierzchniBocznej() + kolo.Pole();
}

void Stozek::Wypisz(std::ostream& out) const {
  cout << "Stozek o promieniu r = " << r << " oraz wysokosci h = " << h << endl;
}

Stozek::~Stozek() {
  cout << "Destruktor Stozka(" << r << ", " << h << ")" << endl;
}