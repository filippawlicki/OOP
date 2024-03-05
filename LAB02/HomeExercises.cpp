#include <string>
#include <iostream>

class Book {
  std::string author, title;
  public:
    Book() : author("unknown"), title("unknown") { // Konstruktor bezparametrowy
      std::cout << "Constructor without parameters" << std::endl;
    }

    Book(const std::string& author, const std::string& title) : author(author), title(title) { // Konstruktor (stale l-referencje)
      std::cout << "Constructor with const lvalue(author: " << author << ", title: " << title << ")" << std::endl;
    }
    Book(std::string&& author, std::string&& title) : author(std::move(author)), title(std::move(title)) { // Konstruktor (r-referencje)
      std::cout << "Constructor with rvalue(author: " << this->author << ", title: " << this->title << ")" << std::endl;
    }

    Book(const Book& other) : author(other.author), title(other.title) { // Konstruktor kopiujacy
      std::cout << "Copy constructor(author: " << author << ", title: " << title << ")" << std::endl;
    }

    Book(Book&& other) : author(other.author), title(other.title) { // Konstruktor przenoszacy
      std::cout << "Transfering constructor(author: " << author << ", title: " << title << ")" << std::endl;
      other.author = nullptr;
      other.title = nullptr;
    }

    std::string GetAuthor() const {
      return author;
    }

    std::string GetTitle() const {
      return title;
    }

    void SetAuthor(const std::string& newAuthor) { // Setery (stale l-referencje)
      author = newAuthor;
    }

    void SetTitle(const std::string& newTitle) {
      title = newTitle;
    }

    void SetAuthor(std::string&& newAuthor) { // Setery (r-referencje)
      author = std::move(newAuthor);
    }

    void SetTitle(std::string&& newTitle) {
      title = std::move(newTitle);
    }

    Book& operator=(const Book& other) { // Kopiujacy operator przypisania
      std::cout << "Assignment operator with lvalue reference" << std::endl;
      if (this != &other) {
        author = other.author;
        title = other.title;
      }
      return *this;
    }

    Book& operator=(Book&& other) { // Przenoszacy operator przypisania
      std::cout << "Assignment operator with rvalue reference" << std::endl;
      if (this != &other) {
        author = std::move(other.author);
        title = std::move(other.title);
      }
      return *this;
    }

    ~Book() {
      std::cout << "~Book(author: " << author << ", title: " << title << ")" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& ostr, const Book& book) {
  ostr << "Book(author: " << book.GetAuthor() << ", title: " << book.GetTitle() << ")";
  return ostr;
}

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