#ifndef LIBRARYITEM_HPP
#define LIBRARYITEM_HPP

#include <iostream>
#include <regex>
#include <string>

class LibraryItem {
public:
  LibraryItem(std::string title, std::string author,
              unsigned int publicationYear, unsigned int id,
              unsigned int numberOfPages);

  LibraryItem(const LibraryItem &other);

  std::string getTitle() const;

  std::string getAuthor() const;

  unsigned int getId() const;

  unsigned int getPublicationYear() const;

  unsigned int getNumberOfPages() const;

  void setTitle(const std::string &title);

  void setAuthor(const std::string &author);

  void setId(const unsigned int &id);

  void setPublicationYear(unsigned int publicationYear);

  void setNumberOfPages(unsigned int numberOfPages);

  virtual std::string toString();

  void display();

  bool operator<(const LibraryItem &other) const;

  LibraryItem &operator=(const LibraryItem &other);

private:
  std::string title;
  std::string author;
  unsigned int id;
  unsigned int publicationYear;
  unsigned int numberOfPages;

private:
  static std::string checkPrintableString(const std::string &author);

  static std::string validatePattern(const std::string &line,
                                     const std::string &pattern);

  static unsigned int checkPublicationYear(const unsigned int &publicationYear);
};

#endif // !LIBRARYITEM_HPP
