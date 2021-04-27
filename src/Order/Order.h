//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_ORDER_H
#define SRC_ORDER_H

#include <map>
#include "../Product/Product.h"

class Order {
private:
    std::map<Product*, unsigned int> products;
public:
    Order(std::map<Product*, unsigned int> products);
    void addProduct(Product* product, unsigned int quantity);
    void removeProduct(Product *product);
    void removeQuantityOfProduct(Product *product, unsigned int quantity);
    unsigned int getNumOfProducts();
    unsigned int getNumOfDifProducts();
    unsigned int getSize();
    float getPrice();
};


#endif //SRC_ORDER_H
