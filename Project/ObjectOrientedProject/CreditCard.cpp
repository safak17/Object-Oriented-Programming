#include "CreditCard.h"

//!CreditCard constructor
CreditCard::CreditCard() :Payment()
{
}

//!CreditCard destructor
CreditCard::~CreditCard()
{
}

/*!
\return The number
*/
//!Returns the number
long CreditCard::getNumber() const
{
	return number;//Return number
}
/*!
\param number a long argument.
*/
//!Sets the number
void CreditCard::setNumber(long number)
{
	this->number = number;//Set number
}
/*!
\return The type
*/
//!Returns the Type
string CreditCard::getType() const
{
	return type;//Return type
}
/*!
\param type a string argument.
*/
//!Sets the Type
void CreditCard::setType(string type)
{
	this->type = type;//Set type
}
/*!
\return The expDate
*/
//!Returns the expDate
string CreditCard::getExpDate() const
{
	return expDate;//Return expDate
}
/*!
\param expDate a string argument.
*/
//!Sets the expDate
void CreditCard::setExpDate(string expDate)
{
	this->expDate = expDate;//Set expDate
}
//!CreditCard class prints that payment is done
void CreditCard::performPayment()
{
	cout << "Payment made by Credit Card.Thank you for choosing us." << endl;//Output
}
