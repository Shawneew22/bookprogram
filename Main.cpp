#include <iostream>
#include <string>
using namespace std;

enum ReadingStatus { NOT_STARTED = 0, READING = 1, FINISHED = 2 };
enum PurchaseStatus { OWNED = 0, WISHLIST = 1 };

struct Book
{
	string title;
	string author;
	ReadingStatus readingStatus;
	PurchaseStatus purchaseStatus;
};

string ReadingStatusString(ReadingStatus rs)
{
	if (rs == NOT_STARTED)
	{
		return "Not Started";
	}
	else if (rs == READING)
	{
		return "Reading";
	}
	else if (rs == FINISHED)
	{
		return "Finished";
	}
	else 
	{
		return "?";
	}
}

string PurchaseStatusString(PurchaseStatus ps)
{
	if (ps == OWNED)
	{
		return "Owned";
	}
	else if (ps == WISHLIST)
	{
		return "Wishlist";
	}
	else
	{
		return "?";
	}
}

void SetBook(Book& book, string title, string author, PurchaseStatus ps, ReadingStatus rs)
{
	book.title = title;
	book.author = author;
	book.purchaseStatus = ps;
	book.readingStatus = rs;
}

void DisplayBook(Book book)
{
	cout << book.readingStatus << book.title << book.author << book.purchaseStatus << endl;
}

int GetValidInput(int min, int max)
{
	int choice;
	cout << "Input >>" << endl;
	cin >> choice;

	while (choice < min || choice > max)
	{
		cout << "Please enter a valid choice: " << endl;
		cin >> choice;
	}
	cin.ignore();
	return choice;
}

void AddBookMenu(Book books[100], int& bookCount)
{
	string title;
	string author;
	int ps;
	int rs;
	cout << "Please enter a title: " << endl;
	getline(cin, title);
	cout << "Please enter an author: " << endl;
	getline(cin, author);

	cout << endl << "Purchase Status:" << endl;
	cout << "\t" << OWNED << ". " << PurchaseStatusString(OWNED) << endl;
	cout << "\t" << WISHLIST << ". " << PurchaseStatusString(WISHLIST) << endl;
	ps = GetValidInput(OWNED, WISHLIST);
	
	cout << endl << "Reading Status:" << endl;
	cout << "\t" << NOT_STARTED << ". " << ReadingStatus(NOT_STARTED) << endl;
	cout << "\t" << READING << ". " << ReadingStatus(READING)<< endl;
	cout << "\t" << FINISHED << ". " << ReadingStatus(FINISHED) << endl;
	rs = GetValidInput(NOT_STARTED, FINISHED);

	SetBook(books[bookCount], title, author, (PurchaseStatus)ps, (ReadingStatus)rs);
	bookCount++;
}

void DisplayBookList(Book books[], int BookCount)
{
	for (int i = 0; i < BookCount; i++)
	{
		cout << i << ". ";
		DisplayBook(books[i]);
	}
}

void UpdateBookMenu(Book books[100], int& bookCount)
{
	cout << DisplayBookList << endl;
	cout << "What would you like to update?" << endl;
	int index;
	cin << index;
	index = GetValidInput(index, bookCount);
	string title = books[index].title;
	string author = books[index].author;
	PurchaseStatus ps = books[index].purchaseStatus;
	ReadingStatus rs = books[index].readingStatus;

	cout << "1. Update title." << endl;
	cout << "2. Update author." << endl;
	cout << "3. Update purchase status." << endl;
	cout << "4. Update reading status." << endl;

	if (GetValidInput == 1)
	{
		cout << "Please enter Book title >>" << endl;
		getline(cin, title);
		SetBook(books[index], title, author, (PurchaseStatus)ps, (ReadingStatus)rs); //asdfasf
}


int main()
{
	
	Book books[100];
	int bookCount = 0;

	return 0;
}