/*!
 * @file   Magazine.h
 * @Author Azmi Cibi (azmicibi@gmail.com)
 * @date   13 January, 2017
 * @brief  Header File of Magazine Class.
 */

/*!
 This is a preprocessor technique of preventing a header file from being included multiple times,
 which can be problematic for various reasons.
 
 #ifndef Product_h
 #define Product_h
 #endif
 */
#ifndef Magazine_h
#define Magazine_h

#include "Product.h"        //! To derive Magazine Class from Product Class.



//! Magazine class. (Polymorphic Class)
/*! It inherits Product member variables. */

//! Magazine class inherits functions and variables from Product Class.
class Magazine:public Product
{
//! Private variables of the class CANNOT BE ACCESSED the out of the class.
private:
    //! Magazine's issue.
    int Issue;
    //! Magazine's type.
    string type;
    
//! Public variables of the class ARE ACCESSED the out of the class.
public:
    
    //! Magazine Class' Constructor Function with parameters.
    Magazine(int ID , string name, double price, int Issue, string type );

    //! Destructor Function of Magazine Class.
    ~Magazine();

    //! It is pure virtual function in Product Class.
    void printProperties();
    
    
    //! Returns the Magazine's Issue. (Accessor Function, should be const)
    int getIssue() const;
    //! Sets the Magazine's Issue according to the given "Issue".
    void setIssue(int Issue);

    
    //! Returns the Magazine's type. (Accessor Function, should be const)
    string getType() const;
    //! Sets the Magazine's type according to the given "type".
    void setType(string type);
};

#endif /* Magazine_h */
