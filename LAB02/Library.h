#pragma once

#include "Book.h"
#include <initializer_list>

class Library {
  private:
    Book* array;
    std::size_t size;
  public:
    Library();
    Library(std::initializer_list<Book> list);
    Library(const Library& orig);
    Library(Library&& orig);

    Library& operator=(const Library& right);
    Library& operator=(Library&& right);
    Book& operator[](std::size_t index);
    const Book& operator[](std::size_t index) const;

    void AddNewBook();
    void ShowBooksByAuthor();
    void DeleteBook();
    void CreateChapters();
    void ShowChapters();
    void EditBook();

    std::size_t GetSize() const;

    ~Library();
};


std::ostream& operator<<(std::ostream& ostr, const Library& library);
