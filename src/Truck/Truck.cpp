//
// Created by eunic on 24/04/2021.
//

#include "Truck.h"

using namespace std;

unsigned int Truck::id_aux = 0;

Truck::Truck(int capacity) : capacity(capacity){
    this->id = id_aux;
    id_aux++;
}

int Truck::getLoad() {
    return this->load;
}

int Truck::getCapacity() {
    return this->capacity;
}

void Truck::removeOrder() {
    this->orders.pop();
}

void Truck::addOrder(Order *order) {
    this->orders.push(order);
}

bool Truck::isFull() {
    return (this->capacity - this->load) == 0;
}

bool Truck::updateLoad(int load) {
    if(isFull()) return false;
    if(this->load + load <= capacity)
    {
        this->load += load;
        return true;
    }
    else
        return false;
}

void Truck::deliveryDone() {
    removeOrder();
    removePath();
}

void Truck::addPath(vector<int> newPath) {
    this->path.push(newPath);
}

void Truck::removePath() {
    this->path.pop();
}

Truck::Truck(unsigned int id, int capacity, int load, std::queue<Order *> orders) {
    this->id = id;
    this->capacity = capacity;
    this->load = load;
    this->orders = orders;
}

unsigned int Truck::getId() {
    return this->id;
}







