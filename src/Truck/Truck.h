//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_TRUCK_H
#define SRC_TRUCK_H

#include "../Order/Order.h"
#include <vector>

class Truck {
private:
    int id;
    unsigned int capacity;
    unsigned int load;
    std::vector<Order*> orders;
public:
    Truck(unsigned int capacity,unsigned int load);
    unsigned int getLoad() const;
    unsigned int getCapacity() const;
    void addOrder(Order* order);
};


#endif //SRC_TRUCK_H
