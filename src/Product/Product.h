//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_PRODUCT_H
#define SRC_PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    std::string price;
public:
    Product(std::string &name, std::string price);
    std::string getName();
    int getPrice();
    void setPrice(int price);
};


#endif //SRC_PRODUCT_H
