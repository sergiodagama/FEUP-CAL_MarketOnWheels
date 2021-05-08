#include <iostream>

#include "Headquarter.h"

int main() {
    std::cout << "Market On Wheels" << std::endl;

    Headquarter headquarter(1000000);
    Truck truck(1000);

    //--------------------primitive tests to loadMap function-------------------------

    //headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");

    //std::cout << "Size: " << headquarter.getGraph().getVertexSet().size() << std::endl;

    //------------------end primitive tests to loadMap function------------------------

    //--------------------primitive tests to loadTrucks function-------------------------

    //headquarter.loadTrucks("../src/Resources/trucks.txt");

    //------------------end primitive tests to loadTrucks function------------------------
    //headquarter.showTrucks();

    truck.loadOrders("../src/Resources/orders.txt");
    truck.showOrders();

    return 0;
}

/*
 * id estadoDaEncomenda date clientId providerId truckId finalPrice
idProduct Quantidade
END ORDER
id estadoDaEncomenda clientId
idProduct Quantidade
END ORDER
...
 */

//1 - Sergio
//Map

//2 - Sara
//Inventário - estrutura done
//Order - estrutura done
//Truck - estrutura done

//3 - EuniceM
//Provider
//Client
