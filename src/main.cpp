#include <iostream>

#include "Headquarter.h"

int main() {
    std::cout << "Market On Wheels" << std::endl;

    Headquarter headquarter(1000000);

    //--------------------primitive tests to importMap function-------------------------

    headquarter.importMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");

    std::cout << "Size: " << headquarter.getGraph().getVertexSet().size() << std::endl;

    //------------------end primitive tests to importMap function------------------------

    return 0;
}

//1 - Sergio
//Map

//2 - Sara
//Inventário
//Order - estrutura done
//Truck - estrutura done

//3 - EuniceM
//Provider
//Client
