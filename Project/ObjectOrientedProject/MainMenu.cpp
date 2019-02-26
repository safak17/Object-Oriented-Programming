#include"MainMenu.h"        //To know function prototypes of MainMenu Class.
#include <iomanip>			//To use setw() function.
#include <fstream>
using namespace std;


//!Constructor function of MainMenu object.
MainMenu::MainMenu()
{
	//Creating books  and adding to book container
	Book* new_book;

	new_book = new Book(1, "The Art Of War", 10, "Sun Tzu", "Pergamino", 120);
	m_bookList.push_back(new_book);

	new_book = new Book(2, "Why Nations Fail", 37.41, "Daron Acemoglu-James Robinson", "Profile Books", 560);
	m_bookList.push_back(new_book);

	new_book = new Book(3, "The Little Prince", 6.57, "Antoine de Saint-Exupery", "Destek Yayinlari", 128);
	m_bookList.push_back(new_book);


	// Creating musicCDs and adding to musicCD container
	MusicCD* new_musicCD;
	new_musicCD = new MusicCD(1, "He Touched Me", 52.39, "Elvis Presley", "Country Jazz");
	m_musicCDList.push_back(new_musicCD);

	new_musicCD = new MusicCD(2, "Yeni Sarkilar", 16.49, "Fazil Say", "Classic");
	m_musicCDList.push_back(new_musicCD);

	// Creating magazines and adding to magazine container
	Magazine* new_magazine;

	new_magazine = new Magazine(1, "Cyclist", 11, 1, "Sport");
	m_magazineList.push_back(new_magazine);

	new_magazine = new Magazine(2, "StartUp", 12, 2, "Entrepreneurship");
	m_magazineList.push_back(new_magazine);
	try {//Reading customer information from Customer.txt source file
		ifstream file("Customer.txt");
		if (file.is_open()) {
			while (!file.eof()) {
				string line,ID, name, username, password, phone, email, address, bonus;
				getline(file, line);//Gets a line from text

                int i = 0;
				while (line[i] != '$') {//Reads ID of customer at the line
					ID += line[i];
					i++;
				}
				i++;
				while (line[i] != '$') {//Reads name of customer at the line
					name += line[i];
					i++;
				}
				i++;
				while (line[i] != '$') {//Reads address of customer at the line
					address += line[i];
					i++;
				}
				i++;
				while (line[i] != '$') {//Reads phone of customer at the line
					phone += line[i];
					i++;
				}
				i++;
				while (line[i] != '$') {//Reads bonus of customer at the line
					bonus += line[i];
					i++;
				}
				i++;
				while (line[i] != '$') {//Reads email of customer at the line
					email += line[i];
					i++;
				}
				i++;
				while (line[i] != '$') {//Reads username of customer at the line
					username += line[i];
					i++;
				}
				i++;
				while (line[i] != '$') {//Reads password of customer at the line
					password += line[i];
					i++;
				}
				i++;
				Customer *customer = new Customer((long)stoi(ID), name, address, phone,(double)stoi(bonus), email, username, password);//Creates a Customer object
				m_customerList.push_back(customer);//Adds new customer to the container
			}
			file.close();
		}
	}
	catch (exception) {

	}
	if(m_customerList.empty()){//İf source file does not exist.Automatically creates a source file and adds root user.
		Customer *customer = new Customer (0,"Cihan Uyanik","Somewhere in Eskisehir","500 000 00 00",1000,"cuyanik@ogu.edu.tr","root","1");//Creates root user
		AddToSource(customer);//Adds the customer to the source file
		m_customerList.push_back(customer);//Adds customer to the container
	}

}

//!Destructor function of MainMenu object.
MainMenu::~MainMenu()
{
	for (int i = 0; i<m_bookList.size(); i++)//Deletes book objects in the container
		delete m_bookList[i];


	for (int i = 0; i<m_musicCDList.size(); i++)//Deletes musicCD objects in the container
		delete m_musicCDList[i];

	for (int i = 0; i<m_magazineList.size(); i++)//Deletes magazine objects in the container
		delete m_magazineList[i];
	ofstream file("Customer.txt");//Open source file
	for (int i = 0; i < m_customerList.size(); i++) {//Writes the all customers informations to the source file
		file << m_customerList[i]->getCustomerID() << "$" << m_customerList[i]->getName() << "$" << m_customerList[i]->getAddress() << "$"
			<< m_customerList[i]->getPhone() << "$" << m_customerList[i]->getBonus() << "$" << m_customerList[i]->getEmail() << "$"
			<< m_customerList[i]->getUsername() << "$" << m_customerList[i]->getPassword() << "$";
		if (i + 1 != m_customerList.size())
			file << "\n";
	}
	file.close();//Close file
}

/*!Writes Customers information to the source file.
\param *customer a Customer argument.
*/

