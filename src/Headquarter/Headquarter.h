#ifndef SRC_HEADQUARTER_H
#define SRC_HEADQUARTER_H

#include <vector>
#include <fstream>
#include <sstream>
#include <Provider.h>
#include <Client.h>
#include <Truck.h>
#include <Utils.h>

class Headquarter {
private:
    std::vector<Client*> clients;
    std::vector<Provider*> providers;
    std::vector<Truck*> trucks;
    std::vector<Order*> orders;
    Position* address;
    Graph<Position> graph;
    std::string admin_password = "123";
public:
    /**
     * Headquarters constructor
     * @param adminPassword Pass code to enter with admin privileges
     */
    Headquarter(std::string adminPassword);


    //##################### GETTERS #########################################
    /**
     * Gets the Graph of the map that is being used
     *
     * @return the graph of the map
     */
    Graph<Position> getGraph() const;

    /**
     * Gets the headquarters admin password
     *
     * @return the admin password
     */
    std::string getAdminPassword() const;

    //##################### Add methods #####################################

    /**
     * Adds a client to the headquarters database
     *
     * @param client to be added
     */
    void addClient(Client* client);

    /**
     * More complete function to add a client
     * @param name Client name
     * @param userName Client userName
     * @param id Client Id
     */
    void addClient(std::string name, std::string userName, double id);

    /**
     * Adds a provider to the headquarters database
     *
     * @param provider to be added
     */
    void addProvider(Provider* provider);

    /**
     * Adds a truck to the headquarters database
     *
     * @param truck to be added
     */
    void addTruck(Truck* truck);

    /**
     * Adds an order to the orders made to the company
     *
     * @param order the order to be added
     */
    void addOrder(Order* order);

    //##################### Load data methods ###############################
    /**
     * Imports map into graph from file
     * @param nodes_path the path to the file where graph nodes are stored
     * @param edges_path the path to the file where graph edges are stored
     */
    void loadMap(const std::string& nodes_path,const std::string& edges_path);  //imports the designated map in files into graph  //TODO change to exceptions


    /**
     * Loads all company data into the program
     *
     * @param clients_path path to the clients file
     * @param providers_path path to the providers file
     * @param trucks_path path to the trucks file
     */
    void loadData(const std::string& clients_path, const std::string& providers_path, const std::string& trucks_path, const std::string& orders_path);

    /**
     * Function to load the provider data
     * @param providers_path File to load data
     */
    void loadProvider(const std::string& providers_path);

    //##################### Save data methods ###############################
    /**
     * Function to save provider data
     * @param providers_path
     */
    void saveProvider(const std::string& providers_path);

    /**
     * Saves all company data into the program
     *
     * @param clients_path path to the clients file
     * @param providers_path path to the providers file
     * @param trucks_path path to the trucks file
     */
    void saveData(const std::string& clients_path, const std::string& providers_path, const std::string& trucks_path, const std::string& orders_path);  //TODO change to exeptions

    //##################### Show collections methods ########################

    /**
     * Displays trucks to user
     */
    void showTrucks();

    /**
     * Shows the providers to the user
     */
    void showProviders();

    /**
     * Show client
     */
    void showClients();

    //##################### Search methods ##################################
    /**
     * Gets the position in graph with the id specified
     *
     * @param id the id of the position to look for
     * @return the position wanted
     */

    Position getPositionById(double id);

    /**
     * Gets a specific provider
     *
     * @param id the id of the provider
     * @return the provider wanted if exists, else nullptr
     */
    Provider* getProviderById(unsigned int id);

    /**
     * Gets a specific client
     *
     * @param id the id of the client
     * @return the client wanted if exists, else nullptr
     */
    Client* getClientById(unsigned int id);

    /**
     * Checks if a client is already registed
     * @param userName Cliient user name
     * @return True if it is registered, false otherwise
     */
    bool isClientRegistered(std::string userName);

};

#endif //SRC_HEADQUARTER_H
