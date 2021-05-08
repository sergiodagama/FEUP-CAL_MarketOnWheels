//
// Created by eunic on 24/04/2021.
//

#include <fstream>
#include <sstream>
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

Truck::Truck(unsigned int id, ::state state, int capacity, int load) {
    this->id = id;
    this->state = state;
    this->capacity = capacity;
    this->load = load;
}

unsigned int Truck::getId() {
    return this->id;
}

::state Truck::getState() {
    return this->state;
}

void Truck::loadOrders(std::string order_path) {
    ifstream ordersFile(order_path);

    string line;
    unsigned int id, idProduct, idClient, idProvider, idTruck,quantity;
    double finalPrice;

    string date;

    int state;
    bool firstLineDone = false;


    //reading nodes file
    if (ordersFile.is_open()) {
        cout << "HERE" << endl;
        while(getline(ordersFile,line)){

            if(!firstLineDone)
            {
                stringstream ss(line);
                ss  >> id >> state >> date >> idClient >> idProvider >> idTruck >> finalPrice;
                Date newDate(date);

                Order* newOrder = new Order(id, static_cast<::state>(state) ,newDate, idClient, idProvider, idTruck, finalPrice);
            }
            //splitting each line into it's corresponding values
            else
            {
                break;
            }
        }
        ordersFile.close();
    }
    else cout << "Unable to open trucks file";
}

void Truck::showOrders() {

    queue<Order* > copyOrder = orders;

    while(!copyOrder.empty())
    {
        Order* newOrder = copyOrder.front();
        cout << "ID: " << newOrder->getId() << "STATE: " <<  ::returnStateString(newOrder->getState()) << "IDCLIENT: " << newOrder->getIdClient() <<  "IDPROVIDER: " << newOrder->getIdProvider() << "IDTRUCK: "<<  newOrder->getIdTruck() << "FINALPRICE: " <<newOrder->getFinalPrice() << endl;
        copyOrder.pop();
    }

}