void MainMenu::AddToSource(Customer * customer)
{
	ofstream file("Customer.txt", ios::app);//Open source file in append mode to add the new customer information
	file << "\n" << customer->getCustomerID() << "$" << customer->getName() << "$" << customer->getAddress() << "$"
		<< customer->getPhone() << "$0$" << customer->getEmail() << "$"
		<< customer->getUsername() << "$" << customer->getPassword() << "$";
	file.close();
}
//!Main Menu function
void MainMenu::ListMenu()
{
	string temp;//Choose variable
	int choice=0;
	do
	{
		system("cls");
		cout << endl;
		cout << right<<setw(30) << "+---------------+" << endl;
		cout << setw(30) << "|   Main Menu   |" << endl;
		cout << setw(30) << "+---------------+" << endl;
		cout << setw(15) << "" << "1. Customer" << endl;
		cout << setw(15) << "" << "2. Item" << endl;
		cout << setw(15) << "" << "3. Shopping" << endl;
		cout << setw(15) << "" << "0. Quit" << endl;
		cout << setw(10) << "" << "Please, choose one :\t";

		cin >> temp;

		try {//Converts string to the int 
			choice = stoi(temp);
		}
		catch (invalid_argument) {//If user did not enter an integer value set choice to the 20
			choice = 20;
		}
		switch (choice)
		{
		case 1:
			cout << endl;
			this->CustomerMenu();//Call CustomerMenu function
			break;
		case 2:
			cout << endl;
			this->ItemMenu();//Call ItemMenu function
			break;
		case 3:
			cout << endl;
			this->ShoppingMenu();//Call ShoppingMenu function
			break;
		case 0:
			break;
		default:
			cout << setw(5) << "" << "∆  You can just choose 1,2,3 and 0." << endl;
			break;
		}//end switch

	} while (choice != 0);

}//end MainMenu::ListMenu()
//!Customer Menu function 
void MainMenu::CustomerMenu()
{
	system("cls");
	string temp;//To take input from user
	int choice;
	string username, password;
	bool loginFlag = false;//To check if root is login or not

	do
	{
		cout << endl;
		cout << setw(30) <<right<< "~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << setw(30) << "~   Customer Menu   ~" << endl;
		cout << setw(30) << "~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << setw(15) << "" << "1. Add a new customer to system" << endl;
		cout << setw(15) << "" << "2. Show the customers in the system" << endl;
		cout << setw(15) << "" << "0. Back" << endl;
		cout << setw(10) << "" << "Please, choose one :\t";

		cin >> temp;
		try {//Converts string to the int
			choice = stoi(temp);
		}
		catch (invalid_argument) {//If user did not enter an integer value set choice to the 20
			choice = 20;
		}
		cin.ignore();
		switch (choice)
		{
		case 1:
			AddCustomer();//Calls AddCustomer function
			break;
		case 2:
				system("cls");
				loginFlag = false;
				cout << "Only Administrator can see all customers in the system.(Username:root  Password:1)" << endl;
				cout << "Username:";
				getline(cin, username);
				cout << "Password:";
				getline(cin, password);
				for (int i = 0; i < m_customerList.size(); i++)//Checks if the user is root or not
				{
					if (m_customerList[i]->checkAccount(username, password))//Checks if is there a user with this username and password
					{
						if (m_customerList[i] == m_customerList[0]) {//Checks if the user root or not
							cout << "\nAccess Granted" << endl;
							loginFlag = true;
						}
						else {//If user is not root 
							cout << "You are not allowed to see customers in the system." << endl;
							cout << "Press Enter to Continue..." << endl;
							getchar();

						}
					}

				}
				if (loginFlag) {//If root is login prints the all customers informations
					cout << left << "-------------------------------------------------------------------------------------" << endl;
					cout << "|" << setw(5) << "ID" << "|" << setw(25) << "Name" << "|" << setw(30) << "Username" << "|" << setw(20) << "Password" << "|"<< endl;
					cout << "-------------------------------------------------------------------------------------" << endl;

					for (int i = 0; i < m_customerList.size(); i++) {//Print customers informations
						cout <<"|" << setw(5) << m_customerList[i]->getCustomerID() << "|" <<setw(25)<< m_customerList[i]->getName() << "|"
						<<setw(30)<<m_customerList[i]->getUsername()<<"|"<<setw(20)<<m_customerList[i]->getPassword()<<"|"<<endl;
						cout << "-------------------------------------------------------------------------------------" << endl;
					}
					
					cout << "Press Enter to Continue..." << endl;
					getchar();
				}
				else if(!loginFlag) {//if loginflag is false
					cout << "User Not Found" << endl;
					cout << "Press Enter to Continue..." << endl;
					getchar();
				}
			break;
		case 0:
			break;
		default:
			cout << "∆  You can just choose 1,2 and 0." << endl << endl;
			break;
		}//end switch

	} while (choice != 0);


}//end MainMenu::Customer()
//!Item Menu function
void MainMenu::ItemMenu()
{
	string temp;
	int choice;
	do {
		system("cls");
		cout <<right<< setw(30) << "~~~~~~~~~~~~~~~~~" << endl;
		cout << setw(30) << "~   Item Menu   ~" << endl;
		cout << setw(30) << "~~~~~~~~~~~~~~~~~" << endl;
		cout << setw(15) << "" << "1. Add Item" << endl;
		cout << setw(15) << "" << "2. Show Items" << endl;
		cout << setw(15) << "" << "0. Back" << endl;
		cout << setw(10) << "" << "Please, choose one :\t";

		cin >> temp;
		cin.ignore();
		try {
			choice = stoi(temp);//Converts string to the int
		}
		catch (invalid_argument) {//If user did not enter an integer value set choice to the 20
			choice = 20;
		}
		switch (choice) {
		case 1:
			system("cls");
			this->AddProductMenu();//Call add product menu
			break;
		case 2://Prints all items in the system
			system("cls");
			cout << "                                              BOOKS" << endl;
			cout << left << "-------------------------------------------------------------------------------------------------" << endl;
			cout << "|" << setw(5) << "ID" << "|" << setw(25) << "Name" << "|" << setw(30) << "Author" << "|" << setw(20) << "Publisher" << "|" << setw(5) << "Page" << "|" << setw(5) << "Price" << "|" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < m_bookList.size(); i++)//Print all books properties in the container
			{
				m_bookList[i]->printProperties();
			}
			cout << "                                             MAGAZINES" << endl;
			cout << left << "-------------------------------------------------------------------------------------------------" << endl;
			cout << "|" << setw(5) << "ID" << "|" << setw(25) << "Name" << "|" << setw(30) << "Type" << "|" << setw(20) << "Issue" << "|" << setw(11) << "Price" << "|" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < m_magazineList.size(); i++)//Print all magazines properties in the container
			{
				m_magazineList[i]->printProperties();
			}
			cout << "                                             MUSIC CDs" << endl;
			cout << left << "-------------------------------------------------------------------------------------------------" << endl;
			cout << "|" << setw(5) << "ID" << "|" << setw(25) << "Name" << "|" << setw(30) << "Singer" << "|" << setw(20) << "Type" << "|" << setw(11) << "Price" << "|" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < m_musicCDList.size(); i++)//Print all musicCDs properties in the container
			{
				m_musicCDList[i]->printProperties();
			}
			cout << "Press Enter to Continue..." << endl;
			getchar();
			break;
		case 0:
			break;
		default:
			cout << "∆  You can just choose 1,2 and 0." << endl << endl;
			cout << "Press Enter to Continue..." << endl;
			getchar();
			break;
		}
	} while (choice != 0);
}
//!Shopping Menu Function
void MainMenu::ShoppingMenu()
{

	bool loginFlag = false;
	string temp;
	ShoppingCart *Cart=new ShoppingCart;
	int choice;

	do {
		system("cls");
		cout <<right<< setw(30) << "~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << setw(30) << "~   Shopping Menu   ~" << endl;
		cout << setw(30) << "~~~~~~~~~~~~~~~~~~~~~" << endl;

		if (!loginFlag)
			cout << setw(15) << "" << "1. Login" << endl;
		else
			cout << setw(15) << "" << "1. Logout\t" <<Cart->getCustomer()->getName()<< endl;


		cout << setw(15) << "" << "2. Add Product" << endl;
		cout << setw(15) << "" << "3. Remove Product" << endl;
		cout << setw(15) << "" << "4. List All Products" << endl;
		cout << setw(15) << "" << "5. List Shopping Cart" << endl;
		cout << setw(15) << "" << "6. Show Bonus" << endl;
		cout << setw(15) << "" << "7. Use Bonus" << endl;
		cout << setw(15) << "" << "8. Place Order" << endl;
		cout << setw(15) << "" << "9. Cancel Order" << endl;
		cout << setw(15) << "" << "10.Show Invoice" << endl;
		cout << setw(15) << "" << "0. Back" << endl;
		cout << setw(10) << "" << "Please, choose one :\t";

		cin >> temp;
		string username, password;
		cin.ignore();
		try {
			choice = stoi(temp);//Convert string to int
		}
		catch (invalid_argument) {//If user did not enter an integer value set choice to the 20
			choice = 20;
		}
		switch (choice) {
		case 1://Login case
			if (!loginFlag) {
				cout << "Username:";
				getline(cin, username);
				cout << "Password:";
				getline(cin, password);
				for (int i = 0; i < m_customerList.size(); i++)//Checks all customers in the system
				{
					if (m_customerList[i]->checkAccount(username, password))//Checks if is there a customer with this login information
					{
						cout << "\nAccess Granted" << endl;
						loginFlag = true;
						Cart->setCustomer(m_customerList[i]);//Sets shoppingCarts customer to the customer which logged in
					}
				}
				if (!loginFlag) {//If user not found
					cout << "\nUser Not Found" << endl;
					cout << "Press Enter to Continue..." << endl;
					getchar();
				}
			}
			else {//Logout scope
				cout << "\nLogged Out.To continue to shopping please login." << endl;
				loginFlag = false;
				Cart->cancelOrder();//Calls cancelOrder() function
			}
			break;
		case 2://Add product to cart case
			if (loginFlag)
				AddProductoCart(Cart);//Calls AddProducttoCart function
			else {//if not logged in
				cout << "You must Login first" << endl;
				cout << "Press Enter to Continue..." << endl;
				getchar();
			}
			break;
		case 3:
			if (loginFlag) {
				RemoveProducFromCart(Cart);//Call RemoveProductFromCart function
				cout << "Press Enter to Continue..." << endl;
				getchar();
			}
			else {//if not logged in
				cout << "You must Login First" << endl;
				cout << "Press Enter to Continue..." << endl;
				getchar();
			}
			break;
		case 4://Print all products in the system
			system("cls");
			cout << "                                              BOOKS" << endl;
			cout <<left<< "-------------------------------------------------------------------------------------------------" << endl;
			cout << "|" << setw(5) << "ID" <<"|"<< setw(25) <<"Name" <<"|"<< setw(30) << "Author" <<"|"<< setw(20) << "Publisher" << "|"<<setw(5) << "Page" << "|"<<setw(5)<<"Price" << "|" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < m_bookList.size(); i++)//Print all books properties
			{
				m_bookList[i]->printProperties();
			}
			cout << "                                             MAGAZINES" << endl;
			cout << left << "-------------------------------------------------------------------------------------------------" << endl;
			cout << "|" << setw(5) << "ID" << "|" << setw(25) << "Name" << "|" << setw(30) << "Type" << "|" << setw(20) << "Issue" << "|" <<  setw(11) << "Price" << "|" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < m_magazineList.size(); i++)//Print all magazines properties
			{
				m_magazineList[i]->printProperties();
			}
			cout << "                                             MUSIC CDs" << endl;
			cout << left << "-------------------------------------------------------------------------------------------------" << endl;
			cout << "|" << setw(5) << "ID" << "|" << setw(25) << "Name" << "|" << setw(30) << "Singer" << "|" << setw(20) << "Type" << "|" << setw(11) << "Price" << "|" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < m_musicCDList.size(); i++)//Print all musicCDs properties
			{
				m_musicCDList[i]->printProperties();
			}
			cout << "Press Enter to Continue..." << endl;
			getchar();
			break;
		case 5://List Shopping Cart case
			if (loginFlag) {
				if (!Cart->isEmpty()) {//Checks if Cart is empty
					Cart->printProducts();//Calls printProduct function to print products in the cart
					cout << "Press Enter to Continue..." << endl;
					getchar();
				}
				else {
					cout << "Press Enter to Continue..." << endl;
					getchar();
				}
			}
			else {//If not logged in
				cout << "You must Login First" << endl;
				cout << "Press Enter to Continue..." << endl;
				getchar();
			}
			break;
		case 6://Show bonus case
			cout << "Show Bonus" << endl;
			if (loginFlag) {//Checks if user logged in
				cout<<"Your Current Bonus->"<<Cart->getCustomer()->getBonus()<<endl;//Prints customers current bonus
				cout << "Bonus you will gain->" << Cart->getAmount()*5/100 << endl;
				cout << "Press Enter to Continue..." << endl;
				getchar();
			}
			else {//If not logged in
				cout << "You must Login First" << endl;
				cout << "Press Enter to Continue..." << endl;
				getchar();
			}
			break;
		case 7://Use bonus case
			cout << "Use Bonus" << endl;
			if (loginFlag) {//Checks if user logged in
				Cart->setBonusUsed();//Calls Shopping Carts setBonusUsed function
				cout << "Your bonus will be used." << endl;
				cout << "Press Enter to Continue..." << endl;
				getchar();
			}
			else {//if not logged in
				cout << "You must Login First" << endl;
				cout << "Press Enter to Continue..." << endl;
				getchar();
			}
			break;
		case 8://Place order case
			if (loginFlag) {//Checks if user logged in
				PlaceOrder(Cart);//Calls PlaceOrder function
				cout << "Press Enter to Continue..." << endl;
				getchar();
			}
			else {//if not logged in
				cout << "You must Login First" << endl;
				cout << "Press Enter to Continue..." << endl;
				getchar();
			}
			break;
		case 9://Cancel order case
			if (loginFlag) {//Checks if user logged in
				if (!Cart->isEmpty()) {//Checks if Cart is empty
					Cart->cancelOrder();//Calls Shopping Carts cancelOrder function
					cout << "Your Cart is Cleared !" << endl;
					cout << "Press Enter to Continue..." << endl;
					getchar();
				}
				else {//if cart is empty
					cout << "Press Enter to Continue..." << endl;
					getchar();
				}
			}
			else {//if not logged in
				cout << "You must Login First" << endl;
				cout << "Press Enter to Continue..." << endl;
				getchar();
			}
			break;
		case 10://Show invoice case
			cout << " Show Invoice" << endl;
			if (loginFlag) {
				if (!Cart->isEmpty()) {//Checks if cart is empty
					system("cls");
					Cart->showInvoice();//Calls shopping carts showInvoice function
					cout << "Press Enter to Continue..." << endl;
					getchar();
				}

				else {//If cart is empty
					cout << "Press Enter to Continue..." << endl;
					getchar();
				}
			}
			else {//if not logged in
				cout << "You must Login First" << endl;
				cout << "Press Enter to Continue..." << endl;
				getchar();
			}
			break;
		case 0:
			break;
		default:
			cout << "∆  You can just choose 1,2,3,4,5,6,7,8,9,10 and 0." << endl << endl;
			break;
		}
	} while (choice != 0);
}
//!Add Product Menu
void MainMenu::AddProductMenu()
{
	string temp;
	int choice;
	cout << setw(30) << "~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << setw(30) << "~   Product List   ~" << endl;
	cout << setw(30) << "~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << setw(15) << "" << "1. Book" << endl;
	cout << setw(15) << "" << "2. Magazine" << endl;
	cout << setw(15) << "" << "3. MusicCD" << endl;
	cout << setw(15) << "" << "0. Cancel" << endl;
	cout << setw(10) << "" << "Please, choose one :\t";

	cin >> temp;
	cin.ignore();
	try {//Converts string to int
		choice = stoi(temp);
	}
	catch (invalid_argument) {//If user did not enter a valid choice
		choice = 20;
	}

	if (choice == 1)//Add book scope
	{
		system("cls");
		string name, author, publisher;
		int page; double price;
		cout << "Enter the name of book>";
		getline(cin, name);//Getting name of book
		cout << "Enter the price of " << name << ">";
		cin >> price;//Getting price of book
		cin.ignore();
		cout << "Enter author for " << name << ">";
		getline(cin, author);//Getting author of book 
		cout << "Enter publisher for " << name << ">";
		getline(cin, publisher);//Getting publisher of book
		cout << "Enter page for " << name << ">";
		cin >> page;//Getting page of book
		cin.ignore();
		Book *book = new Book(m_bookList[m_bookList.size() - 1]->getID() + 1, name, price, author, publisher, page);//Creates a new book object
		m_bookList.push_back(book);//Adds new book  to the book container
		cout << "Addition is done" << endl;
	}

	else if (choice == 2)//Add magazine scope
	{
		system("cls");
		string name, type;
		int issue; double price;
		cout << "Enter the name of magazine>";
		getline(cin, name);//Getting name of magazine
		cout << "Enter the price of " << name << ">";
		cin >> price;//Getting price of magazine
		cin.ignore();
		cout << "Enter type for " << name << ">";
		getline(cin, type);//Getting type of magazine
		cout << "Enter issue for " <<name << ">";
		cin >> issue;//Getting issue of magazine
		cin.ignore();
		Magazine *magazine = new Magazine(m_magazineList[m_magazineList.size() - 1]->getID() + 1, name, price, issue, type);//Creates a new magazine object
		m_magazineList.push_back(magazine);//Adds new magazine to the magazine container
		cout << "Addition is done" << endl;
	}
	else if (choice == 3)//Add musicCD scope
	{
		system("cls");
		string name, type,singer;
		double price;
		cout << "Enter the name of MusicCD>";
		getline(cin, name);//Getting name of musicCD
		cout << "Enter the price of " << name << ">";
		cin >> price;//Getting price of MusicCD
		cin.ignore();
		cout << "Enter name of singer for " << name << ">";
		getline(cin, singer);//Getting singer of MusicCD
		cout << "Enter type for " <<name<< ">";
		getline(cin, type);//Getting type of MusicCD
		MusicCD *music = new MusicCD(m_musicCDList[m_musicCDList.size() - 1]->getID() + 1, name, price, singer, type);//Creates a new musicCD object
		m_musicCDList.push_back(music);//Adds new MusicCD to the MusicCD to the MusicCD container
		cout << "Addition is done" << endl;
	}
	else if (choice == 0)
	{
	}
	else
	{
		cout << "∆  You can just choose 1,2,3 and 0." << endl << endl;
	}
}
//!Add Customer Menu
void MainMenu::AddCustomer()
{
	system("cls");
	cout << "~~~~~~ADD USER~~~~~~" << endl;
	string namecontrol = "qwertyuopasdfghjklizxcvbnm QWERTYUIOPASDFGHJKLZXCVBNM";//Allowed characters for name
	string phonecontrol = "1234567890 ";//Allowed characters for phone
	string usernamecontrol = " $\t\\şçöğüıİĞÜÖÇŞ";//Forbidden characters for username
	string name, username, password, phone, email, address;
	
	cout << "Enter the name of new user>";
	getline(cin, name);//Getting name of user
	
	cout << "Enter the username for " << name << ">";
	getline(cin, username);//Getting username of new user
	
	cout << "Enter the password for " << name << ">";
	getline(cin, password);//Getting password of new user
	
	cout << "Enter the Phone Number->";
	getline(cin, phone);//Getting phone of new user
	
	cout << "Enter the Address->";
	getline(cin, address);//Getting address of new user
	
	cout << "Enter the Email->";
	getline(cin, email);//Getting email of new user
	
	bool flag = true;
	
	while (true) {//Controlling name of user
			flag = true;
			if (name == "") {//If input is null
				flag = false;
				cout << "You must enter a name." << endl<<"Name->";
				getline(cin, name);//Gets a new name
			}
			for (int i = 0; i < name.length(); i++) {//Controls the name if is there a not allowed character
				if (namecontrol.find(name[i]) == string::npos) {//Checks if the character is allowed
					flag = false;
					cout << "Name is not valid please enter name again(Turkish character is not allowed)\nName:";
					getline(cin, name);//Gets a new name
					break;
				}
			}//end of for
			if (flag)//if flag is not true stays in loop
				break;
		}//End of name control
		while (true) {//Controlling username of user
			flag = true;
			if (username == "") {//if input is null
				flag = false;
				cout << "Username cannot be empty." << endl<<"Username->";
				getline(cin, username);//Gets a new username
			}
			for (int i = 0; i < usernamecontrol.length(); i++) {//Controls the username if is there a not allowed character
				if (username.find(usernamecontrol[i]) != string::npos) {//Checks is the character is allowed
					flag = false;
					cout << "Username is not valid please enter a different username('$','\\' and Turkish characters is not allowed)\n";
					getline(cin, username);//Gets a new username
					break;
				}
			}//End of for
			if (flag) {
				for (int i = 0; i < m_customerList.size(); i++) {//Checks all customers if is  there an user with this username
					if (m_customerList[i]->getUsername() == username) {//Checks if username is taken
						flag = false;
						cout << "This username is already taken please enter a different username\n";
						getline(cin, username);//Getting a new username
						break;
					}
				}//end of for
			}
			if (flag)//if flag is not true stays in loop
				break;
		}//End of username control
		while (true) {//Controlling password of user
			if (password == "") {//if input is null
				cout << "Password cannot be empty." << endl<<"Password->";
				getline(cin, password);//Gets a new password
			}
			else if (password.find("$") != string::npos) {//Checks if password contains '$'
				cout << "Password cannot include '$'.Enter Password Again." << endl;
				getline(cin, password);//Gets a new password
			}
			else {//Finishes loop
				break;
			}
		}//End of password control
		while (true) {//Controlling phone number
			flag = true;
			if (phone == "") {//if input is null
				flag = false;
				cout << "Phone number cannot be empty.\nPhone->";
				getline(cin, phone);//Gets a new phone number
			}
			for (int i = 0; i < phone.length(); i++) {//Checks phone number if is there a not allowed character
				if (phonecontrol.find(phone[i]) == string::npos) {//Checks if character is allowed or not
					flag = false;
					cout << "Phone number is not valid enter again." << endl;
					getline(cin, phone);//Gets a new phone number
					break;
				}
			}//end of for
			if (flag)//if flag is false stay in loop
				break;
		}//End of phone control
		while (true) {//Controlling address
			if (address == "") {//if input is null
				cout << "Address cannot be empty." << endl<<"Address->";
				getline(cin, address);//Gets a new address
			}
			else if (address.find("$") != string::npos) {//Checks if address contains '$'
				cout << "You cannot use '$' in address.Please enter it again:\n";
				getline(cin, address);//Gets a new address
			}
			else//Ends loop
				break;
		}//End of Address control
		while (true) {//Controlling Email
			if (email == "") {//if input is null
				cout << "Email cannot be empty." << endl<<"Email->";
				getline(cin, email);//Gets a new email
			}
			else if (email.find("$") != string::npos) {//Checks if email contains '$'
				cout << "You cannot use '$' in email.Please enter another one:\n";
				getline(cin, email);//Gets a new email
			}
			else//Ends loop
				break;
		}//End of email control
		Customer *customer;
		if (m_customerList.size()==1) {//if it is first user except root
			customer = new Customer(1000, name, address, phone, 0, email, username, password);//Creates a new customer
		}
		else {
			long ID = m_customerList[m_customerList.size() - 1]->getCustomerID() + 1;//Gets the ID of last added user 
			customer = new Customer(ID, name, address, phone, 0, email, username, password);//Creates a new customer
		}



		AddToSource(customer);//Adds new customer to the source file
		m_customerList.push_back(customer);//Adds new customer to the customer container
		
	

}

