#ifndef Payment_h
#define Payment_h
#pragma once
#include <iostream>
#include <string>
using namespace std;

/**
 * @file   Payment.h
 * @Author Kerem Yald�z (keremyaldiz@gmail.com)
 * @date   13 January, 2017
 * @brief  Header File of Payment Class.
 * amount(double) is private member of it.*/



//! Payment class.
//! Payment Class is ABSTRACT CLASS because of the Pure Virtual Functions.
class Payment {
private:
	//! Double which stores amount.
	double amount;
public:

	//! A function that returns amount.
    double getAmount()const;

	//! A function that sets amount.
	void setAmount(double amount);

	//! A pure virtual function that performs payment.
	virtual void performPayment()=0;

    //! A constructor.
	Payment();

    //! A destructor.
	virtual ~Payment();

};

#endif
