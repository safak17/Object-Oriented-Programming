/*!
 * @file   ProductToPurchase.h
 * @Author Safak Akinci (safakakinci17@gmail.com)
 * @date   13 January, 2017
 * @brief  Header File of ProductToPurchase Class.
 */


#include "ProductToPurchase.h"          //! To know function prototypes of ProductToPurchase Class.

//! Returns the product. (Accessor Function, should be const)
//! \return product Product*
Product* ProductToPurchase::getProduct() const
{
	return product;
}

//! Sets the product according to the given "product".
//! \param product Product*
void ProductToPurchase::setProduct(Product* product)
{
	this->product = product;
}

//! Returns the quantity. (Accessor Function, should be const)
//! \return quantity int
int ProductToPurchase::getQuantity()
{
	return quantity;
}

//! Sets the quantity according to the given "quantity".
//! \param quantity int
void ProductToPurchase::setQuantity(int quantity)
{
	this->quantity = quantity;
}

//! Constructor Function of ProductToPurchase Class.
ProductToPurchase::ProductToPurchase()
{
}

//! Destructor Function of ProductToPurchase Class.
ProductToPurchase::~ProductToPurchase()
{
}
