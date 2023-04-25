#include "Book.hpp"

Book::Book(std::string title, std::string author, unsigned int publicationYear,
           std::string ISBN, unsigned int numberOfPages, std::string ganre)
    : LibraryItem(title, author, publicationYear, ISBN, numberOfPages),
      ganre(ganre) {}

std::string Book::getGanre() const { return ganre; }

std::string Book::toString(){
  std::string out = LibraryItem::toString();
  out += "Ganre: " + ganre + "\n";
  return out;
}

void Book::display(){
  std::cout << toString() << std::endl;
}
