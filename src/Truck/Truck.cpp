#include "Truck.h"

using namespace std;

unsigned int Truck::id_aux = 0;

Truck::Truck(unsigned int capacity) {
    id_aux++;
    this->id = id_aux;
    this->capacity = capacity;
    load = 0;
}

Truck::Truck(unsigned int capacity, std::queue<Order *> orders) {
    id_aux++;
    this->id = id_aux;
    this->orders = move(orders);
    load = 0;
}

unsigned int Truck::getId() const {
    return id;
}

unsigned int Truck::getCapacity() const {
    return capacity;
}

unsigned int Truck::getLoad() const {
    return load;
}

std::queue<Order *> Truck::getOrders() const {
    return orders;
}

void Truck::popOrder() {
    load -= orders.front()->getSize();  //no need to check < 0,
    orders.pop();                       //because load will be always < capacity
}

void Truck::addOrder(Order *order) {
    if (order->getSize() + load <= capacity) {
        load += order->getSize();
        this->orders.push(order);
    } else throw NotAvailableSpace();
}

void Truck::removeOrder(Order *order) {
    //TODO
}

void Truck::setPath(std::queue<Position> path) {
    this->path = path;
}

queue<Position> Truck::getPath() const {
    return path;
}

void Truck::addPositionToPath(Position position) {
    path.push(position);
}

state_t Truck::getState() {
    return this->state;
}

std::string Truck::returnStateString(int state) {
    switch (state) {
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

ostream &operator<<(ostream &os, const Truck &truck) {
    os << truck.id << DELIMITER << truck.capacity << DELIMITER << truck.load << DELIMITER << truck.state << endl;

    queue<Order *> buffer = truck.orders;

    while (!buffer.empty()) {
        Order *order = buffer.front();
        os << order->getId() << endl;
        buffer.pop();
    }
    os << "_" << endl;
    return os;
}

std::istream &operator>>(istream &is, Truck &truck) {
    is >> truck.id >> truck.capacity;
    return is;
}

void Truck::setLoad(unsigned int load) {
    this->load = load;
}

void Truck::setState(state_t state) {
    this->state = state;
}

void Truck::showOrders(){
    std::queue<Order*> trucks_orders = getOrders();

    std::cout << std::endl << "----------------TRUCKS ORDERS------------------" << std::endl;
    while(!trucks_orders.empty()){
        std::cout << "ID: " << trucks_orders.front()->getId() << "\t";
        std::cout << "SIZE: " << trucks_orders.front()->getSize() << "\t";
        std::cout << "PRICE: " << trucks_orders.front()->getPrice() << "\t";
        std::cout << "CLIENT ID: " << trucks_orders.front()->getClientId() << std::endl;
        trucks_orders.pop();
    }
    std::cout << "-----------------------------------------------" << std::endl;
}

