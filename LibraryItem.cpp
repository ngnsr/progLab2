#include "LibraryItem.hpp"

LibraryItem::LibraryItem(std::string title, std::string author,
                         unsigned int publicationYear, std::string ISBN,
                         unsigned int numberOfPages)
    : title(std::move(title)), author(std::move(author)),
      publicationYear(publicationYear), ISBN(std::move(ISBN)),
      numberOfPages(numberOfPages) {}

std::string LibraryItem::getTitle() { return title; }

std::string LibraryItem::getAuthor() { return author; }

std::string LibraryItem::getISBN() { return ISBN; }
unsigned int LibraryItem::getPublicationYear() { return publicationYear; }
unsigned int LibraryItem::getNumberOfPages() { return numberOfPages; }

bool LibraryItem::operator<(const LibraryItem &other) {
  return this->title < other.title;
}
