#include <Truck.h>

using namespace std;

unsigned int Truck::id_aux = 0;

Truck::Truck(unsigned int capacity){
    id_aux++;
    this->id = id_aux;
    this->capacity = capacity;
}

Truck::Truck(unsigned int capacity, std::queue<Order*> orders) {
    id_aux++;
    this->id = id_aux;
    this->orders = move(orders);
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



state_t Truck::getState() {
    return this->state;
}

std::string Truck::returnStateString(int state) {
    switch(state) {
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



void Truck::addOrder(Order *order) {
    if(order->getSize() + load > capacity){
        load += order->getSize();
        this->orders.push(order);
    }
    else throw NotAvailableSpace();
}


void Truck::popOrder() {
    load -= orders.front()->getSize();  //no need to check < 0,
    orders.pop();                       //because load will be always < capacity
}

void Truck::removeOrder(Order *order) {
    //TODO
}



void Truck::setPath(std::queue<Position*>& path) {
    this->path = path;
}

queue<Position*> Truck::getPath() const {
    return path;
}

void Truck::addPositionToPath(Position* position) {
    path.push(position);
}



ostream &operator<<(ostream &os, const Truck &truck) {
    os << truck.id << DELIMITER << truck.capacity << DELIMITER << endl;

    queue<Order*> buffer = truck.orders;

    while(!buffer.empty()){
        os << buffer.front() << endl;
        buffer.pop();
    }
    return os;
}

std::istream &operator>>(istream &is, Truck &truck) {
    is >> truck.id >> truck.capacity;

    Order* order;

    while(!is.eof()) {
        is >> *order;
        truck.addOrder(order);
    }
    return is;
}
