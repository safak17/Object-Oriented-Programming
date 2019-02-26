/*!
 * @file   Product.h
 * @Author Azmi Cibi (azmicibi@gmail.com)
 * @date   13 January, 2017
 * @brief  Header File of Book Class(ABSTRACT BASE CLASS).
 */

/*!
 This is a preprocessor technique of preventing a header file from being included multiple times,
 which can be problematic for various reasons.
 
 #ifndef Product_h
 #define Product_h
 #endif
 */
#ifndef Product_h
#define Product_h

#include <iostream>         //! To use cin and cout functions.
#include <string>           //! To declare string type variables.
#include <iomanip>          //! To use setw() functions.
using namespace std;        //! To declare string type variables under std namespace.

//! Product Class is ABSTRACT CLASS because of the Pure Virtual Functions.
class Product
{
//! Private variables of the class CANNOT BE ACCESSED the out of the class.
private:
    //! Product's ID.
    int ID;
    
    //! Product's name.
    string name;
    
    //! Product's price.
    double price;
    
//Public variables CAN BE ACCESSED the out of the class.
public:

    //! Product's Class Constructor Function with Parameters.
    Product(int ID, string name, double price);

    //! Product's VIRTUAL Destructor Function.
    //! Being VIRTUAL ensures that, when an object that is created from any derived classes is removing, it should call its base class' destructor function.
    virtual ~Product();
    
    //! Returns the ID which declared PRIVATE as const.
    int getID() const;
    //! Sets the ID.
    void setID(int ID);
    
    //! Returns the name which declared PRIVATE as const.
    string getName() const;
    //! Sets the name.
    void setName(string name);
    
    //! Returns the price which declared PRIVATE as const.
    double getPrice() const;
    //! Sets the price.
    void setPrice(double price);

    //! Pure Virtual Function makes the Product Class ABSTRACT which means we can not create an object by using this class.
    //! All the derived classes must implemet(include) this function.
    virtual void printProperties() =0;
	
};


#endif /* Product_h */
