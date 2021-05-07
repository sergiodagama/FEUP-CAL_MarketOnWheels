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

Truck::Truck(unsigned int id, state_t state, int capacity, int load) {
    this->id = id;
    this->state = state;
    this->capacity = capacity;
    this->load = load;
}

unsigned int Truck::getId() {
    return this->id;
}

state_t Truck::getState() {
    return this->state;
}

std::string Truck::returnStateString(int state) {

    switch(state)
    {
        case 0:
            return "assign";
        case 1:
            return "delivering";
        case 2:
            return "completed";
        default:
            return " ";
    }

}







