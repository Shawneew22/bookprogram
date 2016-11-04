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
		return "Wishlist"
	}
	else
	{
		return "?"
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



int main()
{

}