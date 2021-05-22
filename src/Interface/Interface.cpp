#include "Interface.h"

using namespace std;

void interface(){
    Headquarter headquarter("123");

    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");
    headquarter.loadAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt",
                            "../src/Resources/trucks.txt", "../src/Resources/orders.txt",
                            "../src/Resources/products.txt");

    std::cout << "|||||||| Market On Wheels ||||||||" << std::endl << std::endl;

    //------------------------ CREATING MENUS ------------------------

    //Main Menu
    Menu main_menu = Menu("Choose your user category");
    main_menu.addOption("Client");
    main_menu.addOption("Provider");
    main_menu.addOption("Admin");
    main_menu.addOption("Register");

    Menu client_menu = Menu("Client's Area");
    client_menu.addOption("Make Order");

    Menu providers_menu = Menu("Provider's Area");
    providers_menu.addOption("Add product");
    providers_menu.addOption("Add quantity to product");
    providers_menu.addOption("Show inventory");

    Menu admin_menu = Menu("Administration");
    admin_menu.addOption("Save Data");
    admin_menu.addOption("Calculate optimized paths");  //calculate the optimized paths for each truck
    admin_menu.addOption("Deliver");  //removes all orders that were in the trucks from system
    admin_menu.addOption("Show Trucks");
    admin_menu.addOption("Show Clients");
    admin_menu.addOption("Show Providers");
    admin_menu.addOption("Buy Truck");

    //Register menu
    Menu register_menu = Menu("Register");
    register_menu.addOption("Client");
    register_menu.addOption("Provider");

    bool exit = false;
    while(!exit){
        main_menu.show();
        unsigned int user_category = main_menu.getInput();
        switch (user_category) {
            //exit option
            case 0: {
                cout << "Goodbye! And thanks for your visit!\n" << std::endl;
                exit = true;
                break;
            }
                //client area
            case 1: {
                cout << "Client area\n" << std::endl;
                unsigned int client_id;
                cout << "Enter your client id: " << std::endl;
                do {
                    cout << "->";
                    cin >> client_id;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } while (cin.fail() || headquarter.getClientById(client_id) == nullptr);
                client_menu.show();
                unsigned int client_option = client_menu.getInput();
                switch (client_option) {
                    case 1:{
                        bool end = false;
                        cout << "Give me the product id and the quantity you want. If you want to stop, insert an negative id\n";
                        Order* order = new Order(client_id);
                        headquarter.showProducts();
                        while (!end){
                            cout << "What's the id of the product?\n";
                            int id; cin >> id;
                            if(id < 0){
                                cout << "Thank you for your order\n";
                                end = true;
                                break;
                            }
                            Product* product;
                            try{
                                product = headquarter.getProductById(id);
                            }
                            catch (ProductNotFound) {
                                cout << "We don't have that product\n";
                                continue;
                            }
                            cout << "What's the quantity of the product?\n";
                            int quantity; cin >> quantity;
                            if(quantity < 0){
                                cout << "Invalid quantity\n";
                                continue;
                            }
                            if(order->searchProduct(product->getName())){
                                order->addQuantityOfProduct(product, quantity);
                            } else{
                                order->addProduct(product, quantity);
                            }
                        }
                        if(order->getSize() == 0){
                            cout << "Empty order\n";
                            delete order;
                            break;
                        }
                        if(headquarter.acceptOrder(order)){
                            headquarter.addOrder(order);
                            headquarter.showOrders();
                        } else{
                            cout << "Not enough stock\n";
                            delete order;
                        }
                        break;
                    }
                }
                break;
            }

                //provider area
            case 2:{
                cout << "Provider area\n" << std::endl;
                unsigned int provider_id;
                cout << "Enter your provider id: " << std::endl;
                do {
                    cout << "->";
                    cin >> provider_id;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } while (cin.fail() || headquarter.getClientById(provider_id) == nullptr);
                Provider* provider = headquarter.getProviderById(provider_id);
                cout << provider->getName()<< endl;
                providers_menu.show();
                unsigned int option = providers_menu.getInput();
                switch (option) {
                    //Add a new product
                    case 1: {

                        cout << "What's the product name?\n";
                        string name; cin >> name;

                        cout << "What's the price of the product?\n";
                        float price; cin >> price;
                        if(price < 0){
                            cout << "Invalid price\n";
                            break;
                        }

                        cout << "What's the size of the product?\n";
                        int size; cin >> size;
                        if(size < 0){
                            cout << "Invalid size\n";
                            break;
                        }

                        cout << "What's the quantity of the product?\n";
                        int quantity; cin >> quantity;
                        if(quantity < 0){
                            cout << "Invalid quantity\n";
                            break;
                        }
                        if(provider->searchProduct(name)) {
                            cout << "Product already exists\n";
                            break;
                        }

                        Product* newProduct = headquarter.productSearcher(name);
                        if(newProduct == NULL){
                            newProduct = new Product(name, price, size);
                            headquarter.addProduct(newProduct);
                        }
                        else{
                            cout << "We already sell this product, so it will be our price and characteristics\n";
                        }

                        provider->addProduct(newProduct, quantity);
                        break;
                    }
                        //Add quantity to an existing product
                    case 2: {
                        headquarter.showInventory(provider);
                        cout << "What's the product name?\n";
                        string name; cin >> name;

                        Product* product = headquarter.productSearcher(name);
                        if(product == NULL){
                            cout << "We don't sell this product\n";
                            break;
                        }

                        cout << "What's the quantity of the product?\n";
                        int quantity; cin >> quantity;
                        if(quantity < 0){
                            cout << "Invalid quantity\n";
                            break;
                        }

                        try{
                            provider->addQuantityOfProduct(product, quantity);
                        }
                        catch (ProductNotFound) {
                            cout << "You don't sell this product\n";
                            break;
                        }
                        break;
                    }
                    case 3:
                    {
                        headquarter.showInventory(provider);
                        break;
                    }
                }
                break;
            }
                //admin area
            case 3: {
                cout << "Administration area\n" << std::endl;
                admin_menu.show();
                unsigned int option = admin_menu.getInput();
                switch (option) {
                    //Save Data
                    case 1 :{
                        headquarter.saveAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt",
                                                "../src/Resources/trucks.txt", "../src/Resources/orders.txt",
                                                "../src/Resources/products.txt");
                        break;
                    }
                        //Calculated optimized paths
                    case 2 :{
                        headquarter.calculateTrucksPaths();
                        break;
                    }
                        //Deliver
                    case 3 :{
                        headquarter.deliver();
                        break;
                    }
                        //Show Trucks
                    case 4 :{
                        headquarter.showTrucks();
                        break;
                    }
                        //Show clients
                    case 5 :{
                        headquarter.showClients();
                        break;
                    }
                        //Show providers
                    case 6 :{
                        headquarter.showProviders();
                        break;
                    }
                        //Buy truck
                    case 7:{
                        cout << "What's the capacity?\n";
                        int capacity; cin >> capacity;
                        if(capacity <= 0){
                            cout << "Invalid capacity\n";
                        }
                        else headquarter.addTruck(new Truck(capacity));
                        break;
                    }
                }
                break;
            }
                //register area
            case 4: {
                cout << "Registration area\n" << std::endl;
                register_menu.show();
                unsigned int type = register_menu.getInput();
                switch (type) {
                    case 1: {
                        cout << "Client \n";
                        cout << "Hello Client\n";

                        cout << "What's your name?\n";
                        string name; cin >> name;
                        cout << "What's your user name?\n";
                        string userName; cin >> userName;

                        Date date;
                        cout << "Input your birthdate with format: dd/mm/yyyy" << std::endl;
                        cin >> date;

                        cout << "What's your address id?\n";
                        double address;
                        cin >> address;

                        if(headquarter.clientSearcher(userName)){
                            cout << "You already exist in our company\n";
                            break;
                        }

                        if(!headquarter.positionSearcher(address)){
                            cout << "We can't deliver into you're address\n";
                            break;
                        }

                        if(!headquarter.emptyAddress(address)){
                            cout << "There is someone already living in your address\n";
                            break;
                        }

                        headquarter.addClient(new Client(name, userName, date, address));
                        break;
                    }
                    case 2: {
                        cout << "Provider \n";

                        cout << "What's your name?\n";
                        string name; cin >> name;
                        cout << "What's your user name?\n";
                        string userName; cin >> userName;

                        cout << "What's your address id?\n";
                        double address;
                        cin >> address;

                        if(headquarter.providerSearcher(userName)){
                            cout << "You already exist in our company\n";
                            break;
                        }

                        if(!headquarter.positionSearcher(address)){
                            cout << "We can't deliver into you're address\n";
                            break;
                        }

                        if(!headquarter.emptyAddress(address)){
                            cout << "There is someone already living in your address\n";
                            break;
                        }

                        headquarter.addProvider(new Provider(name, userName, address));
                        break;
                    }
                }

                break;
            }
        }
    }

    headquarter.saveAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt",
                            "../src/Resources/trucks.txt", "../src/Resources/orders.txt",
                            "../src/Resources/products.txt");
}
