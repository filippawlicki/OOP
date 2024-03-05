#include "Book.h"

#include <iostream>
#include <string>

Book::Book() : author("unknown"), title("unknown") { // Konstruktor bezparametrowy
  std::cout << "Constructor without parameters" << std::endl;
}

Book::Book(const std::string& author, const std::string& title) : author(author), title(title) { // Konstruktor (stale l-referencje)
  std::cout << "Constructor with const lvalue(author: " << author << ", title: " << title << ")" << std::endl;
}
Book::Book(std::string&& author, std::string&& title) : author(std::move(author)), title(std::move(title)) { // Konstruktor (r-referencje)
  std::cout << "Constructor with rvalue(author: " << this->author << ", title: " << this->title << ")" << std::endl;
}

Book::Book(const Book& other) : author(other.author), title(other.title) { // Konstruktor kopiujacy
  std::cout << "Copy constructor(author: " << author << ", title: " << title << ")" << std::endl;
}

Book::Book(Book&& other) : author(other.author), title(other.title) { // Konstruktor przenoszacy
  std::cout << "Transfering constructor(author: " << author << ", title: " << title << ")" << std::endl;
  other.author = nullptr;
  other.title = nullptr;
}

std::string Book::GetAuthor() const {
  return author;
}

std::string Book::GetTitle() const {
  return title;
}

void Book::SetAuthor(const std::string& newAuthor) { // Setery (stale l-referencje)
  author = newAuthor;
}

void Book::SetTitle(const std::string& newTitle) {
  title = newTitle;
}

void Book::SetAuthor(std::string&& newAuthor) { // Setery (r-referencje)
  author = std::move(newAuthor);
}

void Book::SetTitle(std::string&& newTitle) {
  title = std::move(newTitle);
}

Book::Book& operator=(const Book& other) { // Kopiujacy operator przypisania
  std::cout << "Assignment operator with lvalue reference" << std::endl;
  if (this != &other) {
    author = other.author;
    title = other.title;
  }
  return *this;
}

Book::Book& operator=(Book&& other) { // Przenoszacy operator przypisania
  std::cout << "Assignment operator with rvalue reference" << std::endl;
  if (this != &other) {
    author = std::move(other.author);
    title = std::move(other.title);
  }
  return *this;
}

Book::~Book() {
  std::cout << "~Book(author: " << author << ", title: " << title << ")" << std::endl;
}

std::ostream& operator<<(std::ostream& ostr, const Book& book) {
  ostr << "Book(author: " << book.GetAuthor() << ", title: " << book.GetTitle() << ")";
  return ostr;
}