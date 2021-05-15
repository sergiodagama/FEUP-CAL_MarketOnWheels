#include <Headquarter.h>
#include <Menu.h>

/*#include "gtest/gtest.h"
#include "gmock/gmock.h"*/

//NOTE: uncomment the google tests to run tests
// and comment the rest of the code
using namespace std;

int main(int argc, char *argv[]) {
    //Criação de headquarter
    Headquarter headquarter("123");

    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");

    std::cout << "|||||||| Market On Wheels ||||||||" << std::endl << std::endl;

    //------------------------ CREATING MENUS ------------------------

    //Main Menu
    Menu main_menu = Menu("Choose your user category");
    main_menu.addOption("Client");
    main_menu.addOption("Provider");
    main_menu.addOption("Admin");
    main_menu.addOption("Register");

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
                break;
            }
            //provider area
            case 2:{
                cout << "Provider area\n" << std::endl;
                break;
            }
            //admin area
            case 3: {
                cout << "Administration area\n" << std::endl;
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

                        headquarter.addClient(new Client(name, userName, date, address));
                        break;
                    }
                    case 2: {
                        cout << "Provider \n";
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

/*Menu admin_menu = Menu("Administration");
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
*/

    /*       case 1: {*/
                /*unsigned int client_id;
                std::cout << "Enter your client id: " << std::endl;
                do {
                    std::cout << "->";
                    std::cin >> client_id;
                    if (client_id == 0) {
                        exit = true;
                        break;
                    }
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } while (std::cin.fail() || headquarter.getClientById(client_id) == nullptr);
                unsigned int client_option;*/
               /* if (!exit) {
                    client_menu.show();
                    client_option = client_menu.getInput();
                }

                switch (client_option) {
                    case 1: {
                        break;
                    }
                    case 2: {
                        break;
                    }
                    case 3: {
                        break;
                    }
                }
                break;*/
//            }
            //provider area
         //   case 2: {
                /*unsigned int provider_id;
                std::cout << "Enter your provider id: " << std::endl;
                do {
                    std::cout << "->";
                    std::cin >> provider_id;
                    if (provider_id == 0) {
                        exit = true;
                        break;
                    }
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } while (std::cin.fail() || headquarter.getProviderById(provider_id) == nullptr);
                unsigned int providers_option;
                if (!exit) {
                    providers_menu.show();
                    providers_option = providers_menu.getInput();
                }

                switch (providers_option) {
                    //Import data
                    case 1: {
                        std::cout << "Importing data into program structures..." << std::endl;
                        headquarter.loadAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt",
                                                "../src/Resources/trucks.txt", "src/Resources/orders.txt",
                                                "../src/Resources/products.txt");
                        break;
                    }
                        //Save data
                    case 2: {
                        std::cout << "Saving data into files.." << std::endl;
                        headquarter.saveAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt",
                                                "../src/Resources/trucks.txt", "../src/Resources/orders.txt",
                                                "../src/Resources/products.txt");
                        break;
                    }
                        //Calculate optimized paths
                    case 3: {
                        break;
                    }
                        //Deliver
                    case 4: {
                        break;
                    }
                        //Show Trucks
                    case 5: {
                        headquarter.showTrucks();
                        break;
                    }
                        //Show Clients
                    case 6: {
                        //headquarter.showClients();
                        break;
                    }
                        //Show Providers
                    case 7: {
                        break;
                    }
                }
                break;
            }*/
            //admin area
         //   case 3: {
                /*std::string admin_pass;
                std::cout << "Enter the admin password: " << std::endl;
                do {
                    std::cout << "->";
                    std::cin >> admin_pass;
                    if (admin_pass == "0") {
                        exit = true;
                        break;
                    }
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } while (std::cin.fail() || headquarter.getAdminPassword() != admin_pass);
                break;*/
           // }
                //registering area
          //  case 4: {

               /* if (option == 1) {
                    std::cout << "Hello Client\n";

                    std::cout << "What's your name?\n";
                    std::string name;
                    std::cin >> name;

                    std::cout << "What's your user name?\n";
                    std::string userName;
                    std::cin >> userName;

                    Date date;
                    std::cout << "Input your birthdate with format: dd/mm/yyyy" << std::endl;
                    std::cin >> date;

                    std::cout << "What's your address id?\n";
                    double address;
                    std::cin >> address;

                    headquarter.addClient(new Client(name, userName, date, address));
                } else {
                    std::cout << "Hello Provider\n";
                    break;*/
              /*  }
                break;
            }
        }
    }*/
    //saves all data even if user doesn't want it
   /*
    return 0;
}*/


/* testing::InitGoogleTest(&argc, argv);
    std::cout << "\n\n----------MARKETONWHEELS TESTS----------" << std::endl;
    return RUN_ALL_TESTS();*/