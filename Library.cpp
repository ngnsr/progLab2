#include "Library.hpp"
#include "LibraryItem.hpp"

Library::Library() : size(0) {}

void Library::add(const LibraryItem &item) {
  items.push_back(item);
  size++;
}

void Library::remove(const std::string &title) {
  int index = indexOf(title);
  if (index == -1) {
    return;
  }
  items.erase(items.begin() + index);
  size--;
}

int Library::indexOf(const std::string title) const {
  for (int i = 0; i < items.size(); i++) {
    if (items[i].getTitle() == title) {
      return i;
    }
  }
  return -1;
}

LibraryItem Library::atIndex(int index) const {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Out of bounds");
  }
  return items[index];
}

std::vector<LibraryItem>::const_iterator
Library::search(const std::string title) const {
  int index = indexOf(title);
  if (index == -1) {
    return items.end();
  }
  return items.begin() + index;
}

void Library::sort() { std::sort(items.begin(), items.end()); }

void Library::display() const {
  for (auto i : items) {
    i.display();
    std::cout << std::endl;
  }
}

int Library::getSize() const { return size; }

Library::~Library() {}
