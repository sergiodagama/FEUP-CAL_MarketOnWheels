//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_PRODUCT_H
#define SRC_PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    unsigned int price;
    unsigned int size;
public:
    Product(std::string &name, unsigned int price, unsigned int size);
    std::string getName() const;
    void setName(std::string name);
    unsigned int getPrice() const;
    void setPrice(unsigned int price);
    unsigned int getSize() const;
    void setSize(unsigned int size);
};


#endif //SRC_PRODUCT_H
