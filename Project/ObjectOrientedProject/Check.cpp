#include "Check.h"

//!Check class prints that payment is done
void Check::performPayment()
{
	cout << "Payment made by Check.Thank you for choosing us." << endl;//Output
}
/*!
\return The name
*/
//!Returns the name
string Check::getName() const
{
	return name;//Return name
}
/*!
\param name a string argument.
*/
//!Sets the name
void Check::setName(string name)
{
	this->name = name;//Set name
}
/*!
\return The bankID
*/
//!Returns the bankID
string Check::getBankID() const
{
	return bankID;//Return bankID
}
/*!
\param bankID a string argument.
*/
//!Sets the bankID
void Check::setBankID(string bankID)
{
	this->bankID = bankID;//Set bankID
}
//!Check class constructor
Check::Check()
{
}
//Check class destructor
Check::~Check()
{
}
