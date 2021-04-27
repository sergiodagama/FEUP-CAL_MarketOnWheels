//
// Created by eunic on 24/04/2021.
//

#include "Product.h"

Product::Product(std::string &name, unsigned int price, unsigned int size) {
    this->name = name;
    this->price = price;
    this->size = size;
}

std::string Product::getName() const{
    return name;
}

void Product::setName(std::string name) {
    this->name = name;
}

unsigned int Product::getPrice() const{
    return price;
}

void Product::setPrice(unsigned int price) {
    this->price = price;
}

unsigned int Product::getSize() const{
    return size;
}

void Product::setSize(unsigned int size) {
    this->size = size;
}




