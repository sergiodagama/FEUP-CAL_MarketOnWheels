#include <gtest/gtest.h>
#include "Headquarter.h"
#include <chrono>
#include <vector>

/**
 * TESTS TO HEADQUARTERS FUNCTIONS AND CLASSES
 *
 * (WARNING: SOME TESTS DEPEND ON OTHERS)
 */

using testing::Eq;

/**
 * LOADERS AND SAVERS, DATA STRUCTURES
 */

TEST(test, saveProductData) {
    Headquarter headquarter("1000000");

    headquarter.loadMap("../src/Resources/Maps/nodes.txt", "../src/Resources/Maps/edges.txt");

    Product* potato = new Product("potato", 1.2, 2);
    Product* rice = new Product("rice", 1, 2);
    Product* pasta = new Product("pasta", 2.1, 3);
    Product* tomato = new Product("tomato", 1.3, 1);
    Product* bread = new Product("bread", 0.4, 1);
    Product* water = new Product("water", 1.1, 2);
    Product* wine = new Product("wine", 4.5, 4);
    Product* chips = new Product("chips", 2.3, 3);

    headquarter.addProduct(potato);
    headquarter.addProduct(rice);
    headquarter.addProduct(pasta);
    headquarter.addProduct(tomato);
    headquarter.addProduct(bread);
    headquarter.addProduct(water);
    headquarter.addProduct(wine);
    headquarter.addProduct(chips);

    headquarter.saveProductData("../src/Resources/products.txt");

    std::cout << std::endl << "SEE INFORMATION ON PRODUCTS FILE" << std::endl;
}

//run after saving products data test
TEST(test, loadProductData) {
    Headquarter headquarter("1000000");
    headquarter.loadMap("../src/Resources/Maps/nodes.txt", "../src/Resources/Maps/edges.txt");

    headquarter.loadProductData("../src/Resources/products.txt");
    headquarter.showProducts();
    EXPECT_EQ(headquarter.getNProducts(), 8);
}

TEST(test, saveProviderData) {
    Headquarter headquarter("1000000");
    headquarter.loadMap("../src/Resources/Maps/nodes.txt", "../src/Resources/Maps/edges.txt");

    Product* potato = new Product("potato", 1.2, 2);
    Product* rice = new Product("rice", 1, 5);
    Product* pasta = new Product("pasta", 2.1, 3);
    Product* tomato = new Product("tomato", 1.3, 1);
    Product* bread = new Product("bread", 0.4, 1);
    Product* water = new Product("water", 1.1, 2);
    Product* wine = new Product("wine", 4.5, 4);
    Product* chips = new Product("chips", 2.3, 3);

    Provider* continente = new Provider("continente", "cont", 26);
    Provider* pingodoce = new Provider("pingodoce", "ping", 32);

    continente->addProduct(potato, 200);
    continente->addProduct(rice, 300);
    continente->addProduct(pasta, 100);
    continente->addProduct(tomato, 30);
    continente->addQuantityOfProduct(tomato, 20);
    EXPECT_EQ(continente->getQuantityOfProduct(tomato), 50);
    continente->removeQuantityOfProduct(tomato, 10);
    EXPECT_EQ(continente->getQuantityOfProduct(tomato), 40);
    continente->removeProduct(pasta);
    EXPECT_EQ(continente->getNumOfDifProducts(), 3);

    pingodoce->addProduct(bread, 45);
    pingodoce->addProduct(water, 50);
    pingodoce->addProduct(wine, 120);
    pingodoce->addProduct(chips, 340);

    headquarter.addProvider(continente);
    headquarter.addProvider(pingodoce);

    headquarter.saveProviderData("../src/Resources/providers.txt");

    std::cout << std::endl << "SEE INFORMATION ON PROVIDERS FILE" << std::endl;
}

//run after save providers test
TEST(test, loadProviderData){
    Headquarter headquarter("1000000");
    headquarter.loadMap("../src/Resources/Maps/nodes.txt", "../src/Resources/Maps/edges.txt");
    headquarter.loadProductData("../src/Resources/products.txt");

    headquarter.loadProviderData("../src/Resources/providers.txt");
    headquarter.showProviders();

    std::map<Product*, unsigned int> prods = headquarter.getProviderById(1)->getProducts();

    for(auto it = prods.begin(); it != prods.end(); it++){
        std::cout << *(*it).first << " " << (*it).second << std::endl;
    }
    EXPECT_EQ(prods.size(), 3);

    std::map<Product*, unsigned int> prods2 = headquarter.getProviderById(2)->getProducts();

    for(auto it = prods2.begin(); it != prods2.end(); it++){
        std::cout << *(*it).first << " " << (*it).second << std::endl;
    }
    EXPECT_EQ(prods2.size(), 4);
}

