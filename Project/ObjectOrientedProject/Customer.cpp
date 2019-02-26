/*!
 * @file        Customer.cpp
 * @Author      Safak Akinci (safakakinci17@gmail.com)
 * @date        13 January, 2017
 * @brief       .cpp File of Customer Class which contains implementation of functions.
 */

#include "Customer.h"           //! To know function prototypes of Customer Class.
#include <iomanip>              //! To use setw() function.


//! Sets the customerID.
//! \param customerID long.
void Customer::setCustomerID(long customerID)
{
    (*this).customerID = customerID;
}

//! Returns the customerID which declared PRIVATE.
//! getCustomerID is an accessor function (should be const), it won't change any variables of the class.
//! \return customerID const long.
long Customer::getCustomerID() const
{
    return customerID;
}

//! Sets the name.
//! \param name string.
void Customer::setName(string name)
{
    (*this).name = name;
}

//!Returns the name which declared PRIVATE.
//!getName is an accessor function (should be const), it won't change any variables of the class.
//! \return name const string.
string Customer::getName() const
{
    return name;
}

//! Sets the address.
//! \param address string.
void Customer::setAddress(string address)
{
    (*this).address = address;
}

//!Returns the address which declared PRIVATE.
//!getAddress is an accessor function (should be const), it won't change any variables of the class.
//! \return addres const string.
string Customer::getAddress() const
{
    return address;
}

//!Sets the phone.
//! \param phone string.
void Customer::setPhone(string phone)
{
    (*this).phone = phone;
}

//!Returns the phone which declared PRIVATE.
//!getPhone is an accessor function (should be const), it won't change any variables of the class.
//! \return phone const string.
string Customer::getPhone() const
{
    return phone;
}

//! Sets the email.
//! \param email string.
void Customer::setEmail(string email)
{
    (*this).email = email;
}

//!Returns the email which declared PRIVATE.
//!getEmail is an accessor function (should be const), it won't change any variables of the class.
//! \return email const string.
string Customer::getEmail() const
{
    return email;
}

//! Sets the username.
//! \param username string.
void Customer::setUsername(string username)
{
    (*this).username = username;
}

//!Returns the username which declared PRIVATE.
//!getUsername is an accessor function (should be const), it won't change any variables of the class.
//! \return username const string.
string Customer::getUsername() const
{
    return username;
}


//! Sets the password.
//! \param password string.
void Customer::setPassword(string password)
{
    (*this).password = password;
}

//!Returns the password which declared PRIVATE.
//!getPassword is an accessor function (should be const), it won't change any variables of the class.
//! \return password const string.
string Customer::getPassword() const
{
    return password;
}

//!Checks whether there is an account(given username and password) or not.
//!This function is an accessor function(should be const) too.
//! \param username string.
//! \param password string.
bool Customer::checkAccount(string username, string password) const
{
    return ( (*this).username==username && (*this).password == password )? true:false;
}

//!Sets the bonus.
//! \param bonus double.
void Customer::setBonus(double bonus)
{
    (*this).bonus = bonus;
}


//!Returns the bonus which declared PRIVATE.
//!getBonus is an accessor function (should be const), it won't change any variables of the class.
//! \return bonus const double.
double Customer::getBonus() const
{
    return bonus;
}

//! Adds bonus and prints it to console.
void Customer::addBonus(double bonus)
{
	(*this).bonus += bonus;

	cout << "You earned " << bonus << " bonus." << endl;
	cout << "Your current bonus is->" << this->bonus<<endl;

}

//! Uses(Subtract) bonus if amount is smaller than or equal to the bonus. Then prints the remaining.
void Customer::useBonus(double& amount)
{
    
	if (amount <= bonus)
    {
		 bonus -= amount;
		 cout << "You used " << amount << " bonus." << endl;
		 cout << "Your current bonus is->" << bonus << endl;
	}	
	else
    {
		amount -= bonus;
		cout << "You used " << bonus << " bonus." << endl;
		cout << "The rest of the Payment->" << amount << endl;
		bonus = 0;
	}	
}

//! Bill will print to console.
void Customer::sendBill() const
{
	cout
		<< "Name:" << setw(20) << name << endl
		<< "Address:" << setw(20) << address << endl
		<< "Phone:" << setw(20) << phone << endl
		<< "Email:" << setw(20) << email << endl;
}

//! Customer Class' Constructor Function with parameters.
//! Initialize all the members of the customer.
//! \param customerID long
//! \param name string
//! \param address string
//! \param phone string
//! \param bonus double
//! \param email string
//! \param username string
//! \param password string
Customer::Customer(long customerID, string name, string address, string phone, double bonus, string email, string username,string password)
{
	this->customerID = customerID;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->bonus = bonus;
	this->email = email;
	this->username = username;
	this->password = password;
}

//! Destructor Function of Customer Class.
Customer::~Customer()
{
  
}
