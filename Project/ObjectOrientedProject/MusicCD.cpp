/*!
 * @file   MusicCD.cpp
 * @Author Azmi Cibi (azmicibi@gmail.com)
 * @date   13 January, 2017
 * @brief  .cpp File of MusicCD Class.
 */

#include "MusicCD.h"        //! To know function prototypes of MusicCD Class.

//! MusicCD's Construcor Function with parameters.
//! It has to call its base Class Constructor Function (Product)
//! \param ID int
//! \param name string
//! \param price double
//! \param singer string
//! \param tpye string
MusicCD::MusicCD(int ID, string name, double price, string singer, string type):Product(ID,name,price),singer(singer),type(type)
{

}

//! Destructor Function of MusicCD Class.
MusicCD::~MusicCD()
{

}

//! Returns the MusicCD's singer. (Accessor Function, should be const)
//! \return singer const string.
string MusicCD::getSinger() const
{
    return singer;
}

//! Sets the MusicCD's singer according to the given "singer".
//! \param singer string.
void MusicCD::setSinger(string singer)
{
    (*this).singer = singer;
}

//! Returns the MusicCD's type. (Accessor Function, should be const)
//! \return type const string.
string MusicCD::getType() const
{
    return type;
}

//! Sets the MusicCD's type according to the given "type".
//! \param type string.
void MusicCD::setType(string type)
{
    (*this).type = type;
}

//! Prints the MusicCD's properties to console (It is pure virtual function which declared in Product Class).
void MusicCD::printProperties()
{
	cout << "|" << setw(5) << this->getID() << "|" << setw(25) << this->getName() << "|" << setw(30) << singer << "|" << setw(20) << type << "|" << setw(11) << this->getPrice() << "|" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
}