TEST(test, saveClientData){
    Headquarter headquarter("1000000");
    headquarter.loadMap("../src/Resources/Maps/nodes.txt", "../src/Resources/Maps/edges.txt");

    Client* client = new Client("Jon", "jony", Date(2, 10 ,2000), 18);
    Client* client2 = new Client("Tom", "tomy", Date(25, 4 ,1996), 17);
    Client* client3 = new Client("Dan", "dan", Date(3, 6 ,1987), 20);
    Client* client4 = new Client("Mary", "mary", Date(17, 9 ,2005), 9);

    headquarter.addClient(client);
    headquarter.addClient(client2);
    headquarter.addClient(client3);
    headquarter.addClient(client4);

    headquarter.saveClientData("../src/Resources/clients.txt");

    std::cout << std::endl << "SEE INFORMATION ON CLIENTS FILE" << std::endl;
}

//run after the save clients data test
TEST(test, loadClientsData){
    Headquarter headquarter("1000000");
    headquarter.loadMap("../src/Resources/Maps/nodes.txt", "../src/Resources/Maps/edges.txt");

    headquarter.loadClientData("../src/Resources/clients.txt");
    headquarter.showClients();
    EXPECT_EQ(headquarter.getNClients(), 4);
}

TEST(test, saveOrdersData){
    Headquarter headquarter("1000000");
    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");

    Product* potato = new Product("potato", 1.2, 2);
    Product* rice = new Product("rice", 1, 5);
    Product* pasta = new Product("pasta", 2.1, 3);
    Product* tomato = new Product("tomato", 1.3, 1);
    Product* bread = new Product("bread", 0.4, 1);
    Product* water = new Product("water", 1.1, 2);
    Product* wine = new Product("wine", 4.5, 4);
    Product* chips = new Product("chips", 2.3, 3);

    headquarter.addProduct(potato);
    headquarter.addProduct(rice);
    headquarter.addProduct(pasta);
    headquarter.addProduct(tomato);
    headquarter.addProduct(bread);
    headquarter.addProduct(water);
    headquarter.addProduct(wine);
    headquarter.addProduct(chips);

    Order* order1 = new Order(3);
    Order* order2 = new Order(1);

    order1->addProduct(tomato, 50);
    order1->addProduct(pasta, 20);
    order1->addProduct(rice, 10);
    order2->addProduct(water, 30);
    order2->addProduct(bread, 10);
    order2->addProduct(wine, 20);

    headquarter.addOrder(order1);
    headquarter.addOrder(order2);

    headquarter.saveOrderData("../src/Resources/orders.txt");

    std::cout << std::endl << "SEE INFORMATION ON ORDERS FILE" << std::endl;
}

//run after save orders test
TEST(test, loadOrderData){
    Headquarter headquarter("1000000");
    headquarter.loadMap("../src/Resources/Maps/nodes.txt", "../src/Resources/Maps/edges.txt");
    headquarter.loadProductData("../src/Resources/products.txt");
    headquarter.loadOrderData("../src/Resources/orders.txt");

    std::map<Product*, unsigned int> prods = headquarter.getOrderById(2)->getProducts();

    for(auto it = prods.begin(); it != prods.end(); it++){
        std::cout << *(*it).first << std::endl;
    }
    headquarter.showOrders();

    EXPECT_EQ(headquarter.getNOrders(), 2);
}

TEST(test, saveTrucksData){
    Headquarter headquarter("1000000");
    headquarter.loadMap("../src/Resources/Maps/nodes.txt", "../src/Resources/Maps/edges.txt");
    headquarter.loadProductData("../src/Resources/products.txt");
    headquarter.loadOrderData("../src/Resources/orders.txt");

    Truck *truck = new Truck(700);
    Truck *truck2 = new Truck(700);

    Order* order1 = headquarter.getOrderById(1);
    Order* order2 = headquarter.getOrderById(2);

    truck->addOrder(order1);
    truck->addOrder(order2);
    truck2->addOrder(order1);

    headquarter.addTruck(truck);
    headquarter.addTruck(truck2);

    headquarter.saveTruckData("../src/Resources/trucks.txt");

    std::cout << std::endl << "SEE INFORMATION ON TRUCKS FILE" << std::endl;
}

