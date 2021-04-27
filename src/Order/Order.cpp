//
// Created by eunic on 24/04/2021.
//

#include "Order.h"

using namespace std;

Order::Order(std::map<Product*, int> products) {
    this->products = products;
}

int Order::getSize() {
    int size;
    for(auto it = products.begin(); it != products.end(); it++){
        size += (it->second * it->first->getSize());
    }
    return size;
}

int Order::getPrice() {
    int price;
    for(auto it = products.begin(); it != products.end(); it++){
        price += (it->second * it->first->getPrice());
    }
    return price;
}

int Order::getNumOfProducts() {
    int num;
    for(auto it = products.begin(); it != products.end(); it++){
        num += it->second;
    }
    return num;
}

int Order::getNumOfDifProducts() {
    return products.size();
}

void Order::addProduct(Product *product, int quantity) {
    products.insert(pair<Product*, int>(product, 40));
}

void Order::removeQuantityOfProduct(Product *product, int quantity) {
    int old_quantity = products.at(product);

    int new_quantity = old_quantity - quantity;

    products.erase(product);

    if(new_quantity > 0) products.insert(pair<Product*, int>(product, new_quantity));
}

void Order::removeProduct(Product *product) {
    products.erase(product);
}

