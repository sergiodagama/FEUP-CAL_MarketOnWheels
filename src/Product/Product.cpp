//
// Created by eunic on 24/04/2021.
//

#include "Product.h"

Product::Product(std::string &name, float cost, int size) : name(name), price(cost), size(size) {
    if(price)
    //lança exceção de preço negativo
    }

std::string Product::getName() {
    return name;
}

float Product::getPrice() {
    return price;
}

void Product::setPrice(float price) { //lança exceção se preço negativo
    this->price = price;
}

int Product::getSize() {
    return size;
}
