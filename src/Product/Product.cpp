//
// Created by eunic on 24/04/2021.
//

#include "Product.h"

Product::Product(std::string name, float cost, unsigned size){
    if(price < 0)
        throw NegativeValue("price");
    this->name = name;
    this->size = size;
    this->price = cost;
}

std::string Product::getName() {
    return name;
}

float Product::getPrice() {
    return price;
}

void Product::setPrice(float price) {
    if(price < 0)
        throw NegativeValue("price");
    this->price = price;
}

unsigned Product::getSize() {
    return size;
}

////////
void Product::setSize(unsigned int size) {
    this->size = size;
}


