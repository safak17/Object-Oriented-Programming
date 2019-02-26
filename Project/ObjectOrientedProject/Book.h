/*!
 * @file   Book.h
 * @Author Azmi Cibi (azmicibi@gmail.com)
 * @date   13 January, 2017
 * @brief  Header File of Book Class.
 */


/*!
 This is a preprocessor technique of preventing a header file from being included multiple times,
 which can be problematic for various reasons.
 
 #ifndef Product_h
 #define Product_h
 #endif
 */
#ifndef  Book_h
#define Book_h
#include "Product.h"    //! To derive Book Class from Product Class as public.


//! Book class. (Polymorphic Class)
/*! It inherits Product's member variables. */
class Book:public Product
{
//! Private variables of the class CANNOT BE ACCESSED the out of the class.
private:
    //! Book's author.
    string author;
    //! Book's publisher.
    string publisher;
    //! Book's page.
    int page;
    
//! Public variables of the class ARE ACCESSED the out of the class.
public:
    
    //! Prints the Book's properties to console (It is pure virtual function which declared in Product Class).
    void printProperties();
    
    
    //! Returns the Book's author. (Accessor Function, should be const)
    string getAuthor()const;
    //! Sets the Book's author according to the given "author".
    void setAuthor(string author);
    
    
    //! Returns the Book's author. (Accessor Function, should be const)
    string getPublisher()const;
    //! Sets the Book's publisher according to the given "publisher".
    void setPublisher(string publisher);
    
    
    //! Returns the Book's page. (Accessor Function, should be const)
    int getPage() const;
    //! Sets the Book's page according to the given "page".
    void setPage(int page);
    
    
    //! Book Class' Constructor Function with parameters.
	Book(int ID, string name, double price, string author, string publisher, int page);
    
    //! Destructor Function of Book Class.
    ~Book();
};

#endif
