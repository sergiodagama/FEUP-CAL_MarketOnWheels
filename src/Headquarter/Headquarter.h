//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_HEADQUARTER_H
#define SRC_HEADQUARTER_H

#include <vector>
#include "../Order/Order.h"
#include "../Product/Product.h"
#include "../Provider/Provider.h"
#include "../Client/Client.h"
#include "../Truck/Truck.h"
#include "../Position/Position.h"

class Headquarter {
private:
    std::vector<Client*> clients;
    std::vector<Provider*> providers;
    std::vector<Truck*> trucks;
    unsigned int capital;
    //Vertex<T>* address;
    Graph<Position> graph;
public:
    Headquarter(unsigned int capital);
    void loadMap(std::string nodes_path, std::string edges_path);  //imports the designated map in files into graph
    void loadTrucks(std::string truck_path);
    Graph<Position> getGraph() const;

    void showTrucks();

    Position getPositionById(double id);
};


#endif //SRC_HEADQUARTER_H
