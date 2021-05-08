#include <Truck.h>

using namespace std;

/**
 * Id auxiliar to create unique id's
 */
unsigned int Truck::id_aux = 0;

/**
 * Truck simple constructor
 *
 * @param capacity the capacity of the truck (max total size of products)
 */
Truck::Truck(unsigned int capacity){
    id_aux++;
    this->id = id_aux;
    this->capacity = capacity;
}

/**
 * Trucks complex constructor
 *
 * @param capacity the capacity of the truck
 * @param orders the queue of orders for the truck
 */
Truck::Truck(unsigned int capacity, std::queue<Order*> orders) {
    id_aux++;
    this->id = id_aux;
    this->orders = move(orders);
}

/**
 * Gets the truck id
 *
 * @return the truck id
 */
unsigned int Truck::getId() const {
    return id;
}

/**
 * Gets truck capacity
 *
 * @return the truck capacity
 */
unsigned int Truck::getCapacity() const {
    return capacity;
}

/**
 * Gets the trucks load
 *
 * @return the load of the truck
 */
unsigned int Truck::getLoad() const {
    return load;
}

/**
 * Removes and order from the queue
 */
void Truck::popOrder() {
    load -= orders.front()->getSize();  //no need to check < 0,
    orders.pop();                       //because load will be always < capacity
}

/**
 * Adds an order to the order queues
 *
 * @param order the order to be added to the queue
 */
void Truck::addOrder(Order *order) {
    if(order->getSize() + load > capacity){
        load += order->getSize();
        this->orders.push(order);
    }
    else throw NotAvailableSpace();
}

/**
 * Removes a specific order from queue
 *
 * @param order the order to be removed
 */
void Truck::removeOrder(Order *order) {
    //TODO
}

/**
 * Sets the path of the truck
 *
 * @param path the trucks path
 */
void Truck::setPath(std::queue<Position*>& path) {
    this->path = path;
}

/**
 * Gets path queue
 *
 * @return the path queue
 */
queue<Position*> Truck::getPath() const {
    return path;
}

/**
 * Adds a position to the current path
 *
 * @param position the position to be added
 */
void Truck::addPositionToPath(Position* position) {
    path.push(position);
}

/**
 * Removes a position from path
 */
void Truck::removePositionFromPath() {
    path.pop();
}

/**
 * Overload to << operator of Truck
 *
 * @param os the output stream to be outputted
 * @param truck the truck object
 * @return the output stream
 */
ostream &operator<<(ostream &os, const Truck &truck) {
    os << truck.id << DELIMITER << truck.capacity << DELIMITER;
    os << truck.load << endl;

    queue<Order*> buffer = truck.orders;

    while(!buffer.empty()){
        os << buffer.front() << endl;
        buffer.pop();
    }
    return os;
}
