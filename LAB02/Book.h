#pragma once

#include <string>

class Book {
  std::string author, title;
public:
  Book();
  Book(const std::string& author, const std::string& title);
  Book(std::string&& author, std::string&& title);
  Book(const Book& other);
  Book(Book&& other);

  Book& operator=(const Book& other);
  Book& operator=(Book&& other);

  std::string GetAuthor() const;
  std::string GetTitle() const;

  void SetAuthor(const std::string& newAuthor);
  void SetTitle(const std::string& newTitle);

  void SetAuthor(std::string&& newAuthor);
  void SetTitle(std::string&& newTitle);

  Book& operator=(const Book& other);
  Book& operator=(Book&& other);

  ~Book();
};

std::ostream& operator<<(std::ostream& ostr, const Book& book);