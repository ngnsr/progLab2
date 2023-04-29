#include <iostream>
#include <stack>

#include "Book.hpp"
#include "Library.hpp"
#include "LibraryItem.hpp"
#include "Magazine.hpp"

void clearInputStream();

void printExamples() {
  Book book("Moonwalking with Einstein: The Art and Science of Remembering "
            "Everything",
            "Joshua Foer", 2012, 1, 307, "Biography", "978-0-143-12053-7");
  Book book1("A Mind for Numbers: How to Excel at Math and Science",
             "Barbara Oakley", 2014, 2, 336, "Education", "978-0-399-16524-5");
  Book book2("Deep Work: Rules for Focused Success in a Distracted World",
             "Cal Newport", 2016, 3, 296, "Psychology", "978-1-455-58669-1");

  Magazine magazine("BBC Top Gear Magazine", "?", 1993, 4, 50, "New",
                    "1350-9624");
  std::cout << "Examples: " << std::endl << std::endl;
  book.display();
  book1.display();
  book2.display();
  magazine.display();
}

class menu {

public:
  std::vector<menu *> children;
  void (*func)();

  const std::string name;

  menu(const std::string &name) : name(name), func(nullptr) {}
  menu(const std::string &name, void (*func)()) : name(name), func(func) {}

  menu subMenu(const std::string &name) { return menu(name, this); }
  menu subMenu(const std::string &name, void (*func)()) {
    return menu(name, this, func);
  }

  menu *getChild(int i) { return children[i]; }

  ~menu() { func = nullptr; }

private:
  menu(const std::string &name, menu *parent) : name(name), func(nullptr) {
    parent->children.push_back(this);
  }

  menu(const std::string &name, menu *parent, void (*func)())
      : name(name), func(func) {
    parent->children.push_back(this);
  }
};

Library library;

void getSize() { std::cout << "Size: " << library.getSize() << std::endl; }

void display() {
  std::cout << "Display: " << std::endl;
  library.display();
  std::cout << std::endl;
}

unsigned int readInt(const std::string message) {
  int n;
  std::string line;

  while (true) {
    std::cout << message;
    try {
      std::getline(std::cin, line);
      n = std::stoi(line);
      std::cout << std::endl;
      return n;
    } catch (...) {
    }
  }
}

std::string readLine(const std::string message) {
  std::string line;
  while (true) {
    std::cout << message;
    try {
      std::getline(std::cin, line);
      std::cout << std::endl;
      return line;
    } catch (...) {
    }
  }
}

LibraryItem readLibraryItem() {
  const std::string readTitle = "Enter title : \n > ";
  const std::string readAuthor = "Enter author : \n > ";
  const std::string readPublicationYear = "Enter publication year : \n > ";
  const std::string readId = "Enter id : \n > ";
  const std::string readNumberOfPages = "Enter number of pages : \n > ";
  clearInputStream();
  while (true) {
    std::string title = readLine(readTitle);
    std::string author = readLine(readAuthor);
    unsigned int publicationYear = readInt(readPublicationYear);
    unsigned int id = readInt(readId);
    unsigned int numberOfPages = readInt(readNumberOfPages);
    try {
      const LibraryItem item(title, author, publicationYear, id, numberOfPages);
      return item;
    } catch (const std::exception &exc) {
      std::cout << exc.what() << std::endl;
      clearInputStream();
    }
  }
}

void addLibraryItem() {
  while (true) {
    try {
      library.add(readLibraryItem());
      std::cout << "Added successfully!" << std::endl;
      return;
    } catch (const std::exception &exc) {
      std::cout << exc.what() << std::endl;
    }
  }
}

void sort() {
  library.sort();
  std::cout << "Sorted successfully!" << std::endl;
}

void search() {
  const std::string readTitle = "Enter title: \n > ";
  clearInputStream();
  std::string title = readLine(readTitle);
  LibraryItem *item = library.search(title);
  if (item != nullptr) {
    item->display();
  }
  std::cout << std::endl;
}

