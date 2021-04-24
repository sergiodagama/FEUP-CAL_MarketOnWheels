//
// Created by eunic on 24/04/2021.
//

#include "Product.h"

Product::Product(std::string &name, std::string cost, int size) : name(name), price(cost), size(size) {//lança exceção de preço negativo
    }

std::string Product::getName() {
    return std::__cxx11::string();
}

int Product::getPrice() {
    return 0;
}

void Product::setPrice(int price) { //lança exceção se preço negativo

}

int Product::getSize() {
    return 0;
}
