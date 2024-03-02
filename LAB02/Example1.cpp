#include <iostream>

class Vektor3d {
  double array[3]; //pole z tablicą liczb
  public:
    Vektor3d (double x1,double x2,double x3) { //konstruktor
    array[0] = x1;
    array[1] = x2;
    array[2] = x3;
  }
  const double& operator[](std::size_t i) const {
    return array[i];
  }
};

std::ostream& operator<<(std::ostream& ostr, const Vektor3d& v) {
  ostr << "Vector3d{";
  for(std::size_t i = 0; i < 3; i++){
    if(i > 0)
      ostr << ',';
    ostr << v[i];
  }
  ostr << ')';
  return ostr;
}
int main() {
  Vektor3d v1{1,2,3}; //utworzenie obiektu
  std::cout << sizeof v1 <<std::endl; // Bierze sie z tego, ze jest array 3 double'ow (double = 8 bites)

  Vektor3d v2{4,5,6}; //utworzenie obiektu
  Vektor3d v1Kopia1{v1}; //utworzenie obiektu - konstruktor kopiujący
  Vektor3d v1Kopia2 = v1; //utworzenie obiektu - konstruktor kopiujący

  std::cout << "v1: " << v1 << std::endl; // Wypisanie v1
  std::cout << "v2: " << v2 << std::endl; // Wypisanie v2
  v1 = v2; //przypisanie wartości
  std::cout << "v1: " << v1 << std::endl; // Wypisanie v1

  std::cout << "v1Kopia1: " << v1Kopia1 << std::endl; // Wypisanie v1Kopia1
  std::cout << "v1Kopia2: " << v1Kopia2 << std::endl; // Wypisanie v1Kopia2

  return 0;
}
