#ifndef LIBRARY_USER_INTERFACE_H
#define LIBRARY_USER_INTERFACE_H
#include "iostream"
#include <string.h>
#include <List>
using namespace std;
class LibraryUserI {
public:
	virtual ~LibraryUserI() = default;

	virtual int GetMaxBorrowBook() const = 0;

	virtual int GetBorrowDays() const = 0;

	virtual double GetFinePerDay() const = 0;

	virtual list<string> GetUserBorrowList() const = 0;

	virtual void SetUserName(string name) = 0 ;

	virtual void BorrowBook(string book_id) = 0;
	virtual void ReturnBook(string book_id) = 0;
	virtual bool HasBook(string book_id) const = 0;

	virtual bool CanBorrow() const {
		return GetUserBorrowList().size() < static_cast<size_t>(GetMaxBorrowBook());
	}
};
#endif // LIBRARY_USER_INTERFACE_H
