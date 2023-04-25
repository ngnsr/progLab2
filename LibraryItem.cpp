#include "LibraryItem.hpp"

LibraryItem::LibraryItem(std::string title, std::string author,
                         unsigned int publicationYear, std::string ISBN,
                         unsigned int numberOfPages)
    : title(isTitleValid(title)), author(isAuthorValid(author)),
      publicationYear(isPublicationYearValid(publicationYear)),
      ISBN(isISBNValid(ISBN)),
      numberOfPages(isNumberOfPagesValid(numberOfPages)) {}

std::string LibraryItem::getTitle() { return title; }

std::string LibraryItem::getAuthor() { return author; }

std::string LibraryItem::getISBN() { return ISBN; }

unsigned int LibraryItem::getPublicationYear() { return publicationYear; }

unsigned int LibraryItem::getNumberOfPages() { return numberOfPages; }

bool LibraryItem::operator<(const LibraryItem &other) {
  return this->title < other.title;
}

std::string LibraryItem::isTitleValid(const std::string &title) {
  const std::string titlePattern = "^(\\w)+([[:punct:]]?\\s(\1)+)+$";

  return validatePattern(title, titlePattern);
};

std::string LibraryItem::isAuthorValid(const std::string &author) {
  const std::string titlePattern = "^([A-Za-z`'-])(\\s\1)*$";

  return validatePattern(author, titlePattern);
};

std::string LibraryItem::isISBNValid(const std::string &ISBN) {
  const std::string ISBNPattern =
      "^(?:ISBN(?:-13)?:?\ )?(?=[0-9]{13}$|(?=(?:[0-9]+[-\ ]){4})[-\ 0-9]{17}$)"
      "97[89][-\ ]?[0-9]{1,5}[-\ ]?[0-9]+[-\ ]?[0-9]+[-\ ]?[0-9]$";

  return validatePattern(ISBN, ISBNPattern);
}

unsigned int LibraryItem::isPublicationYearValid(const unsigned int publicationYear) {
  return publicationYear > 1800;
}

std::string LibraryItem::validatePattern(const std::string &line, const std::string &pattern) {
  if (std::regex_match(line, std::regex(pattern))) {
    return line;
  } else {
    throw std::invalid_argument("Invalid title");
  }
}
