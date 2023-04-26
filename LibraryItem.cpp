#include "LibraryItem.hpp"

LibraryItem::LibraryItem(std::string title, std::string author,
                         unsigned int publicationYear, unsigned int id,
                         unsigned int numberOfPages)
    : title(checkPrintableString(title)), author(checkPrintableString(author)),
      publicationYear(checkPublicationYear(publicationYear)),
      id(id), numberOfPages(numberOfPages) {}

LibraryItem::LibraryItem(const LibraryItem &other)
    : title(checkPrintableString(other.title)),
      author(checkPrintableString(other.author)),
      publicationYear(checkPublicationYear(other.publicationYear)),
      id(other.id), numberOfPages(other.numberOfPages) {}

std::string LibraryItem::getTitle() const { return title; }

std::string LibraryItem::getAuthor() const { return author; }

unsigned int LibraryItem::getId() const { return id; }

unsigned int LibraryItem::getPublicationYear() const { return publicationYear; }

unsigned int LibraryItem::getNumberOfPages() const { return numberOfPages; }

void LibraryItem::setTitle(const std::string &title) {
  LibraryItem::title = title;
}

void LibraryItem::setAuthor(const std::string &author) {
  LibraryItem::author = author;
}

void LibraryItem::setId(const unsigned int &id) { this->id = id; }

void LibraryItem::setPublicationYear(unsigned int publicationYear) {
  LibraryItem::publicationYear = publicationYear;
}

void LibraryItem::setNumberOfPages(unsigned int numberOfPages) {
  LibraryItem::numberOfPages = numberOfPages;
}

std::string LibraryItem::checkPrintableString(const std::string &str) {
  const std::string pattern = R"(^[[:print:]]+$)";

  return validatePattern(str, pattern);
};


unsigned int
LibraryItem::checkPublicationYear(const unsigned int &publicationYear) {
  if (publicationYear > 1800) {
    return publicationYear;
  } else {
    throw std::invalid_argument("Invalid publication year");
  }
}

std::string LibraryItem::validatePattern(const std::string &line, const std::string &pattern) {
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
  out += "Id: " + std::to_string(id) + "\n";
  out += "Publication Year: " + std::to_string(publicationYear) + "\n";
  out += "Number of pages: " + std::to_string(numberOfPages) + "\n";
  return out;
}

void LibraryItem::display() { std::cout << toString(); }

LibraryItem &LibraryItem::operator=(const LibraryItem &other) {
  title = other.title;
  author = other.author;
  id = other.id;
  publicationYear = other.publicationYear;
  numberOfPages = other.numberOfPages;
  return *this;
}

bool LibraryItem::operator<(const LibraryItem &other) const {
  return title < other.title;
}
