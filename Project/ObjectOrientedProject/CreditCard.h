#ifndef CreditCard_h
#define CreditCard_h
#include "Payment.h"


/**
 * @file   CreditCard.h
 * @Author Kerem Yald�z (keremyaldiz@gmail.com)
 * @date   13 January, 2017
 * @brief  Header File of CreditCard Class.
 * CreditCard Class is derived from Payment Class.
 * number (long), type(string) and expDate(string) are the private members of it. */



//! CreditCard class. (Polymorphic Class)
/*! It inherits Payment's member variables. */
class CreditCard :
	public Payment
{
private:
	//! Long which stores number.
	long number;
	//! String which stores type.
	string type;
	//! String which stores expiration date.
	string expDate;
public:

    //! A function that returns number.
	long getNumber()const;

    //! A function that sets number.
	void setNumber(long number);


	//! A function that returns type.
	string getType()const;

	//! A function that sets type.
	void setType(string type);

	//! A function that returns expiration.
	string getExpDate()const;

	//! A function that sets expiration date.
	void setExpDate(string expDate);

    //! A function that performs payment.
	void performPayment();

    //! A constructor.
	CreditCard();

    //! A destructor.
	~CreditCard();
};
#endif
