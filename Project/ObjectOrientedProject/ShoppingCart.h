#ifndef ShoppingCart_h
#define ShoppingCart_h
#include <iostream>
#include <sstream>
#include <list>
#include "ProductToPurchase.h"
#include "Customer.h"
#include "Payment.h"
#include "Product.h"
#include "Cash.h"
using namespace std;
#pragma once
/**
 * @file   ShoppingCart.h
 * @Author Azmi Cibi (azmicibi@gmail.com)
 * @date   January, 2016
 * @brief  Header File of ShoppingCart Class.
 * paymentMethod(Payment*), customer(Customer*) and isBonusUsed(bool) are the private members of it.
 * There is also a container called productsToPurchase which keeps the ProductToPurchase* type variables in it. */



//! ShoppingCart Class.
class ShoppingCart
{
private:
	list <ProductToPurchase*> productsToPurchase;
	Payment* paymentMethod;
	Customer* customer;
	bool isBonusUsed;
    double amount;
public:
    
    //! Returns the paymentMethod. (Accessor Function, should be const.)
	Payment * getPaymentMethod()const;
    
    //! Sets the paymentMethod according to the given "paymentMethod".
	void setPaymentMethod(Payment * paymentMethod);
    
    //! Returns the customer. (Accessor Function, should be const.)
	Customer * getCustomer()const;
    
    //! Sets the customer according to the given "customer".
	void setCustomer(Customer* customer);
    
    //! isBonusUsed will be true.
	void setBonusUsed();
    
	//! Returns the amount! (Accessor Function, should be const).
    double getAmount()const;
    
    //! Sets the amount according to the given "amount"!
	void setAmount(double amount);
	
    //! given "product" will be added to the container.
	void addProduct(Product * product, int quantity);
    
    //! Product at given index will be removed from the container.
    bool removeProduct(int index);
    
    //! Performs payment. 
	void placeOrder();
    
    //! productsToPurchase will be empty.
	void cancelOrder();
    
    //! Orders will print to console.
	void printProducts();
    
    //! Shows the invoice to console.
	void showInvoice();
    
    //! Checks the productsToPurchase container is empty. (Accessor Function, should be const.)
    bool isEmpty() const;
    
    //! Constructor Function of ShoppingCart Class.
	ShoppingCart();
    
    //! Destructor Function of ShoppingCart Class.
	~ShoppingCart();
};

#endif
