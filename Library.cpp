#include "Library.hpp"
#include "LibraryItem.hpp"

Library::Library() : size(0) {}

void Library::add(const LibraryItem &item) {
  bool contains = false;
  int i = 0;
  while (!contains && i < size) {
    if (items[i].getId() == item.getId()) {
      contains = true;
    }
    i++;
  }

  if (contains) {
    throw std::invalid_argument("Invalid ID");
  }else{
    items.push_back(item);
    size++;
  }
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

LibraryItem* Library::search(const std::string title){
  int index = indexOf(title);
  if (index == -1) {
    return nullptr;
  }
  return &items[index];
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
