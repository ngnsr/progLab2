#include <iostream>

#include "Book.hpp"
#include "Library.hpp"
#include "LibraryItem.hpp"
#include "Magazine.hpp"

void init(Library &library) {
  Book book("Moonwalking with Einstein: The Art and Science of Remembering "
            "Everything",
            "Joshua Foer", 2012, 1, 307, "Biography", "978-0-143-12053-7");
  Book book1("A Mind for Numbers: How to Excel at Math and Science",
             "Barbara Oakley", 2014, 2, 336, "Education", "978-0-399-16524-5");
  Book book2("Deep Work: Rules for Focused Success in a Distracted World",
             "Cal Newport", 2016, 3, 296, "Psychology", "978-1-455-58669-1");

  Magazine magazine("BBC Top Gear Magazine", "?", 1993, 4, 50, "New",
                    "1350-9624");
  LibraryItem empty("empty", "unknown", 2020, 10, 1);

  library.add(book2);
  library.add(book1);
  library.add(book);
  library.add(magazine);
  library.add(empty);
}

int main() {

  Library library;
  init(library);
  library.sort();
  library.display();

  // LibraryItem i = *library.search("Aaa");
  // i.display();
  // LibraryItem si = *library.search("afa");
  // si.display();
}
