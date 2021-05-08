#include <Headquarter.h>
#include <Menu.h>

int main() {
    Headquarter headquarter(1000000);

    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");

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

    //------------------------ DISPLAYING MENUS AND MANIPULATING HEADQUARTER ------------------------

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

            client_menu.show();
            unsigned int client_option = client_menu.getInput();

            switch (client_option) {
                case 1:{
                    break;
                }
                case 2:{
                    break;
                }
                case 3:{
                    break;
                }
            }
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

            providers_menu.show();

            unsigned int providers_option = providers_menu.getInput();

            switch(providers_option){
                //Import data
                case 1:{
                    std::cout << "Importing data into program structures..." << std::endl;
                    headquarter.loadData("src/Resources/clients.txt", "src/Resources/providers.txt", "src/Resources/trucks.txt", "src/Resources/orders.txt");
                    break;
                }
                //Save data
                case 2:{
                    std::cout << "Saving data into files.." << std::endl;
                    headquarter.saveData("src/Resources/clients.txt", "src/Resources/providers.txt", "src/Resources/trucks.txt", "src/Resources/orders.txt");
                    break;
                }
                //Calculate optimized paths
                case 3:{
                    break;
                }
                //Deliver
                case 4:{
                    break;
                }
                //Show Trucks
                case 5:{
                    headquarter.showTrucks();
                    break;
                }
                //Show Clients
                case 6:{
                    //headquarter.showClients();
                    break;
                }
                //Show Providers
                case 7:{
                    break;
                }
            }
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
            } while(std::cin.fail() || headquarter.getAdminPassword() != admin_pass);
            break;
        }
        //registering area
        case 4:{
            break;
        }
    }

    return 0;
}
