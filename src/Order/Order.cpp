//
// Created by eunic on 24/04/2021.
//

#include "Order.h"

using namespace std;

Order::Order(std::map<Product*, unsigned int> products) {
    this->products = products;
}

unsigned int Order::getSize() {
    int size;
    for (auto it = products.begin(); it != products.end(); it++) {
        size += (it->second * it->first->getSize());
    }
    return size;
}

float Order::calculatePrice() {
    float price;
    for(auto it = products.begin(); it != products.end(); it++){
        price += (it->second * it->first->getPrice());
    }
    return price;
}

unsigned int Order::getNumOfProducts() {
    int num;
    for(auto it = products.begin(); it != products.end(); it++){
        num += it->second;
    }
    return num;
}

unsigned int Order::getNumOfDifProducts() {
    return products.size();
}

void Order::addProduct(Product *product, unsigned int quantity) {
    products.insert(pair<Product*, unsigned int>(product, 40));
}

void Order::removeQuantityOfProduct(Product *product, unsigned int quantity) {
    int old_quantity = products.at(product);

    int new_quantity = old_quantity - quantity;

    products.erase(product);

    if (new_quantity > 0) products.insert(pair<Product *, unsigned int>(product, new_quantity));
}

void Order::removeProduct(Product *product) {
    products.erase(product);
}

Order::Order(unsigned int id, ::state state, Date date, unsigned int idClient, unsigned int idProvider,
             unsigned int idTruck, double finalPrice) {
    this->id = id;
    this->state = state;
    this->date = date;
    this->idClient = idClient;
    this->idProvider = idProvider;
    this->idTruck = idTruck;
    this->finalPrice = finalPrice;

}

unsigned int Order::getId()
{
    return this->id;
}

::state Order::getState()
{
    return this->state;
}

Date Order::getDate()
{
    return this->date;
}

unsigned int Order::getIdClient()
{
    return this->idClient;
}

unsigned int Order::getIdProvider()
{
    return this->idProvider;
}

unsigned int Order::getIdTruck()
{
    return this->idTruck;
}

double Order::getFinalPrice()
{
    return this->finalPrice;
}

