#ifndef MAGAZINE_HPP
#define MAGAZINE_HPP

#include "LibraryItem.hpp"
#include <iostream>
#include <string>

class Magazine : public LibraryItem {
public:
  Magazine(std::string title, std::string author, unsigned int publicationYear,
           unsigned int id, unsigned int numberOfPages, std::string condition,
           std::string ISSN);

  std::string getCondition() const;
  std::string getISSN() const;
  void setCondition(const std::string &newCondition);
  void setISSN(const std::string &ISSN);
  std::string toString() override;
  void display();

private:
  // new, used, etc
  std::string condition;
  std::string ISSN;

  static std::string checkISSN(const std::string &ISSN);
};

#endif // !MAGAZINE_HPP
