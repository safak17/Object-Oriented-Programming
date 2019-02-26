/*!
 * @file   Magazine.cpp
 * @Author Azmi Cibi (azmicibi@gmail.com)
 * @date   13 January, 2017
 * @brief  .cpp File of Magazine Class.
 */

#include "Magazine.h"       //! To know function prototypes of Magazine Class.

//! Magazine Class' Constructor Function with parameters.
//! It has to call its base Class Constructor Function (Product)
//! \param ID int
//! \param name string
//! \param price double
//! \param Issue int
//! \param type string
Magazine::Magazine(int ID , string name, double price, int Issue, string type ):Product(ID,name,price), Issue(Issue),type(type)
{

}

//! Destructor Function of Magazine Class.
Magazine::~Magazine()
{

}

//! It is pure virtual function in Product Class.
//! Prints the Magazine's properties to console.
void Magazine::printProperties()
{
	cout << "|" << setw(5) << this->getID() << "|" << setw(25) << this->getName() << "|" << setw(30) << type
		<< "|" << setw(20) << Issue << "|" << setw(11) << this->getPrice() << "|" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
}

//! Returns the Magazine's Issue. (Accessor Function, should be const)
//! \return Issue const int.
int Magazine::getIssue() const
{
    return Issue;
}

//! Sets the Magazine's Issue according to the given "Issue".
//! \param Issue int.
void Magazine::setIssue(int Issue)
{
    (*this).Issue = Issue;
}

//! Returns the Magazine's type. (Accessor Function, should be const)
//! \return type const string.
string Magazine::getType() const
{
    return type;
}

//! Sets the Magazine's type according to the given "type".
//! \param type string.
void Magazine::setType(string type)
{
    (*this).type = type;
}