//run after the save trucks data test
TEST(test, loadTrucksData){
    Headquarter headquarter("1000000");
    headquarter.loadMap("../src/Resources/Maps/nodes.txt", "../src/Resources/Maps/edges.txt");

    headquarter.loadProductData("../src/Resources/products.txt");
    headquarter.loadOrderData("../src/Resources/orders.txt");
    headquarter.loadTruckData("../src/Resources/trucks.txt");

    EXPECT_EQ(headquarter.getNTrucks(), 2);

    headquarter.showTrucks();
}

/**
 * SHORTEST PATH ALGORITHMS
 */

TEST(test, floydWarshall_simpleMap){
    Headquarter headquarter("123");

    std::cout << std::endl << "-------STARTED LOADING MAP--------" << std::endl;
    std::cout << "MAP: 25 nodes" << std::endl;

    headquarter.loadMap("../src/Resources/Maps/nodes.txt", "../src/Resources/Maps/edges.txt");

    std::cout << "--------LOADED SIMPLE MAP---------" << std::endl << std::endl;

    std::cout << "------STARTED FLOYD WARSHALL------" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    headquarter.getGraph().floydWarshallShortestPath();

    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "Elapsed time in function call: " << elapsed.count() << std::endl;
}

//WARNING PROCESSING TIME TOO BIG (just for demo purpose)
TEST(test, floydWarshall_penafielMap){
    Headquarter headquarter("123");

    std::cout << std::endl << "----STARTED LOADING PENAFIEL MAP----" << std::endl;
    std::cout << "MAP: 10365 nodes" << std::endl;

    headquarter.loadMap("../src/Resources/Maps/penafiel_strong_nodes.txt", "../src/Resources/Maps/penafiel_strong_edges.txt");

    std::cout << "-------------LOADED MAP-------------" << std::endl << std::endl;

    std::cout << "--------STARTED FLOYD WARSHALL------" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    headquarter.getGraph().floydWarshallShortestPath();

    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "Elapsed time in function call: " << elapsed.count() << std::endl;
}

TEST(test, dijkstraShortestPath_getPath){
    Headquarter headquarter("123");

    headquarter.loadMap("../src/Resources/Maps/penafiel_strong_nodes.txt", "../src/Resources/Maps/penafiel_strong_edges.txt");

    int begin = 3423, end = 3570;

    std::cout << "PATH FROM VERTEX " << begin << " TO " << end << std::endl;

    headquarter.getGraph().dijkstraShortestPath(headquarter.getPositionById(begin));

    std::vector<Position> path = headquarter.getGraph().getPath(headquarter.getPositionById(begin), headquarter.getPositionById(end));

    for(auto it : path){
        std::cout << it << "\t";
    }

    EXPECT_EQ(path.size(), 45);

    std::cout << std::endl << "\nREVERSE PATH FROM VERTEX " << end << " TO " << begin << std::endl;

    headquarter.getGraph().dijkstraShortestPath(headquarter.getPositionById(end));

    std::vector<Position> reverse_path = headquarter.getGraph().getPath(headquarter.getPositionById(end), headquarter.getPositionById(begin));

    for(auto it : reverse_path){
        std::cout << it << "\t";
    }

    EXPECT_EQ(reverse_path.size(), 123);

    int begin2 = 2, end2 = 300;

    std::cout << std::endl << "\nNO PATH FROM VERTEX " << begin2 << " TO " << end2 << std::endl;

    headquarter.getGraph().dijkstraShortestPath(headquarter.getPositionById(begin2));

    std::vector<Position> no_path = headquarter.getGraph().getPath(headquarter.getPositionById(begin2), headquarter.getPositionById(end2));

    EXPECT_EQ(no_path.size(), 0);
}

