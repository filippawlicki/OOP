#include <iostream>
#include "Prostokat.h"
#include "Trojkat.h"
#include "Kolo.h"

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

void Funkcja2()
{
	FiguraPlaska* tab[3] = { new Prostokat(6,2), new Trojkat(12, 17, 15), new Kolo(8) };
	for(int i = 0; i < 3; i++)
	{
		cout << "Obwod figury " << i + 1 << ": " << tab[i]->Obwod() << endl;
		cout << "Pole figury " << i + 1 << ": " << tab[i]->Pole() << endl;
		delete tab[i]; // Zwolnienie pamieci
	}
	cout << endl;
}



int main(){
  // Funkcja1();
  Funkcja2();
  return 0;
}