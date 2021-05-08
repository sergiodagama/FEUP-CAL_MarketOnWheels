#include <Headquarter.h>
#include <Menu.h>

int main() {
    Headquarter headquarter("123");

    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");
    //std::map<Product *, unsigned int> products;

    //Product * product = new Product("batata", 1.2, 3);
    //Product * product2 = new Product("batata", 1.3, 3);
    //products.insert(std::pair<Product * ,unsigned int>(product,100));
    //products.insert(std::pair<Product * ,unsigned int>(product2,150));

    //Provider * provider = new Provider("FEUP", "frtrgtye", products);
    //Provider * provider2 = new Provider("FMUP", "gtghtr", products);

    /*headquarter.addProvider(provider);
    headquarter.addProvider(provider2);*/

    //headquarter.saveProvider("../src/Resources/providers.txt");
    /*headquarter.loadProvider("../src/Resources/providers.txt");
    headquarter.showProviders();*/

    std::cout << "|||||||| Market On Wheels ||||||||" << std::endl << std::endl;

    //------------------------ CREATING MENUS ------------------------

    Menu main_menu = Menu("Choose your user category");
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

    bool exit = false;
    while(!exit) {
        main_menu.show();
        unsigned int user_category = main_menu.getInput();
        switch (user_category) {
            //exit option
            case 0: {
                std::cout << "Goodbye" << std::endl;
                exit = true;
                break;
            }
            //client area
            case 1: {
                unsigned int client_id;
                std::cout << "Enter your client id: " << std::endl;
                do {
                    std::cout << "->";
                    std::cin >> client_id;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } while (std::cin.fail() || headquarter.getClientById(client_id) == nullptr);
                break;
            }
            //provider area
            case 2: {
                unsigned int provider_id;
                std::cout << "Enter your provider id: " << std::endl;
                do {
                    std::cout << "->";
                    std::cin >> provider_id;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } while (std::cin.fail() || headquarter.getProviderById(provider_id) == nullptr);
                break;
            }
                //admin area
            case 3: {
                std::string admin_pass;
                std::cout << "Enter the admin password: " << std::endl;
                do {
                    std::cout << "->";
                    std::cin >> admin_pass;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } while (std::cin.fail() || headquarter.getAdminPassword() != admin_pass);
                break;
            }
            //registering area
            case 4: {
                register_menu.show();
                int option;
                do {
                    std::cout << "->";
                    std::cin >> option;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } while (std::cin.fail());
                if (option == 1) {
                    std::cout << "Hello Client\n";

                    std::cout << "What's your name?\n";
                    std::string name;
                    std::cin >> name;

                    std::cout << "What's your user name?\n";
                    std::string userName;
                    std::cin >> userName;

                    std::cout << "What's your address id?\n";
                    double address;
                    std::cin >> address;

                    headquarter.addClient(name, userName, address);
                } else {
                    std::cout << "Hello Provider\n";
                    break;
                }
                break;
            }
        }
    }
    headquarter.saveData("../src/Resources/clients.txt", "", "");
    return 0;
}
