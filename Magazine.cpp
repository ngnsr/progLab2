#include "Magazine.hpp"
#include "LibraryItem.hpp"
#include <string>

Magazine::Magazine(std::string title, std::string author,
                   unsigned int publicationYear, std::string ISBN,
                   unsigned int numberOfPages, std::string condition)
    : LibraryItem(title, author, publicationYear, ISBN, numberOfPages),
      condition(condition) {}

std::string Magazine::getCondition() const { return condition; }

std::string Magazine::toString() {
  std::string out = LibraryItem::toString();
  out += "Condition: " + condition + "\n";
  return out;
}

void Magazine::display(){
  std::cout << toString();
}
