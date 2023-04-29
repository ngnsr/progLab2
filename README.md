## Get source code

- git clone https://github.com/ngnsr/progLab2
- copy files attached to email

## Compile

### *nix
**ninja & cmake required**
````bash
# Change directory to folder where source code located.
mkdir build
cd build
cmake -GNinja ..
ninja
````

### Windows
?

## Run

````bash
./prog
````

# Library Management System

This library management system is designed to manage a collection of library items like books and magazines. It provides functionality to add, remove, search, display, and sort library items based on their properties.

## Class Hierarchy

The library management system uses a class hierarchy to represent the entities in the library:

### LibraryItem

The `LibraryItem` class is a base class that represents a general item in the library. It has the following properties:

-   `title`: The title of the item.
-   `author`: The author of the item.
-   `publicationYear`: The year in which the item was published.
-   `id`: A unique identifier for the item.

### Book

The `Book` class is derived from the `LibraryItem` class and represents a book in the library. It has the following additional properties:

-   `ganre`: The ganre of the book.
-   `ISBN`: The ISBN of the book.

### Magazine

The `Magazine` class is also derived from the `LibraryItem` class and represents a magazine in the library. It has the following additional properties:

-   `condition`: The condition of the magazine.
-   `ISSN`: The ISSN of the magazine.


### Operator Overloading

The `<` operator is overloaded to compare two books based on their titles.

### Library

The `Library` class manages the collection of library items. It has the following functions:

-   `add(...)`: Adds a library item to the collection.
-   `remove(...)`: Removes a library item from the collection.
-   `search(...)`: Finds a library item based on its properties.
-   `display()`: Displays all items in the collection.
-   `sort()`: Sorts the collection based on LibraryItem `<` operator.

## CLI Interface

The library management system can be used through a Command Line Interface (CLI) to interact with the `Library` class. 

To use the CLI, the user can enter one of the above commands followed by the necessary parameters. 

The CLI implemented using standard C++ input/output streams.