TEST(test, distanceFromPath){
    Headquarter headquarter("123");

    int begin = 2555, end = 6865;
    //int begin = 17, end = 1;
    int intermediate = 10361;

    headquarter.loadMap("../src/Resources/Maps/penafiel_strong_nodes.txt", "../src/Resources/Maps/penafiel_strong_edges.txt");

    headquarter.getGraph().dijkstraShortestPath(headquarter.getPositionById(begin));

    std::vector<Position> path = headquarter.getGraph().getPath(headquarter.getPositionById(begin), headquarter.getPositionById(end));

    std::cout << "DISTANCE FROM " << begin << " TO " << intermediate << " : " << headquarter.getGraph().getWeight(headquarter.getGraph().findVertex(headquarter.getPositionById(begin)), headquarter.getGraph().findVertex(headquarter.getPositionById(intermediate)));

    std::cout << "\nDISTANCE FROM " << intermediate << " TO " << end << " : " << headquarter.getGraph().getWeight(headquarter.getGraph().findVertex(headquarter.getPositionById(intermediate)), headquarter.getGraph().findVertex(headquarter.getPositionById(end)));

    std::cout << "\nDISTANCE FROM VERTEX " << begin << " TO "  << end << " : " << headquarter.getGraph().distanceFromPath(path);
}

/**
 * FUNCTIONS THAT HANDLES DELIVERS AND SHORTEST PATHS
 */

TEST(test, distributeOrdersToTrucks){
    Headquarter headquarter("1000000");

    headquarter.loadClientData("../src/Resources/clients.txt");
    headquarter.loadProductData("../src/Resources/products.txt");

    Truck* truck = new Truck(110);
    Truck* truck2 = new Truck(300);

    Order* order1 = new Order(1);
    Order* order2 = new Order(2);
    Order* order3 = new Order(3);
    Order* order4 = new Order(1);
    Order* order5 = new Order(1);
    Order* order6 = new Order(3);
    Order* order7 = new Order(3);
    Order* order8 = new Order(4);

    order1->addProduct(headquarter.getProductById(2), 10);
    order2->addProduct(headquarter.getProductById(2), 10);
    order3->addProduct(headquarter.getProductById(2), 5);
    order4->addProduct(headquarter.getProductById(2), 5);
    order5->addProduct(headquarter.getProductById(2), 20);
    order6->addProduct(headquarter.getProductById(2), 30);
    order7->addProduct(headquarter.getProductById(2), 10);
    order8->addProduct(headquarter.getProductById(2), 5);

    headquarter.addOrder(order1);
    headquarter.addOrder(order2);
    headquarter.addOrder(order3);
    headquarter.addOrder(order4);
    headquarter.addOrder(order5);
    headquarter.addOrder(order6);
    headquarter.addOrder(order7);
    headquarter.addOrder(order8);

    headquarter.addTruck(truck);

    headquarter.distributeOrdersToTrucks();

    headquarter.showTrucks();

    truck->showOrders();

    EXPECT_EQ(truck->getLoad(), 110);
    EXPECT_EQ(truck->getOrders().size(), 4);

    headquarter.addTruck(truck2);

    headquarter.distributeOrdersToTrucks();

    headquarter.showTrucks();

    truck2->showOrders();

    EXPECT_EQ(truck2->getLoad(), 80);
    EXPECT_EQ(truck2->getOrders().size(), 4);
}

TEST(test, getProvidersThatSatisfy){
    Headquarter headquarter("123");

    std::cout << std::endl << "----getProvidersThatSatisfy----" << std::endl;
    headquarter.loadMap("../src/Resources/Maps/penafiel_strong_nodes.txt", "../src/Resources/Maps/penafiel_strong_edges.txt");
    headquarter.loadProductData("../src/Resources/products.txt");
    headquarter.loadProviderData("../src/Resources/providers.txt");

    Order* order1 = new Order(1);
    Order* order2 = new Order(2);

    std::queue<Order *> orders1;

    order1->addProduct(headquarter.getProductById(2), 5);
    order2->addProduct(headquarter.getProductById(2), 10);

    orders1.push(order1);
    orders1.push(order2);

    std::vector<Provider * > providersNeeded2 = headquarter.getProvidersThatSatisfy(orders1);

    //One provider that has all the products of the given orders
    EXPECT_EQ(providersNeeded2.size(), 1);
    EXPECT_EQ(providersNeeded2[0]->getName() , "continente");
    EXPECT_EQ(providersNeeded2[0]->getProducts()[headquarter.getProductById(2)] , 285);

    //More than one provider is needed to complete a given order
    order1->addProduct(headquarter.getProductById(6), 5);
    std::queue<Order *> orders2;
    orders2.push(order1);
    orders2.push(order2);

    std::vector<Provider * > providersNeeded3 = headquarter.getProvidersThatSatisfy(orders2);
    EXPECT_EQ(providersNeeded3.size(), 2);
}

