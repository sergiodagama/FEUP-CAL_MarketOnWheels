//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_ORDER_H
#define SRC_ORDER_H

#include <map>
#include "../Product/Product.h"

class Order {
public:
    Order();
    void addProduct(Product* product, int quantity);
    int getSize();
    int getPrice();
private:
    std::map<Product*, int> products;
};


#endif //SRC_ORDER_H
