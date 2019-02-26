#ifndef Cash_h
#define Cash_h
#include "Payment.h"

/**
 * @file   Cash.h
 * @Author Kerem Yald�z (keremyaldiz@gmail.com)
 * @date   13 January, 2017
 * @brief  Header File of Book Class.
 * Cash Class is derived from Payment Class.
 * It hasn't got any member variables but performPayment Function*/


//! Cash class. (Polymorphic Class)
/*!
It inherits Payment's member variables.
*/
class Cash :
	public Payment
{
public:

    //! A fuction that performs payment.
	void performPayment();

    //! A constructor.
	Cash();

    //! A destructor.
	~Cash();
};
#endif
