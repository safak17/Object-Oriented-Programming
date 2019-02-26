/*!
 * @file   Book.cpp
 * @Author Azmi Cibi (azmicibi@gmail.com)
 * @date   13 January, 2017
 * @brief  .cpp File of Book Class.
 */

#include "Book.h"       //! To know function prototypes of Book Class.

//! Book Class' Constructor Function with parameters.
//! It has to call its base Class Constructor Function (Product)
//! \param ID int
//! \param name string
//! \param price double
//! \param author string
//! \param publisher string
//! \param page int
Book::Book(int ID, string name, double price, string author, string publisher, int page) :Product(ID, name, price)
{
	this->author = author;
	this->publisher = publisher;
	this->page = page;
}

//! Destructor Function of Book Class.
Book::~Book()
{
}

//! Prints the Book's properties to console.
void Book::printProperties()
{
	cout <<left<<"|"<<setw(5)<<this->getID() << "|" << setw(25) << this->getName() << "|"<<setw(30)<<author
		<< "|" << setw(20) << publisher <<"|"<< setw(5) << page <<"|"<< setw(5) << this->getPrice()<<"|" << endl
		<< "-------------------------------------------------------------------------------------------------" << endl;
}

//! Returns the Book's author. (Accessor Function, should be const)
//! \return author const string.
string Book::getAuthor() const
{
	return author;
}

//! Sets the Book's author according to the given "author".
//! \param author string.
void Book::setAuthor(string author)
{
	this->author = author;
}

//! Returns the Book's publisher. (Accessor Function, should be const)
//! \return publisher const string.
string Book::getPublisher() const
{
	return publisher;
}

//! Sets the Book's publisher according to the given "publisher".
//! \param publisher string.
void Book::setPublisher(string publisher)
{
	this->publisher = publisher;
}

//! Returns the Book's page. (Accessor Function, should be const)
//! \return page const int.
int Book::getPage()const
{
	return page;
}

//! Sets the Book's page according to the given "page".
//! \param page int.
void Book::setPage(int page)
{
	this->page = page;
}
