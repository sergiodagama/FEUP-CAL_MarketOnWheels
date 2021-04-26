//
// Created by eunic on 24/04/2021.
//

#include "Order.h"

using namespace std;

Order::Order() {
}

unsigned Order::getSize() {
    unsigned size = 0;
    map<Product*, unsigned>::iterator it = products.begin();
    while(it!=products.end()){
        size += it->second * it->first->getSize();
        it++;
    }
    return size;
}

float Order::getPrice() {
    unsigned price = 0;
    map<Product*, unsigned>::iterator it = products.begin();
    while(it!=products.end()){
        price += it->second * it->first->getPrice();
        it++;
    }
    return price;
}

void Order::addProduct(Product *product, unsigned quantity) {
    this->products.insert(pair <Product*, unsigned> (product, quantity));
}
