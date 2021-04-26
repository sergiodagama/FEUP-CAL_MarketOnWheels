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
    void addProduct(Product* product, unsigned quantity);
    unsigned getSize();
    float getPrice();
private:
    std::map<Product*, unsigned > products;
};


#endif //SRC_ORDER_H
