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
    ostr << i << ". " << library[i] << std::endl;
  }
  ostr << "End of library";
  return ostr;
}

void Library::AddNewBook(){
  std::string a, t;
	std::cout << "Podaj autora ksiazki ktora chcesz dodac: ";
	std::cin >> a;
	std::cout << "Podaj tytul ksiazki ktora chcesz dodac: ";
	std::cin >> t;

	size++;
	Book* tab2 = new Book[size];

	for (int i = 0; i < size - 1; i++)
	{
		tab2[i].SetAuthor(array[i].GetAuthor());
    tab2[i].SetTitle(array[i].GetTitle());
	}

	tab2[size - 1].SetAuthor(a);
	tab2[size - 1].SetTitle(t);

	std::swap(tab2, array);

	delete[] tab2;
}

void Library::ShowBooksByAuthor(){
  std::string autor;
	std::cout << "Wpisz autora: ";
	std::cin >> autor;
	std::cout << std::endl;
	bool znaleziono = false;
	for (size_t i = 0; i < size; i++)
	{
		if (array[i].GetAuthor() == autor)
		{
			znaleziono = true;
			std::cout << "Tytul ksiazki tego autora: " << array[i].GetTitle() << "." << std::endl;
		}
	}
	if (!znaleziono)
	{
		std::cout << "Nie ma zadnej ksiazki tego autora." << std::endl;
	}
}

void Library::DeleteBook(){
  int index;
  std::cout << "Podaj indeks ksiazki: ";
  std::cin >> index;
  if(index >= 0 && index < size){
    //std::cout << size << "ROZMIAR" << std::endl;
    size--;
    //std::cout << size << "ROZMIAR PO USUNIECIU" << std::endl;
	  Book* tab2 = new Book[size];
    for (int i = 0; i < size; i++) {
      if(i < index){
        tab2[i].SetAuthor(array[i].GetAuthor());
        tab2[i].SetTitle(array[i].GetTitle());
      } else if(i >= index){
        tab2[i].SetAuthor(array[i+1].GetAuthor());
        tab2[i].SetTitle(array[i+1].GetTitle());
      }
    }

    std::swap(tab2, array);

    delete[] tab2;
  }else{
    std::cout << "Nie ma takiej ksiazki" << std::endl;
  }
}


void Library::CreateChapters(){
  int index;
  std::cout << "Podaj indeks ksiazki: ";
  std::cin >> index;
  if(index >= 0 && index < size){
    for(int i = 0; i < 3; i++){
      std::string chapter;
      std::cout << "Wpisz nazwe rodzialu nr" << i+1 << std::endl;
      std::cin >> chapter;
      array[index].SetChapter(i, chapter);
    }
  } else {
    std::cout << "Nie ma takiej ksiazki" << std::endl;
  }
}

void Library::ShowChapters(){
  int index;
  std::cout << "Podaj indeks ksiazki: ";
  std::cin >> index;
  if(index >= 0 && index < size){
    for(int i = 0; i < 3; i++){
      std::cout << "Rodzial nr " << i+1 << ": " << array[index].GetChapter(i) << std::endl;
    }
  } else {
    std::cout << "Nie ma takiej ksiazki" << std::endl;
  }
}

void Library::EditBook(){
  int index;
  std::cout << "Podaj indeks ksiazki: ";
  std::cin >> index;
  if(index >= 0 && index < size){
    int choice = -1;
    std::cout << "Wybierz co chcesz edytowac: " << std::endl;
    std::cout << "1. Autora" << std::endl;
    std::cout << "2. Tytul" << std::endl;
    std::cout << "3. Spis" << std::endl;
    std::cin >> choice;
    if(choice == 1){
      std::string newAuthor;
      std::cout << "Podaj nowego autora: " << std::endl;
      std::cin >> newAuthor;
      array[index].SetAuthor(newAuthor);
    } else if(choice == 2){
      std::string newTitle;
      std::cout << "Podaj nowy tytul: " << std::endl;
      std::cin >> newTitle;
      array[index].SetAuthor(newTitle);
    } else if(choice == 3){
      std::string newChapter;
      int number;
      std::cout << "Podaj, ktory rozdzial chcesz edytowac: " << std::endl;
      std::cin >> number;
      std::cout << "Podaj tresc nowego rozdzialu: " << std::endl;
      std::cin >> newChapter;
      array[index].SetChapter(number-1, newChapter);
    }
  } else {
    std::cout << "Nie ma takiej ksiazki" << std::endl;
  }
}



