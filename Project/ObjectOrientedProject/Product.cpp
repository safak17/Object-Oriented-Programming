/*!
 * @file   Product.cpp
 * @Author Azmi Cibi (azmicibi@gmail.com)
 * @date   13 January, 2017
 * @brief  .cpp File of Product Class.
 */

#include "Product.h"        //! To know function prototypes of Product Class.

//! Product's Class Constructor Function with Parameters.
//! \param ID int
//! \param name string
//! \param price double
Product::Product(int ID, string name, double price):ID(ID),name(name),price(price)
{

}

//! Product's VIRTUAL Destructor Function.
//! Being VIRTUAL ensures that, when an object that is created from any derived classes is removing, it should call its base class' destructor function.
Product::~Product()
{

}

//! getID is an accessor function (it won't change any member of the class), it should be const.
//! \return ID const int.
int Product::getID() const
{
    return ID;
}

//! Sets the ID.
//! \param ID int.
void Product::setID(int ID)
{
    (*this).ID = ID;
}

//! getName is an accessor function (it won't change any member of the class), it should be const.
//! \return name const string.
string Product::getName() const
{
    return name;
}

//! Sets the name.
//! \param name string.
void Product::setName(string name)
{
    (*this).name = name;
}

//! getPrice is an accessor function (it won't change any member of the class), it should be const.
//! \return price const double.
double Product::getPrice() const
{
    return price;
}

//! Sets the price.
//! \param price double.
void Product::setPrice(double price)
{
    (*this).price = price;
}
