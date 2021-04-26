//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_PRODUCT_H
#define SRC_PRODUCT_H

#include <string>
#include "../Exceptions/Exceptions.h"

class Product {
public:
    Product(std::string name, float cost, unsigned size);
    std::string getName();
    float getPrice();
    unsigned getSize();
    void setPrice(float price);
    void setSize(unsigned size);
private:
    std::string name;
    float price;
    unsigned size;
};


#endif //SRC_PRODUCT_H
