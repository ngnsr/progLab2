#include "LibraryItem.hpp"

LibraryItem::LibraryItem(std::string title, std::string author,
                         unsigned int publicationYear, std::string ISBN,
                         unsigned int numberOfPages)
    : title(checkPrintableString(title)), author(checkPrintableString(author)),
      publicationYear(checkPublicationYear(publicationYear)),
      ISBN(checkISBN(ISBN)), numberOfPages(numberOfPages) {}

std::string LibraryItem::getTitle() const { return title; }

std::string LibraryItem::getAuthor() const { return author; }

std::string LibraryItem::getISBN() const { return ISBN; }

unsigned int LibraryItem::getPublicationYear() const { return publicationYear; }

unsigned int LibraryItem::getNumberOfPages() const { return numberOfPages; }

bool LibraryItem::operator<(const LibraryItem &other) const {
  return this->title < other.title;
}

std::string LibraryItem::checkPrintableString(const std::string &author) const {
  const std::string titlePattern = R"(^[[:print:]]+$)";

  return validatePattern(author, titlePattern);
};

std::string LibraryItem::checkISBN(const std::string &ISBN) const {
  // https://www.oreilly.com/library/view/regular-expressions-cookbook/9781449327453/ch04s13.html
  const std::string ISBNPattern = R"(^(?:ISBN(?:-13)?:?\ )?(?=[0-9]{13}$|(?=(?:[0-9]+[-\ ]){4})[-\ 0-9]{17}$)97[89][-\ ]?[0-9]{1,5}[-\ ]?[0-9]+[-\ ]?[0-9]+[-\ ]?[0-9]$)";

  return validatePattern(ISBN, ISBNPattern);
}

unsigned int
LibraryItem::checkPublicationYear(const unsigned int &publicationYear) const {
  if (publicationYear > 1800) {
    return publicationYear;
  } else {
    throw std::invalid_argument("Invalid publication year");
  }
}

std::string LibraryItem::validatePattern(const std::string &line,
                                         const std::string &pattern) const {
  if (std::regex_match(line, std::regex(pattern))) {
    return line;
  } else {
    throw std::invalid_argument("Invalid argument");
  }
}

std::string LibraryItem::toString() {
  std::string out;
  out += "Title: " + title + "\n";
  out += "Author: " + author + "\n";
  out += "ISBN: " + ISBN + "\n";
  out += "Publication Year: " + std::to_string(publicationYear) + "\n";
  out += "Number of pages: " + std::to_string(numberOfPages) + "\n";
  return out;
}

void LibraryItem::display() { std::cout << toString(); }
