#include <iostream>

#include "LibraryItem.hpp"
#include "Book.hpp"
#include "Magazine.hpp"
#include "Library.hpp"

int main(){
  // LibraryItem li("Nineteen Eighty-Four", "George Orwell", 1949,"978-0-596-52068-7", 328);
  // li.display();
  // Book book("Nineteen Eighty-Four", "George Orwell", 1949,"978-0-596-52068-7", 328, "fiction");
  // book.display();

  Magazine magazine("Nineteen Eighty-Four", "George Orwell", 1949,"978-0-596-52068-7", 328, "new");
  magazine.display();

  // Library library;
  // library.add(magazine);
  // std::cout << library.search("Nineteen Eighty-Four");
  // library.get(0).display();



}
