//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_TRUCK_H
#define SRC_TRUCK_H

#include "../Order/Order.h"
#include <queue>
#include <vector>

class Truck {
public:
    Truck(int capacity);

    //get methods
    int getLoad();
    int getCapacity();

    //when a order is delivered
    void removeOrder();
    void addOrder(Order* order);

    //when the truck is full -> addOrder()
    bool isFull();

    //return the update success
    bool updateLoad(int load);

    //update orders and path
    void deliveryDone();

    void addPath(std::vector<int> newPath);
    void removePath();

private:
    int capacity;
    int load;
    unsigned int id;
    static unsigned int id_aux;

    std::queue<Order*> orders;
    //a rota que a truck vai ter de fazer , para já está inteiro, mas é só para irmos fazendo
    std::queue<std::vector<int>> path;
};

/*
 * Notas
 * ->eliminar uma encomenda espefica
 */


#endif //SRC_TRUCK_H
