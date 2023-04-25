#ifndef MAGAZINE_HPP
#define MAGAZINE_HPP

#include "LibraryItem.hpp"
#include <iostream>
#include <string>

class Magazine : public LibraryItem {
public:
  Magazine(std::string title, std::string author, unsigned int publicationYear,
           std::string ISBN, unsigned int numberOfPages,
           std::string condition);

  std::string getCondition() const;
  std::string toString() override;
  void display() override;

private:
  // new, used, etc
  std::string condition;
};

#endif // !MAGAZINE_HPP
