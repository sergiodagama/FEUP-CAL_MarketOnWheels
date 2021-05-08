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
    Truck(unsigned id, state state, int capacity, int load);

    //get methods
    unsigned int getId();
    int getLoad();
    int getCapacity();
    state getState();

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

    void loadOrders(std::string order_path);
    void showOrders();

private:
    int capacity;
    int load;
    unsigned int id;
    static unsigned int id_aux;

    state state;

    std::queue<Order*> orders;
    //a rota que a truck vai ter de fazer , para já está inteiro, mas é só para irmos fazendo
    std::queue<std::vector<int>> path;

};

/*
 * Notas
 * ->eliminar uma encomenda espefica
 */


#endif //SRC_TRUCK_H