TEST(test, calculateTrucksPathFromHeadToProviders){
    Headquarter headquarter("123");

    headquarter.loadAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt", "../src/Resources/trucks.txt", "../src/Resources/orders.txt", "../src/Resources/products.txt");
    headquarter.loadMap("../src/Resources/Maps/penafiel_strong_nodes.txt", "../src/Resources/Maps/penafiel_strong_edges.txt");

    headquarter.distributeOrdersToTrucks();

    headquarter.calculateTrucksPathFromHeadToProviders();
}

TEST(test, getClientsFromOrders){
    Headquarter headquarter("123");

    headquarter.loadAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt", "../src/Resources/trucks.txt", "../src/Resources/orders.txt", "../src/Resources/products.txt");
    headquarter.loadMap("../src/Resources/Maps/penafiel_strong_nodes.txt", "../src/Resources/Maps/penafiel_strong_edges.txt");

    std::queue<Order*> ords;

    Order* order1 = new Order(1);
    Order* order2 = new Order(1);
    Order* order3 = new Order(2);
    Order* order4 = new Order(1);
    Order* order5 = new Order(3);

    order1->addProduct(headquarter.getProductById(1), 5);
    order2->addProduct(headquarter.getProductById(1), 10);
    order3->addProduct(headquarter.getProductById(1), 10);
    order4->addProduct(headquarter.getProductById(1), 10);
    order5->addProduct(headquarter.getProductById(1), 10);

    ords.push(order1);
    ords.push(order2);
    ords.push(order3);
    ords.push(order4);
    ords.push(order5);

    std::vector<Client*> cli = headquarter.getClientsFromOrders(ords);

    std::cout << "AFTER GET CLIENTS" << std::endl;
    for(auto i : cli){
        std::cout << i->getId() << std::endl;
    }
    EXPECT_EQ(cli.size(), 3);
    EXPECT_EQ(cli.at(1)->getId(), 3);
}

TEST(test, calculateTrucksPathFromProvidersToClients){
    Headquarter headquarter("123");

    headquarter.loadAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt", "../src/Resources/trucks.txt", "../src/Resources/orders.txt", "../src/Resources/products.txt");
    headquarter.loadMap("../src/Resources/Maps/penafiel_strong_nodes.txt", "../src/Resources/Maps/penafiel_strong_edges.txt");

    headquarter.distributeOrdersToTrucks();

    headquarter.calculateTrucksPathFromHeadToProviders();

    headquarter.calculateTrucksPathFromProvidersToClients();
}


TEST(test, connectivity){
    Headquarter headquarter("123");
    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");
    Graph<Position> graph = headquarter.getGraph();
    std::vector<std::vector<Vertex<Position> *>> test = graph.connectivity();
    EXPECT_EQ(test.size(), 25);
}

TEST(test, calculateTrucksPaths){
    Headquarter headquarter("123");

    headquarter.loadAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt", "../src/Resources/trucks.txt", "../src/Resources/orders.txt", "../src/Resources/products.txt");
    headquarter.loadMap("../src/Resources/Maps/penafiel_strong_nodes.txt", "../src/Resources/Maps/penafiel_strong_edges.txt");

    headquarter.calculateTrucksPaths();

    std::vector<Truck*> trucks = headquarter.getTrucks();

    for(auto it = trucks.begin(); it != trucks.end(); it++){
        (*it)->showOrders();
    }

    headquarter.saveTruckData("../src/Resources/trucks.txt");

    std::cout <<  "Also check trucks file" << std::endl;
}

TEST(test, deliver){
    Headquarter headquarter("123");

    headquarter.loadAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt", "../src/Resources/trucks.txt", "../src/Resources/orders.txt", "../src/Resources/products.txt");
    headquarter.loadMap("../src/Resources/Maps/porto_strong_nodes.txt", "../src/Resources/Maps/porto_strong_edges.txt");

    headquarter.calculateTrucksPaths();

    headquarter.deliver();
}

/**
 * END OF TESTS
 */

