#include "ShoppingCart.h"           //! To know function prototypes of ShoppingCart Class.


//! Constructor Function of ShoppingCart Class.
ShoppingCart::ShoppingCart()
{
	paymentMethod = new Cash;
}


//! Destructor Function of ShoppingCart Class.
//! PaymentMethod(Payment*) and productToPurchase(ProductToPurchase*) should be destroyed because of the Composition.
ShoppingCart::~ShoppingCart()
{

    //! Release the paymentMethod.
    paymentMethod->~Payment();

    //! Removes all items from productsToPurchase List.
	while(!productsToPurchase.empty()){
			productsToPurchase.pop_back();
	}
    productsToPurchase.clear();
}

//! Returns the paymentMethod. (Accessor Function, should be const.)
Payment * ShoppingCart::getPaymentMethod() const
{
    return paymentMethod;
}

//! Sets the paymentMethod according to the given "paymentMethod".
void ShoppingCart::setPaymentMethod(Payment * paymentMethod)
{
    this->paymentMethod = paymentMethod;
}

//! Returns the customer. (Accessor Function, should be const.)
Customer * ShoppingCart::getCustomer() const
{
    return customer;
}

//! Sets the customer according to the given "customer".
void ShoppingCart::setCustomer(Customer * customer)
{
    this->customer = customer;
}

//! isBonusUsed will be true.
void ShoppingCart::setBonusUsed()
{
    isBonusUsed = true;
}

//! Returns the amount! (Accessor Function, should be const).
double ShoppingCart::getAmount() const
{
    return amount;
}

//! Sets the amount according to the given "amount"!
void ShoppingCart::setAmount(double amount)
{
    this->amount = amount;
}

//! Adds new product and its quantity to productsToPurchase.
void ShoppingCart::addProduct(Product * product,int quantity)
{
    ProductToPurchase *new_Item = new ProductToPurchase;
    new_Item->setProduct(product);
    new_Item->setQuantity(quantity);

    amount += product->getPrice()*quantity;
    productsToPurchase.push_back(new_Item);
}

//! Product at given index will be removed from the container.
bool ShoppingCart::removeProduct(int index)
{

    if (index > 0 && index <= productsToPurchase.size())
    {
        list<ProductToPurchase *>::const_iterator iterator;
        iterator = productsToPurchase.begin();
        for (int i = 1; i < index; i++)
        {
            iterator++;
        }
        amount -= (*iterator)->getProduct()->getPrice()*(*iterator)->getQuantity();
        productsToPurchase.remove(*iterator);
        return true;
    }

    return false;

}

//! Performs payment.
void ShoppingCart::placeOrder()
{
	system("cls");
    if (isBonusUsed)
        customer->useBonus(amount);
	this->showInvoice();
    paymentMethod->performPayment();
    customer->addBonus(amount * 5 / 100);
    productsToPurchase.clear();
    amount = 0;

}

//! Removes all items which were in the productsToPurchase container.
void ShoppingCart::cancelOrder()
{
    productsToPurchase.clear();
	amount = 0;
}

//! Prints products which are in the productsToPurchase container to console.
void ShoppingCart::printProducts()
{
    int theOrderOfTheItem = 1;
    cout << setw(30) <<"~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << setw(30) <<"~      Products     ~" << endl;
    cout << setw(30) <<"~~~~~~~~~~~~~~~~~~~~~" << endl;

    list<ProductToPurchase *>::const_iterator iterator;
    for (iterator = productsToPurchase.begin(); iterator != productsToPurchase.end(); ++iterator)
    {
        cout
        << left << theOrderOfTheItem << "->"<<setw(10) << "Quantity:" << setw(7) << (*iterator)->getQuantity()
        << setw(6) <<"Name:" <<setw(30)<<(*iterator)->getProduct()->getName()
        << setw(6) <<"Price:"<< (*iterator)->getProduct()->getPrice() <<endl;
        theOrderOfTheItem++;
    }
}


//! Shows the invoice to console.
void ShoppingCart::showInvoice()
{
    stringstream Invoice;
    cout << setw(30) << "INVOICE" << endl;
	cout << "-------------------------------------------------------------" << endl;
    customer->sendBill();
	cout << setw(20) << " " << "PURCHASED PRODUCTS" << endl;
	cout << "-------------------------------------------------------------" << endl;

    list<ProductToPurchase *>::const_iterator iterator;
    for (iterator = productsToPurchase.begin(); iterator != productsToPurchase.end(); ++iterator)
    {
        Invoice << (*iterator)->getQuantity()<<" x "<<left<<setw(40)<<(*iterator)->getProduct()->getName() << "Price:" << (*iterator)->getProduct()->getPrice()<<endl;
    }

    Invoice <<setw(50)<<right<< "Total:" <<amount<< endl;
    cout << Invoice.str();
	cout << "-------------------------------------------------------------" << endl;

}

//! Checks the productsToPurchase container is empty.
bool ShoppingCart::isEmpty() const
{
    if( productsToPurchase.empty() )
    {
        cout<< setw(30) <<"List is empty !"<<endl;
        return true;
    }

        return false;
}
