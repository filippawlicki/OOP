#include "Book.h"
#include "Library.h"

#include <iostream>
#include <string>

int main(){
  std::cout << "FIRST EXERCISE" << std::endl;
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
  std::cout << "SECOND EXERCISE" << std::endl;
  Library g;
  std::cout << "g: "<< g << std::endl;
  Library l1 = {{"Harry Potter", "J. K. Rowling"},
  {"Potop", "Sienkiewicz"},
  {"Rich Dad, Poor Dad", "Kiyosaki"}};
  std::cout << "l1: "<< l1 << std::endl;
  Library l2({Book(), Book()});
  std::cout << "l2: "<< l2 << std::endl;
  l2[0] = {"Hobbit", "Tolkien"};
  l2[1] = {"Jak to wyjasnic?", "Pitala"};
  std::cout << "l2: "<< l2 << std::endl;
  g = std::move(l2);
  std::cout << "g: " << g << " l2: "<< l2 << std::endl;
  l1[0] = std::move(g[1]);
  std::cout << "l1: " << l1 << " g: "<< g << std::endl;
  return 0;
}