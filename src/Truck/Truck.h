#ifndef SRC_TRUCK_H
#define SRC_TRUCK_H

#include <queue>
#include <vector>
#include "Order.h"
#include "../Position/Position.h"

class Truck {
private:
    unsigned int id;

    /**
    * Id auxiliar to create unique id's
    */
    static unsigned int id_aux;
    unsigned int capacity;
    unsigned int load;
    std::queue<Order* > orders;
    std::queue<Position> path;
    bool delivering = false;
public:

    /**
    * Truck simple constructor
    *
    * @param capacity the capacity of the truck (max total size of products)
    */
    Truck(unsigned int capacity);

    /**
    * Trucks complex constructor
    *
    * @param capacity the capacity of the truck
    * @param orders the queue of orders for the truck
    */
    Truck(unsigned int capacity, std::queue<Order *> orders);

    /**
    * Gets the truck id
    *
    * @return the truck id
    */
    unsigned int getId() const;

    /**
    * Gets truck capacity
    *
    * @return the truck capacity
    */
    unsigned int getCapacity() const;

    /**
    * Gets the trucks load
    *
    * @return the load of the truck
    */
    unsigned int getLoad() const;

    /**
     * Gets all the trucks orders
     *
     * @return the orders queue
     */
    std::queue<Order*> getOrders() const;

    /**
     * Sets trucks load
     *
     * @param load the load to be set
     */
    void setLoad(unsigned int load);

    /**
    * Adds an order to the order queues
    *
    * @param order the order to be added to the queue
    */
    void addOrder(Order *order);

    /**
    * Removes and order from the queue
    */
    void popOrder();

    /**
    * Removes a specific order from queue
    *
    * @param order the order to be removed
    */
    void removeOrder(Order *order);

    /**
    * Sets the path of the truck
    *
    * @param path the trucks path
    */
    void setPath(std::queue<Position> path);

    /**
    * Gets path queue
    *
    * @return the path queue
    */
    std::queue<Position> getPath() const;

    /**
    * Adds a position to the current path
    *
    * @param position the position to be added
    */
    void addPositionToPath(Position position);

    void removePositionFromPath();

    /**
     * Sets the state of the truck to delivering
     *
     * @param delivering states if the truck is delivering or available
     */
    void setDelivering(bool delivering);

    /**
     * Gets the state of the truck
     *
     * @return the delivering flag of the truck
     */
    bool isDelivering() const;

    /**
    * Overload to << operator of Truck
    *
    * @param os the output stream to be outputted
    * @param truck the truck object
    * @return the output stream
    */
    friend std::ostream &operator<<(std::ostream &os, const Truck &truck);

    /**
    * Overload to >> operator
    *
    * @param is the input stream to be outputted
    * @param truck the truck object
    * @return the input stream
    */
    friend std::istream &operator>>(std::istream &is, Truck &truck);

    /**
     * Shows all trucks orders
     */
    void showOrders();

    /**
     * Clears the trucks path
     */
    void clearPath();
};

#endif //SRC_TRUCK_H
