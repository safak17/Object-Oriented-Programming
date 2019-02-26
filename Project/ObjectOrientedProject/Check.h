#ifndef Check_h
#define Check_h
#include "Payment.h"

/**
 * @file   Check.h
 * @Author Kerem Yald�z (keremyaldiz@gmail.com)
 * @date   13 January, 2017
 * @brief  Header File of Check Class.
 * Check Class is derived from Payment Class.
 * name (string) and bankID(string) are the private members of it. */



//! Check class. (Polymorphic Class)
/*!
It inherits Payment's member variables.
*/
class Check :
	public Payment
{
private:
	//! String which stores name.
	string name;
	//! String which stores bankID.
	string bankID;
public:

    //! A function that performs payment.
	void performPayment();

    //! A function that returns name.
	string getName()const;

    //! A fuction that sets name.
	void setName(string name);

    //! A function that returns bankID.
	string getBankID()const;

    //! A function that sets bankID.
	void setBankID(string bankID);

    //! A constructor.
	Check();

    //! A destructor.
	~Check();
};

#endif
