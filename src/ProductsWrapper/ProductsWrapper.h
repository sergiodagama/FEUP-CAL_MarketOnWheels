#ifndef MARKETONWHEELS_PRODUCTSWRAPPER_H
#define MARKETONWHEELS_PRODUCTSWRAPPER_H

#include <map>
#include <Product.h>

class ProductsWrapper {
private:
    std::map<Product*, unsigned int> products; //[product | quantity]
public:
    ProductsWrapper(std::map<Product*, unsigned int> products);
    ProductsWrapper() {};
    std::map<Product*, unsigned int> getProducts() const;
    unsigned int getNumOfProducts();
    unsigned int getNumOfDifProducts();
    unsigned int getQuantityOfProduct(Product* product);
    void addProduct(Product* product, unsigned int quantity);
    void removeProduct(Product* product);
    void removeQuantityOfProduct(Product* product, unsigned int quantity);
    void addQuantityOfProduct(Product* product, unsigned int quantity);
    unsigned int getSize() const;
    float getPrice() const;
};

#endif //MARKETONWHEELS_PRODUCTSWRAPPER_H
