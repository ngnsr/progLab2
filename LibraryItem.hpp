#ifndef LIBRARYITEM_HPP
#define LIBRARYITEM_HPP

#include <iostream>
#include <regex>
#include <string>

class LibraryItem {
public:
  LibraryItem(std::string title, std::string author,
              unsigned int publicationYear, std::string ISBN,
              unsigned int numberOfPages);
  std::string getTitle() const;
  std::string getAuthor() const;
  std::string getISBN() const;
  unsigned int getPublicationYear() const;
  unsigned int getNumberOfPages() const;
  bool operator<(const LibraryItem &other) const;
  virtual std::string toString();
  virtual void display();

private:
  const std::string title;
  const std::string author;
  const std::string ISBN;
  const unsigned int publicationYear;
  const unsigned int numberOfPages;

private:
  std::string checkPrintableString(const std::string &author) const;
  std::string checkISBN(const std::string &ISBN) const;
  std::string validatePattern(const std::string &line, const std::string &pattern) const;
  unsigned int checkPublicationYear(const unsigned int &publicationYear) const;
};

#endif // !LIBRARYITEM_HPP
