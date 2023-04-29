#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>

#include "LibraryItem.hpp"

class Book : public LibraryItem {
public:
  Book(std::string title, std::string author, unsigned int publicationYear,
       unsigned int id, unsigned int numberOfPages, std::string ganre, std::string ISBN);
  Book(const LibraryItem &libraryItem, std::string ganre, std::string ISBN);

  std::string getGanre() const;
  std::string getISBN() const;
  void setGanre(const std::string &newGanre);
  void setISBN(const std::string &ISBN);
  std::string toString() override;
  void display();

private:
  std::string ganre;
  std::string ISBN;

  static std::string checkISBN(const std::string &ISBN);
};

#endif // !BOOK_HPP
