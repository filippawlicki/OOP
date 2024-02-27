#include <iostream>
#include "Prostokat.h"

using namespace std;

void Funkcja1(){
  Prostokat prost(2, 8); // Konstruktor
  cout << "Prostokat (zmienna lokalna): " << prost << endl;
  cout << "Pole: " << prost.Pole() << endl;
  cout << "Obwod: " << prost.Obwod() << endl;
  // Setery
  prost.SetA(5);
  prost.SetB(8);
  cout << "Po uzyciu seterow: " << prost << endl;
  // Uzycie geterow
  cout << "a = " << prost.GetA() << ", b = " << prost.GetB() << endl;

  Prostokat* prostWsk = new Prostokat(5, 7);
  cout << "Prostokat (wskaznikiem): " << *prostWsk << endl;
  cout << "Pole: " << prostWsk->Pole() << endl;
  cout << "Obwod: " << prostWsk->Obwod() << endl;
  delete prostWsk; // Zwolnienie pamieci
}

int main(){
  Funkcja1();
  return 0;
}