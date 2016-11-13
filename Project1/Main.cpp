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
cout << book.title << "\n by " << book.author << "\t Purchase: " << PurchaseStatusString(book.purchaseStatus) << "\t Reading: " << ReadingStatusString(book.readingStatus) << endl;

}

int GetValidInput(int min, int max)
{
	int choice;
	cout << " >> " << endl;
	cin >> choice;

		while (choice < min || choice > max)
		{
			cout << "Invalid input! " << endl;
			cin >> choice;
		}
		cin.ignore();
		return choice;
}

void AddbookMenu(Book books[100], int& bookCount)
{
	string title;
	string author;
	int ps;
	int rs;
	cout << "Please enter the title of the book >>" << endl;
	getline(cin, title);
	cout << "Please enter the Author >>" << endl;
	getline(cin, author);

	cout << "Purchase status: 0 = Owned, 1 = Wishlist " << endl;
	ps = GetValidInput(OWNED, WISHLIST);
	cout << "Reading status: 0 = not started, 1 = reading, 2 = finished " << endl; 
	rs = GetValidInput(NOT_STARTED, FINISHED);
	books[bookCount].purchaseStatus = (PurchaseStatus)ps;
	books[bookCount].readingStatus = (ReadingStatus)rs;
	books[bookCount].title = title;
	books[bookCount].author = author;
	bookCount++;

	SetBook(books[bookCount], title, author, (PurchaseStatus)ps, (ReadingStatus)rs);
}

void DisplayBookList(Book books[100], int bookCount)
{
	for (int i = 0; i < bookCount; i++)
	{
		cout << i << endl;
		DisplayBook(books[i]);
		
	}
}

void UpdateBookMenu(Book books[100], int& bookCount)
{
	DisplayBookList(books, bookCount);
	cout << "What would you like to update? " << endl;
	int index;
	index = GetValidInput(0, bookCount);
	string title = books[index].title;
	string author = books[index].author;
	PurchaseStatus ps = books[index].purchaseStatus;
	ReadingStatus rs = books[index].readingStatus;
	cout << "1. Update title" << endl;
	cout << "2. Update author" << endl;
	cout << "3. Update purchase status" << endl;
	cout << "4. Update reading status" << endl;
	int choice;
	choice = GetValidInput(1, 4);
	
	if (choice == 1)
	{
		cout << "What is the new title?" << endl;
		getline(cin, title);
	}
	else if (choice == 2)
	{
		cout << "What is the name of the author?" << endl;
		getline(cin, author);
	}
	else if (choice == 3)
	{
		cout << "What is the purchase Status?" << endl;
		cout << OWNED << "or" << PurchaseStatusString(OWNED) << endl;
		cout << WISHLIST << " " << PurchaseStatusString(WISHLIST) << endl;

		SetBook(books[index], title, author, (PurchaseStatus)ps, (ReadingStatus)rs);
	}
	else if (choice == 4)
	{
		cout << "What is the reading status?" << endl;
		cout << NOT_STARTED << " " << ReadingStatusString(NOT_STARTED) << endl;
		cout << READING << " " << ReadingStatusString(READING) << endl;
		cout << FINISHED << " " << ReadingStatusString(FINISHED) << endl;

		SetBook(books[index], title, author, (PurchaseStatus)ps, (ReadingStatus)rs);
	}
	else
	{
		cout << "Invalid choice!" << endl;
	}
}


void mainMenu(Book books[100], int& bookCount)

{
	cout << "1. Add book" << "\n 2. Update book" << "\n 3. Display book list" << "\n 4. Quit" << endl;
	int choice;
	choice = GetValidInput(1, 4);
	bool done = false;

	while (done != true && choice < 4)
	{
		if (choice == 1)
		{
			AddbookMenu(books,bookCount);
		}

		else if (choice == 2)
		{
			UpdateBookMenu(books, bookCount);
		}
		else if (choice == 3)
		{
			DisplayBookList(books, bookCount);
		}
		else if (choice == 4)
		{
			done = true;
		}
	}
}





int main()
{
	Book books[100];
	int bookCount = 0;
	Book bookA, bookB, bookC, bookD, bookE, bookF;
	

	DisplayBook(bookA);
	DisplayBook(bookB);
	DisplayBook(bookC);
	DisplayBook(bookD);
	DisplayBook(bookE);
	DisplayBook(bookF);
	UpdateBookMenu;
	return 0;
}