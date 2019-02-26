/*!
 * @file   MusicCD.h
 * @Author Azmi Cibi (azmicibi@gmail.com)
 * @date   13 January, 2017
 * @brief  Header File of MusicCD Class.
 */


/*!
 This is a preprocessor technique of preventing a header file from being included multiple times,
 which can be problematic for various reasons.
 
 #ifndef Product_h
 #define Product_h
 #endif
 */
#ifndef MusicCD_h
#define MusicCD_h

#include "Product.h"        //! To derive MusicCD class from Product Class.


//! MusicCD class. (Polymorphic Class)
/*! MusicCD class inherits functions and variables from Product Class. */
class MusicCD:public Product
{
//! Private variables of the class CANNOT BE ACCESSED the out of the class.
private:
    //! MusicCD's singer.
    string singer;
    //! MusicCD's type.
    string type;

//! Public variables of the class ARE ACCESSED the out of the class.
public:

    //! MusicCD's Construcor Function with parameters.
    MusicCD(int ID, string name, double price, string singer, string type);

    //! Destructor Function of MusicCD Class.
    ~MusicCD();

    //! Returns the MusicCD's singer. (Accessor Function, should be const)
    string getSinger() const;
    //! Sets the MusicCD's singer according to the given "singer".
    void setSinger(string singer);

    
    //! Returns the MusicCD's type. (Accessor Function, should be const)
    string getType() const;
    //! Sets the MusicCD's type according to the given "type".
    void setType(string type);

    //! Prints the MusicCD's properties to console (It is pure virtual function which declared in Product Class).
    void printProperties();
};



#endif /* MusicCD_h */
