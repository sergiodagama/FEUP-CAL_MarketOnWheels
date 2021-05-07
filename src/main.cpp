#include <iostream>

#include "Headquarter.h"

int main() {
    std::cout << "Market On Wheels" << std::endl;

    Headquarter headquarter(1000000);

    //--------------------primitive tests to loadMap function-------------------------

    //headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");

    //std::cout << "Size: " << headquarter.getGraph().getVertexSet().size() << std::endl;

    //------------------end primitive tests to loadMap function------------------------

    //--------------------primitive tests to loadTrucks function-------------------------

    headquarter.loadTrucks("../src/Resources/trucks.txt");

    //------------------end primitive tests to loadTrucks function------------------------
    headquarter.showTrucks();

    return 0;
}

//1 - Sergio
//Map

//2 - Sara
//Inventário -
//Order - estrutura done
//Truck - estrutura done

//3 - EuniceM
//Provider
//Client
