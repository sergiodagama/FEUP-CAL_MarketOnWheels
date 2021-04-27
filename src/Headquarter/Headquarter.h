//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_HEADQUARTER_H
#define SRC_HEADQUARTER_H

#include <vector>
#include "..\Order\Order.h"
#include "..\Product\Product.h"
#include "..\Provider\Provider.h"
#include "..\Client\Client.h"
#include "..\Truck\Truck.h"

class Headquarter {
private:
    std::vector<Client*> clients;
    std::vector<Provider*> providers;
    std::vector<Truck*> trucks;
    unsigned int capital;
    Vertex<T>* address;
public:
    Headquarter(unsigned int capital);
};


#endif //SRC_HEADQUARTER_H
