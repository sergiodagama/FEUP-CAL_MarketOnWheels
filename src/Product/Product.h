//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_PRODUCT_H
#define SRC_PRODUCT_H

#include <string>
#include "../Exceptions/Exceptions.h"

class Product {
private:
    std::string name;
    float price;
    unsigned int size;
public:
    Product(std::string name, float cost, unsigned int size);
    std::string getName();
    void setName(std::string name);
    float getPrice();
    unsigned int getSize();
    void setPrice(float price);
    void setSize(unsigned int size);
};


#endif //SRC_PRODUCT_H
