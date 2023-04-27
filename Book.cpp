#include "Book.hpp"
#include "LibraryItem.hpp"

Book::Book(std::string title, std::string author, unsigned int publicationYear,
           unsigned int id, unsigned int numberOfPages, std::string ganre,
           std::string ISBN)
    : LibraryItem(title, author, publicationYear, id, numberOfPages),
      ganre(ganre), ISBN(checkISBN(ISBN)) {}

Book::Book(const LibraryItem &libraryItem, std::string ganre, std::string ISBN)
    : LibraryItem(libraryItem.getTitle(), libraryItem.getAuthor(),
                  libraryItem.getPublicationYear(), libraryItem.getId(),
                  libraryItem.getNumberOfPages()), ganre(ganre), ISBN(checkISBN(ISBN)) {}

std::string Book::getGanre() const { return ganre; }

std::string Book::toString() {
  std::string out = LibraryItem::toString();
  out += "Ganre: " + ganre + "\n";
  out += "ISBN: " + ISBN + "\n";
  return out;
}

void Book::display() { std::cout << toString() << std::endl; }

void Book::setGanre(const std::string &newGanre) { ganre = newGanre; }

void Book::setISBN(const std::string &ISBN) { this->ISBN = ISBN; }

std::string Book::checkISBN(const std::string &ISBN) {
  // https://www.oreilly.com/library/view/regular-expressions-cookbook/9781449327453/ch04s13.html
  const std::string ISBNPattern =
      R"(^(?:ISBN(?:-13)?:?\ )?(?=[0-9]{13}$|(?=(?:[0-9]+[-\ ]){4})[-\ 0-9]{17}$)97[89][-\ ]?[0-9]{1,5}[-\ ]?[0-9]+[-\ ]?[0-9]+[-\ ]?[0-9]$)";

  if (std::regex_match(ISBN, std::regex(ISBNPattern))) {
    return ISBN;
  } else {
    throw std::invalid_argument("Invalid argument");
  }
}
