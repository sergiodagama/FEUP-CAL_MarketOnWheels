//
// Created by eunic on 24/04/2021.
//

#include "Product.h"


std::string Product::getName(){
    return name;
}

void Product::setName(std::string name) {
    this->name = name;
}

float Product::getPrice(){
    return price;
}


unsigned int Product::getSize() {
    return size;
}

Product::Product(std::string name, float cost, unsigned size){
    if(price < 0)
        throw NegativeValue("price");
    this->name = name;
    this->size = size;
    this->price = cost;
}


void Product::setPrice(float price) {
    if(price < 0)
        throw NegativeValue("price");
    this->price = price;
}


void Product::setSize(unsigned int size) {
    this->size = size;
}
