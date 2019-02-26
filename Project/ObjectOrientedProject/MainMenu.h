/**
* @file MainMenu.h
* @Author Kerem Yaldýz (keremyaldiz@gmail.com)
* @date   January, 2016
* @brief  Header File of MainMenu Class.
*
* Header that everything chosen in its functions.
*/
#ifndef MainMenu_h
#define MainMenu_h
#include<vector>
#include<string>
#include <iostream>
#include"Customer.h"
#include"Book.h"
#include"Magazine.h"
#include"MusicCD.h"
#include"CreditCard.h"
#include "ShoppingCart.h"
#include"Cash.h"
#include"Check.h"
#include "Product.h"

//! A MainMenu class.
/*!
	Private scope in this class contains vectors that keeps customers and products in it. Public scope in this class contains menu functions, function which writes changes to text file and some order operations.
*/

class MainMenu
{
private:
  //! Vector which stores customer list.
  vector <Customer*> m_customerList;
  //! Vector which stores book list.
  vector <Product*> m_bookList;
  //! Vector which stores magazine list.
  vector <Product*> m_magazineList;
  //! Vector which stores music list.
  vector <Product*> m_musicCDList;

public:

	//! A constructor.
	MainMenu();

	//! A Destructor.
	~MainMenu();

	//! A fuction that writes customer list to text file.
  void AddToSource(Customer *);
  //! A function that prints list menu.
  void ListMenu();
  //! A function that prints customer menu.
  void CustomerMenu();
  //! A function that print items menu.
  void ItemMenu();
  //! A function that  prints shopping menu.
  void ShoppingMenu();
  //! A function that  prints addproduct menu.
  void AddProductMenu();
  //! A function that adds customer.
  void AddCustomer();
  //! A function that adds product to shopping cart.
  void AddProductoCart(ShoppingCart *);
  //! A function that removes product from shopping cart.
  void RemoveProducFromCart(ShoppingCart *);
  //! A function that places order.
  void PlaceOrder(ShoppingCart *);
};

#endif
