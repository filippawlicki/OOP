#include <iostream>
#include "Prostokat.h"
#include "Trojkat.h"
#include "Kolo.h"
#include "Stozek.h"

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
} // Destruktor prost uruchamia sie po wyjsciu z funkcji

void Funkcja2(){ // Wirtualne bo sa nadpisywane
	FiguraPlaska* tab[3] = { new Prostokat(6,2), new Trojkat(12, 17, 15), new Kolo(8) };
	for(int i = 0; i < 3; i++)
	{
		cout << "Obwod " << i + 1 << ": " << tab[i]->Obwod() << endl; // jakby nie byly wirtualne
		cout << "Pole " << i + 1 << ": " << tab[i]->Pole() << endl; // to zostalaby uruchomione metody dla FiguraPlaska
		delete tab[i]; // Zwolnienie pamieci
	}
	cout << endl;
}

int Funkcja3(int x, int y){ // overloading
  return x + y;
}

int Funkcja3(int x, int y, int z){ // overloading
  return x + y + z;
}
// overriding jest uzywany w kazdej figurze w funkcji wypisz -> nadpisuje metode

void FunckjaLAB(){
  Stozek stozek(1, 3);
  Stozek* stozekWsk = new Stozek(5, 6);
  cout << "Tworzaca Stozka(1, 3): " << stozek.Tworzaca() << endl;
  cout << "Pole Powierzchni Boczenej Stozka(5, 6): " << stozekWsk->PolePowierzchniBocznej() << endl;
  cout << "Pole Powierzchni Calkowitej Stozka(5, 6): " << stozekWsk->PolePowierzchniCalkowitej() << endl;
  delete stozekWsk;
}


int main(){
  //Funkcja1();
  //Funkcja2();
  //cout << "Podpunkt 3, pierwsze wyjscie: " << Funkcja3(1, 2) << endl;
  //cout << "Podpunkt 3, drugie wyjscie: " << Funkcja3(1, 2, 3) << endl;
  FunckjaLAB();
  return 0;
}