//! \param *Cart ShoppingCart
void MainMenu::AddProductoCart(ShoppingCart *Cart) {

	// Refreshes the console!
	system("cls");


	do {
		string temp;
		bool find = false;
		int ID;
		int choice;
		int quantity;
		cout << "Please Choose The Product Type" << endl;
		cout << "1.Book\n2.Magazine\n3.MusicCD\n0.Back\n";
		cin >> temp;

		//It ignores the amount of characters.
		cin.ignore();

		//Exception Handling for casting string to integer.
		try
		{
			choice = stoi(temp);
		}
		//If casting is invalid then choice will equal to 20.
		catch (invalid_argument)
		{
			choice = 20;
		}

		//ADDING BOOK !
		if (choice == 1)
		{

			// Refreshes the console!
			system("cls");


			cout << "                                              BOOKS" << endl;
			cout << left << "-------------------------------------------------------------------------------------------------" << endl;
			cout << "|" << setw(5) << "ID" << "|" << setw(25) << "Name" << "|" << setw(30) << "Author" << "|" << setw(20) << "Publisher" << "|" << setw(5) << "Page" << "|" << setw(5) << "Price" << "|" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;

			//Printing properties of books which are in the m_bookList.
			for (int i = 0; i < m_bookList.size(); i++)
			{
				m_bookList[i]->printProperties();
			}

			//Getting Product ID part.
			cout << "Please Enter The Book Product ID" << endl;
			cin >> ID;

			//Searches the book according to the taken ID.
			for (int i = 0; i < m_bookList.size(); i++)
			{
				//If it is found, then...
				if (m_bookList[i]->getID() == ID)
				{
					//find will be true and ...
					while (find = true)
					{

						cout << "Enter the Quantity of Product" << endl;
						cin >> quantity;

						//book will add to Cart if the quantity is higher than 0.
						if (quantity > 0)
						{
							Cart->addProduct(m_bookList[i], quantity);
							cout << "Product Added to Your Shopping Cart" << endl;
							break;
						}
						else
							cout << "Quantity must be higher than 0" << endl;

					}//end while

					break;

				}//end IF
			}//end FOR

			 //If searched book isn't found, then prints the console that product could not find!
			if (!find)
				cout << "Product Could not find" << endl;
		}//END IF CHOICE == 1, ADDING BOOK

		 //ADDING MAGAZINES !
		else if (choice == 2)
		{
			//Refreshes the console !
			system("cls");


			cout << "                                             MAGAZINES" << endl;
			cout << left << "-------------------------------------------------------------------------------------------------" << endl;
			cout << "|" << setw(5) << "ID" << "|" << setw(25) << "Name" << "|" << setw(30) << "Type" << "|" << setw(20) << "Issue" << "|" << setw(11) << "Price" << "|" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;

			//Printing properties of magazines which are in the m_magazineList.
			for (int i = 0; i < m_magazineList.size(); i++)
			{
				m_magazineList[i]->printProperties();
			}

			//Getting Product ID part.
			cout << "Please Enter The Magazine Product ID" << endl;
			cin >> ID;

			//Searches the magazine according to the taken ID.
			for (int i = 0; i < m_magazineList.size(); i++)
			{
				//If it is found, then...
				if (m_magazineList[i]->getID() == ID) {

					//find will be true and ...
					while (find = true)
					{

						cout << "Enter the Quantity of Product" << endl;
						cin >> quantity;

						//magazine will add to Cart if the quantity is higher than 0.
						if (quantity > 0)
						{
							Cart->addProduct(m_magazineList[i], quantity);
							cout << "Product Added to Your Shopping Cart" << endl;
							break;
						}
						else
							cout << "Quantity must be higher than 0" << endl;

					}//end while

					break;

				}//end IF
			}//end FOR

			 //If searched book isn't found, then prints the console that product could not find!
			if (!find)
				cout << "Product Could not find" << endl;

		}//END IF CHOICE == 2, ADDING MAGAZINES

		 //ADDING MUSIC CDs.
		else if (choice == 3)
		{
			// Refreshes the console!
			system("cls");


			cout << "                                             MUSIC CDs" << endl;
			cout << left << "-------------------------------------------------------------------------------------------------" << endl;
			cout << "|" << setw(5) << "ID" << "|" << setw(25) << "Name" << "|" << setw(30) << "Singer" << "|" << setw(20) << "Type" << "|" << setw(11) << "Price" << "|" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;

			//Printing properties of music cds which are in the m_musicCDList.
			for (int i = 0; i < m_musicCDList.size(); i++)
			{
				m_musicCDList[i]->printProperties();
			}

			//Getting Product ID part.
			cout << "Please Enter The MusicCD Product ID" << endl;
			cin >> ID;

			//Searches the music cd according to the taken ID.
			for (int i = 0; i < m_musicCDList.size(); i++)
			{
				//If it is found, then...
				if (m_musicCDList[i]->getID() == ID)
				{

					//find will be true and ...
					while (find = true)
					{

						cout << "Enter the Quantity of Product" << endl;
						cin >> quantity;

						//magazine cd will add to Cart if the quantity is higher than 0.
						if (quantity > 0)
						{
							Cart->addProduct(m_musicCDList[i], quantity);
							cout << "Product Added to Your Shopping Cart" << endl;
							break;
						}
						else
							cout << "Quantity must be higher than 0" << endl;
					}//end while

					break;
				}//end IF
			}//end FOR

			 //If searched music cd isn't found, then prints the console that product could not find!
			if (!find)
				cout << "Product Could not find" << endl;
		}//END IF CHOICE == 3, ADDING MUSIC CDs.

		 //GOES TO PREVIOUS MENU.
		else if (choice == 0)
		{
			break;
		}

		//WRONG CHOOSE!
		else
			cout << "Wrong Choose!" << endl;

	} while (true);
}//end of AddProductCart Function.

 //! \param *Cart ShoppingCart
