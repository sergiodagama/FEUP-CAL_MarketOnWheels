//
// Created by eunic on 24/04/2021.
//

#include "Provider.h"

unsigned int Provider::id_aux = 0;

Provider::Provider() {
    this->id = id_aux;
    id_aux++;

}

Provider::Provider(std::map<Product *, unsigned > products) {
    this->id = id_aux;
    id_aux++;
    this->products = products;

}

bool Provider::removeProduct(Product* product, unsigned number) {
    //Product does not exist
    if(products.at(product) == NULL) return false;
    else
    {
        products.erase(product);
        return true;
    }
}

bool Provider::addProduct(Product *product, unsigned number) {
    //Product does not exist
    if(products.at(product) == NULL)
    {
        products[product] = number;
    }
    else
    {
        products.at(product) += number;
        return true;
    }
}

int Provider::getNumProduct(Product *product) {
    return products[product];
}

std::map<Product *, unsigned> Provider::getProducts() {
    return products;
}

int Provider::getSizeProducts() {
    return products.size();
}
