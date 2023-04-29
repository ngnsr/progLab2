#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "LibraryItem.hpp"

using std::vector;

class Library {
public:
  Library();
  void add(const LibraryItem &item);

  /**
   * @brief remove first element by title
   * @param LibraryItem
   */

  void remove(const std::string &title);

  /**
   *  @brief Search index of element by title
   *  @param title
   *  @return -1 if element not exist
   */
  int indexOf(std::string title) const;

  LibraryItem* search(std::string title);

  /**
   *  @brief Sort Library.items by LibraryItem < operator
   */

  void sort();

  void display() const;
  int getSize() const;

  LibraryItem atIndex(int index) const;

  ~Library();

private:
  vector<LibraryItem> items;
  int size;
};

#endif // !LIBRARY_HPP
