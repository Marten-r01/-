#include <iostream>
#include "user.h"
#include "LibraruOperation.h"
#include "book.h"

using namespace std;

int main() {

    LibraryOperation library;

    User student("John Doe", "S123", STUDENT);
    User faculty("Dr. Smith", "F456", FACULTY);
    User guest("Visitor", "G789", GUEST);

    library.AddUser(student);
    library.AddUser(faculty);
    library.AddUser(guest);

    BooksList book1("War and Peace", "Leo Tolstoy", "B001");
    BooksList book2("Crime and Punishment", "Fyodor Dostoevsky", "B002");
    BooksList book3("The Master and Margarita", "Mikhail Bulgakov", "B003");

    library.AddBook(book1);
    library.AddBook(book2);
    library.AddBook(book3);

    cout << "Lending books...\n";

    if (library.LendBook("B001", "S123")) {
        cout << "Student borrowed book successfully\n";
    }
    else {
        cout << "Student failed to borrow book\n";
    }

    if (library.LendBook("B002", "F456")) {
        cout << "Faculty borrowed book successfully\n";
    }
    else {
        cout << "Faculty failed to borrow book\n";
    }

    if (!library.LendBook("B001", "G789")) {
        cout << "Guest cannot borrow already taken book\n";
    }

    cout << "\nStudent borrowed books: " << library.GetBorrowedBooksCount("S123") << endl;
    cout << "Available books: " << library.GetAvailableBooks().size() << endl;

    if (library.ReturnBook("B001", "S123")) {
        cout << "Book returned successfully\n";
    }
    else {
        cout << "Book return failed\n";
    }

    return 0;
}