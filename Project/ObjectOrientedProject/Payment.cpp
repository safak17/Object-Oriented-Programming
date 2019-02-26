#include "Payment.h"


/*!
\return The amount.
*/
//!Returns the amount
double Payment::getAmount() const
{
	return amount;//Return amount
}
/*!
\param amount an double argument.
*/
//!Sets the amount
void Payment::setAmount(double amount)
{
	this->amount=amount;//Set amount
}

//!Payment class constructor
Payment::Payment()
{
}
//!Payment class destructor
Payment::~Payment()
{
}