void remove() {
  const std::string readTitle = "Enter title: \n > ";
  clearInputStream();
  try {
    std::string title = readLine(readTitle);
    library.remove(title);
  } catch (const std::exception &exc) {
    std::cout << exc.what() << std::endl;
  }
}

void indexOf() {
  clearInputStream();
  std::string title = readLine("Enter title: \n > ");
  unsigned int index = library.indexOf(title);
  std::cout << "Index: " << (index != -1 ? std::to_string(index) : "not found!")
            << std::endl;
}

void startMenu(std::stack<menu *> &menuStack) {
  bool executed = false;
  while (!menuStack.empty()) {
    menu *currentMenu = menuStack.top();

    // Print current menu
    std::cout << currentMenu->name << ":\n";

    // execute function
    if (currentMenu->func != nullptr && !executed) {
      currentMenu->func();
      executed = true;
    }

    if(currentMenu->func == nullptr){
      executed = false;
      // after execution remove action
      currentMenu->func = nullptr;
    }

    // print submenues
    int i = 1;
    for (auto &submenu : currentMenu->children) {
      std::cout << i++ << ". " << submenu->name << "\n";
    }

    std::cout << "0. Exit current menu\n";

    // Get input
    std::string input;
    std::cout << " > ";
    std::cin >> input;
    std::cout << std::endl;

    if (input == "0") {
      menuStack.pop();
      executed = false;
    } else {
      int item;
      try {
        item = std::stoi(input);
      } catch (const std::exception &exc) {
        std::cout << exc.what() << std::endl;
        continue;
      }

      if (item >= 1 && item <= currentMenu->children.size()) {
        menuStack.push(currentMenu->children[item - 1]);
      }
    }
  }
}

void addBook() {
  const LibraryItem libraryItem = readLibraryItem();

  const std::string readGanreMsg = "Enter ganre : \n > ";
  const std::string readISBNmsg = "Enter ISBN : \n > ";

  while (true) {
    std::string ganre = readLine(readGanreMsg);
    std::string ISBN = readLine(readISBNmsg);

    try {
      const Book book(libraryItem, ganre, ISBN);
      library.add(book);
      break;
    } catch (const std::exception &exc) {
      std::cout << exc.what() << std::endl;
    }
  }

  std::cout << "Added successfully!" << std::endl;
}

void addMagazine() {
  const LibraryItem libraryItem = readLibraryItem();

  const std::string readConditionMsg = "Enter condition : \n > ";
  const std::string readISSNmsg = "Enter ISSN : \n > ";

  while (true) {
    std::string ganre = readLine(readConditionMsg);
    std::string ISBN = readLine(readISSNmsg);

    try {
      const Magazine magazine(libraryItem, ganre, ISBN);
      library.add(magazine);
      break;
    } catch (const std::exception &exc) {
      std::cout << exc.what() << std::endl;
    }
  }

  std::cout << "Added successfully!" << std::endl;
}

void clearInputStream() {
  std::cin.sync();
  std::cin.clear();
  std::cin.ignore();
}

int main() {

  std::stack<menu *> menuStack;

  menu mainMenu = menu("Mode");
  menu addMenu = mainMenu.subMenu("add(...)");

  menu addLibraryItemMenu =
      addMenu.subMenu("addLibraryItem(...)", addLibraryItem);
  menu addBookMenu = addMenu.subMenu("addBook(...)", addBook);
  menu addMagazineMenu = addMenu.subMenu("addMagazine(...)", addMagazine);

  menu searchMenu = mainMenu.subMenu("search(...)", search);
  menu removeMenu = mainMenu.subMenu("remove(...)", remove);
  menu getSizeMenu = mainMenu.subMenu("getSize()", getSize);
  menu sortMenu = mainMenu.subMenu("sort()", sort);
  menu displayMenu = mainMenu.subMenu("display()", display);
  menu indexOfMenu = mainMenu.subMenu("indexOf(...)", indexOf);

  menuStack.push(&mainMenu);

  printExamples();

  startMenu(menuStack);
}
