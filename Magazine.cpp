#include "Magazine.hpp"

Magazine::Magazine(std::string title, std::string author,
                   unsigned int publicationYear, unsigned int id, 
                   unsigned int numberOfPages, std::string condition, std::string ISSN)
    : LibraryItem(title, author, publicationYear, id, numberOfPages),
      condition(condition), ISSN(checkISSN(ISSN)) {}

Magazine::Magazine(const LibraryItem &libraryItem, std::string condition, std::string ISSN)
    : LibraryItem(libraryItem.getTitle(), libraryItem.getAuthor(),
                  libraryItem.getPublicationYear(), libraryItem.getId(),
                  libraryItem.getNumberOfPages()),condition(condition), ISSN(checkISSN(ISSN)) {}

std::string Magazine::getCondition() const { return condition; }

std::string Magazine::toString() {
  std::string out = LibraryItem::toString();
  out += "Condition: " + condition + "\n";
  return out;
}

void Magazine::display(){
  std::cout << toString();
}

void Magazine::setCondition(const std::string& newCondition){
  condition = newCondition;
}

std::string Magazine::checkISSN(const std::string &ISSN){
  const std::string ISSNPattern = R"(^\d{4}-\d{3}[0-9xX]$)";

  if (std::regex_match(ISSN, std::regex(ISSNPattern))) {
    return ISSN;
  } else {
    throw std::invalid_argument("Invalid argument");
  }

}
