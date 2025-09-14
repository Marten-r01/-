#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <list>
using namespace std;

enum GuestType {
    STUDENT,
    FACULTY,
    GUEST
};

class User {
private:
    string user_name;
    string user_id;
    GuestType user_role;
    list<string> borrowedBooks;

public:
    User() :user_name(" "), user_id(" "), user_role() {}
    User(const string& name, const string& id, GuestType role)
        : user_name(name), user_id(id), user_role(role) {}

    int GetMaxBorrowBook() const {
        switch (user_role) {
        case STUDENT: return 5;
        case FACULTY: return 10;
        case GUEST: return 3;
        default: return 0;
        }
    }

    int GetBorrowDays() const {
        switch (user_role) {
        case STUDENT: return 14;
        case FACULTY: return 30;
        case GUEST: return 7;
        default: return 0;
        }
    }

    double GetFinePerDay() const {
        switch (user_role) {
        case STUDENT: return 0.5;
        case FACULTY: return 0.3;
        case GUEST: return 1.0;
        default: return 0;
        }
    }

    string GetUserName() {
        return user_name;
    }

    string GetUserId() {
        return user_id;
    }

    GuestType GetUserRole() {
        return user_role;
    }

    void SetUserName(string us_name) {
        user_name = us_name;
    }

    void BorrowBook(string book_id) {
        borrowedBooks.push_back(book_id);
    }

    void ReturnBook(string book_id) {
        borrowedBooks.remove(book_id);
    }

    bool HasBook(string book_id) {
        for (const auto& book : borrowedBooks) {
            if (book == book_id) {
                return true;
            }
        }
        return false;
    }

    bool CanBorrow() {
        return borrowedBooks.size() < static_cast<size_t>(GetMaxBorrowBook());
    }

    int GetBorrowedBooksCount() {
        return borrowedBooks.size();
    }
};

#endif // USER_H}