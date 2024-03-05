#include <initializer_list>
#include <iostream>

class Vector {
  double* array;
  std::size_t size;
  public:
    //Parametr typu std::initializer_list pozwoli na uruchomienie
    //konstruktora z dowolną liczbą wystąpień liczb typu double.
    // Będzie to wyglądało jak inicjalizacja tablicy. Przykład:
    //Vector v1({1,2,3,4,5,5.5});
    //lub
    //Vector v1{1,2,3,4,5,5.5};
    //lub
    //Vector v1 = {1,2,3,4,5,5.5};
    //Jest to cecha C++11
    Vector(std::initializer_list<double> initList) : size{initList.size()}, array{new double[initList.size()]} {
      std::size_t i = 0;
      for(double v : initList) {
        array[i] = v;
        i++;
      }
    }

    Vector(const Vector& other) : size(other.size), array{new double[other.size]} { // Kontruktor kopiujacy
      std::cout << "Vector(const Vector&)" << std::endl; //Informacja diagnostyczna
      for(std::size_t i=0; i < size; i++)
        array[i] = other.array[i];
    }

    //Implementacja operatora przypisania z wykorzystaniem copy-swap
    Vector& operator=(const Vector& right) {
      std::cout << "operator=(const Vector&)" << std::endl; //Informacja diagnostyczna
      Vector tmp = right; //Tworzenie obiektu tymczasowego
      std::swap(array,tmp.array); //Zamiana wskaźników na tablice miejscami
      std::swap(size,tmp.size); //Zamiana informacji o wielkości tablicy
      return *this;
    }
    //Po wyjściu z ciała operatora obiekt tmp jest niszczony
    //a wraz z nim stara zawartość obiektu głównego

    std::size_t GetSize() const {
      return size;
    }
    const double& operator[](std::size_t i) const {
      return array[i];
    }
    double& operator[](std::size_t i) {
    return array[i];
    }

    ~Vector() {
      std::cout << "~Vector()" << std::endl; //Informacja diagnostyczna
      if(array != nullptr) {
        std::cout << "Releasing memory " << array << std::endl;
        delete[] array;
      }
    }
};
std::ostream& operator<<(std::ostream& ostr, const Vector& v){
  ostr << "Vector{";
  for(std::size_t i = 0; i < v.GetSize(); i++) {
    if(i > 0)
      ostr << ',';
    ostr << v[i];
  }
  ostr << '}';
  return ostr;
}

void wypisz1(Vector v) {
  std::cout << v << std::endl;
}
void wypisz2(Vector& v) {
  std::cout << v << std::endl;
}

int main(int argc, char** argv) {
  std::cout << "Przyklad 4 (w instrukcji):" << std::endl;

  Vector v1 = {1,2,3,4,5,5.5};
  std::cout << "v1: " << v1 << std::endl;
  Vector v2 = {5.5,4,3,2,1};
  std::cout << "v2: " << v2 << std::endl;
  v1 = v2; //To już nie jest kłopotliwe przypisanie
  std::cout << "v1: " << v1 << std::endl;
  std::cout << "v2: " << v2 << std::endl;
  v1[0] = 100.0; //Ustawienie wartości w obiekcie v1
  std::cout << "v1: " << v1 << std::endl;
  std::cout << "v2: " << v2 << std::endl;

  std::cout << "Przyklad 5 (w instrukcji):" << std::endl;

  Vector v = {1,2,3};
  std::cout << "Test wypisz1" << std::endl;
  wypisz1(v);
  std::cout << "Koniec testu wypisz1" << std::endl;

  std::cout << "Test wypisz2" << std::endl;
  wypisz2(v);
  std::cout << "Koniec testu wypisz2" << std::endl;
  return 0;
}