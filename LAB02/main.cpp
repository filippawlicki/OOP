#include "Book.h"

#include <iostream>
#include <string>

int main(){
  std::string a="Sapkowski", t="Wiedzmin";
  Book e;
  std::cout << "e: "<< e << std::endl;
  Book b1 = {a, t};
  std::cout << "b1: "<< b1 << std::endl;
  Book b2 = {"Mroz","Precedens"};
  std::cout << "b2: "<< b2 << std::endl;
  Book b3 = b1;
  std::cout << "b3: "<< b3 << " b1: " << b1 << std::endl;
  e = std::move(b2);
  std::cout << "e: "<< e << " b2:" << b2 << std::endl;
  e.SetAuthor("Remigiusz Mroz");
  std::cout << "e: "<< e << std::endl;
  e.SetTitle("Precedens - Chylka");
  std::cout << "e: "<< e << std::endl;

  return 0;
}