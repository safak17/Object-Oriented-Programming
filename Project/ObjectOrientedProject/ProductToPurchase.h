/*!
 * @file   ProductToPurchase.h
 * @Author Safak Akinci (safakakinci17@gmail.com)
 * @date   13 January, 2017
 * @brief  Header File of ProductToPurchase Class.
 */

/*!
 This is a preprocessor technique of preventing a header file from being included multiple times,
 which can be problematic for various reasons.
 
 #ifndef ProductToPurchase_h
 #define ProductToPurchase_h
 #endif
 */
#ifndef ProductToPurchase_h
#define ProductToPurchase_h

#include "Product.h"            //! To have an object which derived from Product Class. (Composition)


//! ProductToPurchase Class.
class ProductToPurchase
{
//! Private variables of the class CANNOT BE ACCESSED the out of the class.
private:
	Product * product;
	int quantity;
    
//! Public variables CAN BE ACCESSED the out of the class.
public:
    
    //! Returns the product. (Accessor Function, should be const)
	Product * getProduct()const;
    
    //! Sets the product according to the given "product".
	void setProduct(Product*product);
    
    //! Returns the quantity. (Accessor Function, should be const)
	int getQuantity();
    
    //! Sets the quantity according to the given "quantity".
	void setQuantity(int quantity);
    
    //! Constructor Function of ProductToPurchase Class.
	ProductToPurchase();
    
    //! Destructor Function of ProductToPurchase Class.
	~ProductToPurchase();
};
#endif
