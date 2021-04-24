//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_TRUCK_H
#define SRC_TRUCK_H

#include "../Order/Order.h"
#include <vector>

class Truck {
public:
    Truck(int capacity, int load);
    int getLoad();
    int getCapacity();
    void addOrder(Order* order);
private:
    int capacity;
    int load;
    std::vector<Order*> orders;
};


#endif //SRC_TRUCK_H
