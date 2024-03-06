#include "Library.h"
#include "Book.h"

#include <initializer_list>
#include <iostream>

Library::Library() : size(0), array{new Book[0]} {
  std::cout << "Constructor without parameters" << std::endl;
}

Library::Library(std::initializer_list<Book> list) : size(list.size()), array{new Book[list.size()]} {
  std::cout << "Constructor with init list" << std::endl;
  std::size_t i = 0;
  for(Book b : list) {
    array[i] = b;
    i++;
  }
}

Library::Library(const Library& orig) : size(orig.size), array{new Book[orig.size]} {
  std::cout << "Copy constructor" << std::endl;
  for(std::size_t i = 0; i < size; i++) {
    array[i] = orig.array[i];
  }
}

Library::Library(Library&& orig) : size(orig.size), array{new Book[orig.size]} {
  std::cout << "Transfering constructor" << std::endl;
  for(std::size_t i = 0; i < size; i++) {
    array[i] = orig.array[i];
  }
  orig.array = nullptr;
}

Library& Library::operator=(const Library& right) {
  std::cout << "Assignment operator with lvalue reference (copy)" << std::endl;
  Library tmp = right;
  std::swap(array, tmp.array);
  std::swap(size, tmp.size);
  return *this;
}

Library& Library::operator=(Library&& right) {
  std::cout << "Assignment operator with rvalue reference (transfer)" << std::endl;
  std::swap(array, right.array);
  std::swap(size, right.size);
  return *this;
}

const Book& Library::operator[](std::size_t index) const {
  return array[index];
}

Book& Library::operator[](std::size_t index) {
  return array[index];
}

Library::~Library() {
  std::cout << "~Library" << std::endl;
  if(array != nullptr) {
    delete[] array;
  }
}

std::size_t Library::GetSize() const {
  return size;
}

std::ostream& operator<<(std::ostream& ostr, const Library& library) {
  ostr << "Library: " << std::endl;
  for(size_t i = 0; i < library.GetSize(); i++) {
    ostr << library[i] << std::endl;
  }
  ostr << "End of library";
  return ostr;
}


