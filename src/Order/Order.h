//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_ORDER_H
#define SRC_ORDER_H

#include <map>
#include "../Product/Product.h"

class Order {
private:
    std::map<Product*, int> products;
public:
    Order(std::map<Product*, int> products);
    void addProduct(Product* product, int quantity);
    void removeProduct(Product *product);
    void removeQuantityOfProduct(Product *product, int quantity);
    int getNumOfProducts();
    int getNumOfDifProducts();
    int getSize();
    int getPrice();
};


#endif //SRC_ORDER_H
