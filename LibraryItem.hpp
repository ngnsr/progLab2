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
  std::string getTitle();
  std::string getAuthor();
  std::string getISBN();
  unsigned int getPublicationYear();
  unsigned int getNumberOfPages();
  bool operator<(const LibraryItem &other);

private:
  const std::string title;
  const std::string author;
  const std::string ISBN;
  const unsigned int publicationYear;
  const unsigned int numberOfPages;

private:
  std::string isTitleValid(const std::string &title);
  std::string isAuthorValid(const std::string &author);
  std::string isISBNValid(const std::string &ISBN);
  std::string validatePattern(const std::string &line, const std::string &pattern);
  unsigned int isPublicationYearValid(const unsigned int publicationYear);
  unsigned int isNumberOfPagesValid(const unsigned int numberOfPages);
};

#endif
