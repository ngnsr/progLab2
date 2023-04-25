#ifndef LIBRARYITEM_HPP
#define LIBRARYITEM_HPP

#include <iostream>
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
};

#endif
