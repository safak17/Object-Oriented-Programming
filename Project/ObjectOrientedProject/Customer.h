/*!
 * @file        Customer.h
 * @Author      Safak Akinci (safakakinci17@gmail.com)
 * @date        13 January, 2017
 * @brief       Header File of Customer Class.
 */

/*!
 This is a preprocessor technique of preventing a header file from being included multiple times,
 which can be problematic for various reasons.
 
 #ifndef Customer_h
 #define Customer_h
 #endif
 */
#ifndef Customer_h
#define Customer_h

#include <iostream>         //! To use standart input and output functions which are cin and cout.
#include <string>           //! To declare variables string type.
using namespace std;        //! To use string variables under the std namespace.


//! Customer Class.
class Customer
{
    
//! Private variables of the class CANNOT BE ACCESSED the out of the class.
private:
    //! Unique id for each customer. (It will assign at AddCustomer Function in Main Menu)
    long customerID;
    
    //! Customer's name.
    string name;
    
    //! Customer's address.
    string address;
    
    //! Customer's phone number.
    string phone;
    
    //! Customer's bonus.
    //! Each customer earns bonus as 5% of the amount of each shopping.
    double bonus;
    
    //! Customer's email.
    string email;
    
    
    
//**    The customer may shop after entering his username and password.     **//
    //! Customer's username.
    string username;
    
    //! Customer's password.
    string password;
    
//! Public variables CAN BE ACCESSED the out of the class.
public:
    
    //! Constructor Function with parameters.
    Customer(long ID, string name, string address, string phone, double bonus, string email, string username,string password);
    
    //! Destructor function.
    ~Customer();
    
    
    //! Sets the customerID.
    void setCustomerID(long customerID);
    //! Returns the customerID which declared PRIVATE.
    long getCustomerID() const;
    
    
    //! Sets the name.
    void setName(string name);
    //! Returns the name which declared PRIVATE.
    string getName() const;
    
    
    //! Sets the address.
    void setAddress(string address);
    //! Returns the name which declared PRIVATE.
    string getAddress() const;
    
    
    //! Sets the phone number.
    void setPhone(string phone);
    //! Returns the phone which declared PRIVATE.
    string getPhone() const;
    
    
    //! Sets the email.
    void setEmail (string email);
    //! Returns the email which declared PRIVATE.
    string getEmail () const;
    
    
    //! Sets the username.
    void setUsername(string username);
    //! Returns the userName which declared PRIVATE.
    string getUsername() const;

    //! Sets the password.
    void setPassword (string password);
    //! Returns the password which declared PRIVATE.
    string getPassword () const;
    
    //! Checks whether there is an account(given username and password) or not.
    bool checkAccount (string username, string password) const;
    
    
    //The customer use his bonus next shopping or save it.
    //! Sets the bonus.
    void setBonus(double bonus);
    //! Returns the bonus which declared PRIVATE.
    double getBonus() const;
    //! Adds bonus.
    void addBonus(double amount);
    //! Uses(Subtract) bonus.
	void useBonus(double& amount);

    
    //! Bill will print to console.
    void sendBill() const;
};

#endif /* Customer_h */
