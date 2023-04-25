#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>

#include "LibraryItem.hpp"

class Book : public LibraryItem {
public:
  Book(std::string title, std::string author, unsigned int publicationYear,
       std::string ISBN, unsigned int numberOfPages, std::string ganre);

  std::string getGanre() const;
  std::string toString() override;
  void display() override;

private:
  std::string ganre;
};

#endif // !BOOK_HPP
