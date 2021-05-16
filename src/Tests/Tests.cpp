#include <gtest/gtest.h>
#include <Headquarter.h>

/**
 * TESTS TO HEADQUARTERS FUNCTIONS AND CLASSES
 */

using testing::Eq;

TEST(test, saveProductData) {
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

    headquarter.saveProductData("../src/Resources/products.txt");

    std::cout << std::endl << "SEE INFORMATION ON PRODUCTS FILE" << std::endl;
}

//run after saving test
TEST(test, loadProductData) {
    Headquarter headquarter("1000000");
    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");

    headquarter.loadProductData("../src/Resources/products.txt");
    headquarter.showProducts();
    EXPECT_EQ(headquarter.getNProducts(), 8);
}

TEST(test, saveProviderData) {
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

    Provider* continente = new Provider("continente", "cont", 30);
    Provider* pingodoce = new Provider("pingodoce", "ping", 31);

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
    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");
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
    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");

    Client* client = new Client("Jon", "jony", Date(2, 10 ,2000), 4);
    Client* client2 = new Client("Tom", "tomy", Date(25, 4 ,1996), 10);
    Client* client3 = new Client("Dan", "dan", Date(3, 6 ,1987), 21);
    Client* client4 = new Client("Mary", "mary", Date(17, 9 ,2005), 5);

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
    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");

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
    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");
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
    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");
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
    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");

    headquarter.loadProductData("../src/Resources/products.txt");
    headquarter.loadOrderData("../src/Resources/orders.txt");
    headquarter.loadTruckData("../src/Resources/trucks.txt");

    EXPECT_EQ(headquarter.getNTrucks(), 2);

    headquarter.showTrucks();
}

TEST(test, distributeOrdersToTrucks){
    Headquarter headquarter("1000000");

    headquarter.loadClientData("../src/Resources/clients.txt");
    headquarter.loadProductData("../src/Resources/products.txt");

    Truck* truck = new Truck(100);

    Order* order1 = new Order(1);
    Order* order2 = new Order(2);
    Order* order3 = new Order(3);
    Order* order4 = new Order(4);

    order1->addProduct(headquarter.getProductById(2), 5);
    order2->addProduct(headquarter.getProductById(2), 10);
    order3->addProduct(headquarter.getProductById(2), 5);
    order4->addProduct(headquarter.getProductById(2), 5);

    headquarter.addOrder(order1);
    headquarter.addOrder(order2);
    headquarter.addOrder(order3);
    headquarter.addOrder(order4);

    headquarter.addTruck(truck);

    headquarter.distributeOrdersToTrucks();

    headquarter.showTrucks();

    //capacity greater than order size
}