void MainMenu::RemoveProducFromCart(ShoppingCart *Cart)
{

	cout << "Remove Product" << endl;

	//If Cart is empty goes back to the Shopping Menu.
	if (Cart->isEmpty())
		return;

	//Prints the products which are in the Cart.
	Cart->printProducts();

	int choice;
	cout << "Enter the product number (NOT ID) you want to remove.\n";
	cin >> choice;

	//Removes the product and warnes the user.
	if (Cart->removeProduct(choice))
	{
		cout << "Product Removed From Cart" << endl;
	}
	else
	{
		//Refreshes the console !
		system("cls");

		cout << "Product Number is wrong" << endl;

		//Calls this function.
		RemoveProducFromCart(Cart);
	}

}//end of RemoveProductFromCart Function.

 //! \param *Cart ShoppingCart
void MainMenu::PlaceOrder(ShoppingCart *Cart)
{

	cout << setw(30) << "Place Order" << endl;

	// If cart is empty returns the Shopping Menu.
	if (Cart->isEmpty())
		return;

	//Refreshes the console.
	system("cls");


	int choice;
	string temp;

	while (true)
	{
		cout << "Choose Your Payment Method" << endl;
		cout << "1.Credit Card\n2.Cash\n3.Check\n" << endl;
		cin >> temp;

		//It ignores the amount of characters.
		cin.ignore();

		//Exception Handling for casting string to integer.
		try
		{
			choice = stoi(temp);
		}
		//If casting is invalid then choice will equal to 20.
		catch (invalid_argument)
		{
			choice = 20;
		}

		//CREDIT CART
		if (choice == 1)
		{
			//Takes the card's information.
			string number, type, expDate;
			cout << "Please enter Credit Card Number" << endl;
			getline(cin, number);
			cout << "Please enter type of Card" << endl;
			getline(cin, type);
			cout << "Please enter Exp Date of Card" << endl;
			getline(cin, expDate);


			bool flag = true;
			string NumberControl = "1234567890 ";
			while (true)
			{

				//Checks the taken number is valid.
				for (int i = 0; i < number.length(); i++)
				{
					flag = true;
					if (NumberControl.find(number[i]) == string::npos)
					{
						flag = false;
						cout << "Card number is not valid enter again." << endl;
						getline(cin, number);
						break;
					}//end if
				}//end for

				if (flag)
					break;
			}//end WHILE

			 //Created new CreditCard object according to the given informations.
			CreditCard* payment = new CreditCard;
			payment->setExpDate(expDate);
			payment->setNumber((long)stoi(number));
			payment->setType(type);

			//PaymentMethod is changed as CreditCard.
			Cart->setPaymentMethod(payment);

			//Places the order.
			Cart->placeOrder();

			break;
		}//end IF --> CREDIT CART

		 //CASH
		else if (choice == 2)
		{
			//Created new Cash object.
			Cash *payment = new Cash;

			//PaymentMethod is changed as Cash.
			Cart->setPaymentMethod(payment);

			//Places the order.
			Cart->placeOrder();
			break;
		}//end ELSE IF --> CASH

		 //CHECK
		else if (choice == 3)
		{
			//Takes the check's information.
			string name, bankID;
			cout << "Please enter your name" << endl;
			getline(cin, name);
			cout << "Please enter your bankID" << endl;
			getline(cin, bankID);

			//Created new Check object.
			Check *payment = new Check;
			payment->setBankID(bankID);
			payment->setName(name);

			//PaymentMethod is changed as Check.
			Cart->setPaymentMethod(payment);

			//Places the order.
			Cart->placeOrder();
			break;
		}//end ELSE IF --> CHECK

	}//end WHILE
}//end of PlaceOrder Function.
