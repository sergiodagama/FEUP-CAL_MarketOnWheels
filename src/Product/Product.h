//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_PRODUCT_H
#define SRC_PRODUCT_H

#include <string>

class Product {
public:
    Product(std::string &name, float cost, int size);
    std::string getName();
    float getPrice();
    int getSize();
    void setPrice(float price);
private:
    std::string name;
    float price;
    int size;
};


#endif //SRC_PRODUCT_H
