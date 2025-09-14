#ifndef LIBRARY_OPERATION_H
#define LIBRARY_OPERATION_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "book.h"
#include "user.h"
using namespace std;

class LibraryOperation {
private:
    unordered_map<string, BooksList> List_Books;
    unordered_map<string, User> List_User;

public:
    void AddBook(BooksList book) {
        List_Books[book.BookIdGet()] = book;
    }

    void AddUser(User user) {
        List_User[user.GetUserId()] = user;
    }

    BooksList* FindBook(string book_id) {
        auto it = List_Books.find(book_id);
        if (it != List_Books.end()) {
            return &it->second;
        }
        return nullptr;
    }

    User* FindUser(string user_id) {
        auto it = List_User.find(user_id);
        if (it != List_User.end()) {
            return &it->second;
        }
        return nullptr;
    }

    bool LendBook(string book_id, string user_id) {
        BooksList* book = FindBook(book_id);
        User* user = FindUser(user_id);

        if (!book || !user) return false;
        if (!book->IsAvailable()) return false;
        if (!user->CanBorrow()) return false;

        book->SetBorrowerId(user_id);
        user->BorrowBook(book_id);

        return true;
    }

    bool ReturnBook(string book_id, string user_id) {
        BooksList* book = FindBook(book_id);
        User* user = FindUser(user_id);

        if (!book || !user) return false;
        if (book->BorrowerIdGet() != user_id) return false;

        book->SetAvailable(true);
        user->ReturnBook(book_id);

        return true;
    }

    int GetBorrowedBooksCount(string user_id) {
        User* user = FindUser(user_id);
        if (user) {
            return user->GetBorrowedBooksCount();
        }
        return 0;
    }

    vector<BooksList> GetAvailableBooks() {
        vector<BooksList> available;
        for (auto& pair : List_Books) {
            if (pair.second.IsAvailable()) {
                available.push_back(pair.second);
            }
        }
        return available;
    }

    vector<BooksList> GetBorrowedBooksByUser(string user_id) {
        vector<BooksList> borrowed;
        for (auto& pair : List_Books) {
            if (pair.second.BorrowerIdGet() == user_id) {
                borrowed.push_back(pair.second);
            }
        }
        return borrowed;
    }
};

#endif // LIBRARY_OPERATION_H