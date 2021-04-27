//
// Created by eunic on 24/04/2021.
//

#include "Truck.h"

Truck::Truck(unsigned int capacity,unsigned int load) : capacity(capacity), load(load) {}

unsigned int Truck::getLoad() const{
    return load;
}

unsigned int Truck::getCapacity() const{
    return capacity;
}

void Truck::addOrder(Order *order) {
    orders.push_back(order);
}
