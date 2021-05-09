#include <Headquarter.h>
#include <Menu.h>

int main() {
    Headquarter headquarter(1000000);

    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");

    /**
     * Test to saveProviderData and ProductsWrapper Functions
     */

    Product* potato = new Product("potato", 1.2, 2);
    Product* rice = new Product("rice", 1, 5);
    Product* pasta = new Product("pasta", 2.1, 3);
    Product* tomato = new Product("tomato", 1.3, 1);
    Product* bread = new Product("bread", 0.4, 1);
    Product* water = new Product("water", 1.1, 2);
    Product* wine = new Product("wine", 4.5, 4);
    Product* chips = new Product("chips", 2.3, 3);
/*
    Provider* continente = new Provider("continente", "cont");
    Provider* pingodoce = new Provider("pingodoce", "ping");

    continente->addProduct(potato, 200);
    continente->addProduct(rice, 300);
    continente->addProduct(pasta, 100);
    continente->addProduct(tomato, 30);
    continente->addQuantityOfProduct(tomato, 20);
    continente->removeQuantityOfProduct(tomato, 10);
    continente->removeProduct(pasta);

    std::cout << "diff prods: " << continente->getNumOfDifProducts() << std::endl;

    pingodoce->addProduct(bread, 45);
    pingodoce->addProduct(water, 50);
    pingodoce->addProduct(wine, 120);
    pingodoce->addProduct(chips, 340);

    headquarter.addProvider(continente);
    headquarter.addProvider(pingodoce);

    headquarter.saveProviderData("../src/Resources/providers.txt");
    */

    /**
     * Test to loadProviderData
     */
     /*
    headquarter.loadProviderData("../src/Resources/providers.txt");
    headquarter.showProviders();

    std::map<Product*, unsigned int> prods = headquarter.getProviderById(1)->getProducts();

    for(auto it = prods.begin(); it != prods.end(); it++){
        std::cout << *(*it).first << std::endl;
    }

    std::map<Product*, unsigned int> prods2 = headquarter.getProviderById(2)->getProducts();

    for(auto it = prods2.begin(); it != prods2.end(); it++){
        std::cout << *(*it).first << std::endl;
    }
      */

     /**
      * Test to saveClientData
      */
      /*
      Position position = headquarter.getPositionById(4);
      Client* client = new Client("Jon", "jony", Date(2, 10 ,2000), &position);
      Position position2 = headquarter.getPositionById(10);
      Client* client2 = new Client("Tom", "tomy", Date(25, 4 ,1996), &position2);
      Position position3 = headquarter.getPositionById(21);
      Client* client3 = new Client("Dan", "dan", Date(3, 6 ,1987), &position3);
      Position position4 = headquarter.getPositionById(5);
      Client* client4 = new Client("Mary", "mary", Date(17, 9 ,2005), &position4);

      headquarter.addClient(client);
      headquarter.addClient(client2);
      headquarter.addClient(client3);
      headquarter.addClient(client4);
      headquarter.showClients();

      headquarter.saveClientData("../src/Resources/clients.txt");
       */

      /**
       * Test to loadClientData
       */
/*
      headquarter.loadClientData("../src/Resources/clients.txt");  //TODO position loads all same for now

      headquarter.showClients();
      */

      /**
       * Test to saveTruckData
       */
/*
      Truck *truck = new Truck(700);

      Order* order1;
      Order* order2;

    truck->addOrder(order1);
    truck->addOrder(order2);

      order1->addProduct(tomato, 50);
      order1->addProduct(pasta, 20);
      order1->addProduct(rice, 10);

      order2->addProduct(water, 30);
      order2->addProduct(bread, 10);
      order2->addProduct(wine, 23);



      headquarter.addTruck(truck);

      headquarter.showTrucks();*/

    //std::cout << "|||||||| Market On Wheels ||||||||" << std::endl << std::endl;

    //------------------------ CREATING MENUS ------------------------

    /*Menu main_menu = Menu("Choose your user category");
    main_menu.addOption("Client");
    main_menu.addOption("Provider");
    main_menu.addOption("Admin");
    main_menu.addOption("Register");

    Menu admin_menu = Menu("Administration");
    admin_menu.addOption("Import Data");
    admin_menu.addOption("Save Data");
    admin_menu.addOption("Calculate optimized paths");  //calculate the optimized paths for each truck
    admin_menu.addOption("Deliver");  //removes all orders that were in the trucks from system
    admin_menu.addOption("Show Trucks");
    admin_menu.addOption("Show Clients");
    admin_menu.addOption("Show Providers");

    Menu client_menu = Menu("Client's Area");
    client_menu.addOption("Make Order");
    client_menu.addOption("Cancel Order");
    client_menu.addOption("Show info");

    Menu providers_menu = Menu("Provider's Area");
    providers_menu.addOption("Add product");
    providers_menu.addOption("Remove Product");
    providers_menu.addOption("Add Quantity to product");
    providers_menu.addOption("Remove Quantity to product");
    providers_menu.addOption("Show info");


    Menu register_menu = Menu("Register");
    register_menu.addOption("Client");
    register_menu.addOption("Provider");

    main_menu.show();
    unsigned int user_category = main_menu.getInput();

    switch(user_category) {
        //error on input
        case 0:{
            std::cout << "Error on input" << std::endl;
            break;
        }
        //client area
        case 1:{
            unsigned int client_id;
            std::cout << "Enter your client id: " << std::endl;
            do {
                std::cout << "->";
                std::cin >> client_id;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } while(std::cin.fail() || headquarter.getClientById(client_id) == nullptr);
            break;
        }
        //provider area
        case 2:{
            unsigned int provider_id;
            std::cout << "Enter your provider id: " << std::endl;
            do {
                std::cout << "->";
                std::cin >> provider_id;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } while(std::cin.fail() || headquarter.getProviderById(provider_id) == nullptr);
            break;
        }
        //admin area
        case 3:{
            std::string admin_pass;
            std::cout << "Enter the admin password: " << std::endl;
            do {
                std::cout << "->";
                std::cin >> admin_pass;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } while(std::cin.fail() || headquarter.getAdminPassword() == admin_pass);
            break;
        }
        //registering area
        case 4:{
            register_menu.show();
            int option;
            do {
                std::cout << "->";
                std::cin >> option;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } while(std::cin.fail());
            if(option == 1){
                std::cout << "Hello Client\n";
            }
            else{
                std::cout << "Hello Provider\n";
            }
            break;
        }
    }*/

    return 0;
}
