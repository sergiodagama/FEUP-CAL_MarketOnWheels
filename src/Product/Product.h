//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_PRODUCT_H
#define SRC_PRODUCT_H

#include <string>

class Product {
public:
    Product(std::string &name, std::string cost, int size);
    std::string getName();
    int getPrice();
    int getSize();
    void setPrice(int price);
private:
    std::string name;
    std::string price;
    int size;
};


#endif //SRC_PRODUCT_H
