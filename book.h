#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string.h>
using namespace std;
class BooksList {
private:
	string book_name;
	string author;
	string book_id;
	string borrower_id;
	bool available_book;
public:
	BooksList()
	{
		book_name = nullptr;
		author = nullptr;
		book_id = nullptr;
		borrower_id = nullptr; 
		available_book = 1;
	}
	BooksList(string n, string a, string i)
	{
		book_name = n;
		author = a;
		book_id = i;
		borrower_id = nullptr;
		available_book = 1;
	}
	void SetBookName(string bn) {
		book_name = bn;
	}
	void SetAuthor(string auth) {
		author = auth;
	}
	void SetBookId(string bk_id) {
		book_id = bk_id;
	}
	void SetBorrowerId(string bwer_id) {
		borrower_id = bwer_id;
		available_book = bwer_id.empty();
	}
	void SetAvailable(bool available) {
		available_book = available;
		if (available)
			borrower_id = nullptr;
	}
	bool IsAvailable() {
		return available_book;
	}
	string BookNameGet() {
		return book_name;
	}
	string AuthorGet() {
		return author;
	}
	string BookIdGet() {
		return book_id;
	}
	string BorrowerIdGet() {
		return borrower_id;
	}

};
#endif // BOOK_H
