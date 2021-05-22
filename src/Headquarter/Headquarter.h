#ifndef SRC_HEADQUARTER_H
#define SRC_HEADQUARTER_H

#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <map>
#include <set>
#include <Provider.h>
#include <Client.h>
#include <Truck.h>
#include <Utils.h>

class Headquarter {
private:
    std::vector<Client *> clients;
    std::vector<Provider *> providers;
    std::vector<Truck *> trucks;
    std::vector<Order *> orders;
    std::vector<Product *> products;
    unsigned int position_id = 1;
    Graph<Position> graph;
    std::string admin_password = "123";
public:

    //-----------------------CONSTRUCTOR(S)-----------------------

    /**
    * Headquarters constructor
    * @param password to the administration
    */
    Headquarter(std::string admin_pass);

    //-------------------------GETTERS-------------------------

    bool emptyAddress(double idVertex);

    /**
     * Check if a client already exists
     * @param userName Client user name
     * @return True if it already exists, false otherwise
     */
    bool clientSearcher(std::string userName);

    /**
     * Checks if the map has a certain position
     * @param idVertex Vertex id of the graph
     * @return True if the vertex exists and is a reachable, false otherwise //TODO
     */
    bool positionSearcher(double idVertex);

    /**
     * Checks if the company has a certain provider
     * @param userName Provider name
     * @return True if the provider already exists, false otherwise
     */
    bool providerSearcher(std::string userName);

    /**
     * Checks if the company has a certain product
     * @param name Product name
     * @return True if the product already exists, false otherwise
     */
    Product* productSearcher(std::string name);

    /**
     * Function that checks if there is stock enough to supply a certain order
     * @param order The order to be supplied
     * @return True if the order can be supplied, false otherwise
     */
    bool acceptOrder(Order* order);

    /**
    * Gets the Graph of the map that is being used
    *
    * @return the graph of the map
    */
    Graph<Position> getGraph() const;

    /**
    * Gets a specific provider
    *
    * @param id the id of the provider
    * @return the provider wanted if exists, else nullptr
    */
    Provider *getProviderById(unsigned int id);

    /**
    * Gets a specific client
    *
    * @param id the id of the client
    * @return the client wanted if exists, else nullptr
    */
    Client *getClientById(unsigned int id);

    /**
     * Gets order by id
     *
     * @param id id of the order
     * @return the order wanted
     */
    Order *getOrderById(unsigned int id);

    /**
     * Gets product by id
     *
     * @param id the product id
     * @return the product wanted
     */
    Product *getProductById(unsigned int id);

    /**
    * Gets truck by id
    *
    * @param id the truck id
    * @return the truck wanted
    */
    Truck *getTruckById(unsigned int id);

    /**
     * Gets the trucks from headquarter
     */
     std::vector<Truck*> getTrucks() const;

    /**
    * Gets the position in graph with the id specified
    *
    * @param id the id of the position to look for
    * @return the position wanted
    */
    Position getPositionById(double id);

    /**
    * Gets the headquarters admin password
    *
    * @return the admin password
    */
    std::string getAdminPassword() const;

    /**
     * Gets the number of products listed
     *
     * @return the number of products listed
     */
    unsigned int getNProducts() const;

    /**
    * Gets the number of clients
    *
    * @return the number of clients
    */
    unsigned int getNClients() const;

    /**
    * Gets the number of orders
    *
    * @return the number of orders
    */
    unsigned int getNOrders() const;

    /**
    * Gets the number of trucks
    *
    * @return the number of trucks
    */
    unsigned int getNTrucks() const;

    //-------------------------ADDERS-------------------------

    /**
    * Adds a client to the headquarters database
    *
    * @param client to be added
    */
    void addClient(Client *client);

    /**
    * Adds a provider to the headquarters database
    *
    * @param provider to be added
    */
    void addProvider(Provider *provider);

    /**
    * Adds a truck to the headquarters database
    *
    * @param truck to be added
    */
    void addTruck(Truck *truck);

    /**
    * Adds an order to the orders made to the company
    *
    * @param order the order to be added
    */
    void addOrder(Order *order);

    /**
     * Removes an order by its id
     *
     * @param id the order id
     */
    void removeOrderById(unsigned int id);

    /**
     * Adds a product to headquarters database
     *
     * @param product the product to be added
     */
    void addProduct(Product *product);

    //-------------------------FILE LOADERS & SAVERS-------------------------

    /**
    * Imports map into graph from file
    * @param nodes_path the path to the file where graph nodes are stored
    * @param edges_path the path to the file where graph edges are stored
    */
    void loadMap(const std::string &nodes_path,
                 const std::string &edges_path);

    /**
    * Loads all company data into the program
    *
    * @param clients_path path to the clients file
    * @param providers_path path to the providers file
    * @param trucks_path path to the trucks file
    * @param orders_path path to file of company orders
    * @param products_path path to file of products listed
    */
    void loadAllData(const std::string &clients_path, const std::string &providers_path, const std::string &trucks_path,
                     const std::string &orders_path, const std::string &products_path);

    /**
    * Saves all company data into files
    *
    * @param clients_path path to the clients file
    * @param providers_path path to the providers file
    * @param trucks_path path to the trucks file
    * @param orders_path path to file of company orders
    * @param products_path path to file of products listed
    */
    void saveAllData(const std::string &clients_path, const std::string &providers_path, const std::string &trucks_path,
                     const std::string &orders_path, const std::string &products_path);

    /**
    * Saves all clients data in it respective file
    * @param clients_path the path to the clients file
    */
    void saveClientData(const std::string &clients_path);

    /**
    * Loads all clients data into program
    * @param clients_path the path to the clients file
    */
    void loadClientData(const std::string &clients_path);

    /**
    * Saves all providers data in it respective file
    * @param providers_path the path to the providers file
    */
    void saveProviderData(const std::string &providers_path);

    /**
    * Loads all providers data into program
    * @param providers_path the path to the providers file
    */
    void loadProviderData(const std::string &providers_path);

    /**
    * Saves all trucks data in it respective file
    * @param trucks_path the path to the trucks file
    */
    void saveTruckData(const std::string &trucks_path);

    /**
    * Loads all trucks data into program
    * @param trucks_path the path to the trucks file
    */
    void loadTruckData(const std::string &trucks_path);

    /**
    * Saves all orders data in it respective file
    * @param orders_path the path to the order file
    */
    void saveOrderData(const std::string &orders_path);

    /**
    * Loads all orders data into program
    * @param orders_path the path to the orders file
    */
    void loadOrderData(const std::string &orders_path);

    /**
    * Saves all products data in it respective file
    * @param products_path the path to the products file
    */
    void saveProductData(const std::string &products_path);

    /**
    * Loads all products data into program
    * @param products_path the path to the products file
    */
    void loadProductData(const std::string &products_path);

    //-------------------------DATA SHOWERS-------------------------

    /**
    * Displays products listed to user
    */
    void showProducts();

    /**
    * Displays clients to user
    */
    void showClients();

    /**
    * Shows the providers to the user
    */
    void showProviders();

    /**
    * Displays trucks to user
    */
    void showTrucks();

    /**
    * Displays orders to user
    */
    void showOrders();

    /**
    * Displays the inventory to user
    */
    void showInventory(Provider * provider);

    //------------------------- FUNCTIONS TO HANDLE DELIVERS -------------------------

    /**
    * It uses a greedy approach by starting with a sort of the orders that exist, by price,
    * so that are added the most valuable orders first.
    * After that, if an order is added to the truck, the other orders of the same client
    * are given priority. If there are no space, the algorithm follows the same logical order,
    * however it keep trying all the next orders, until the truck is full, or there are no more orders
    * As it adds the orders to trucks, sets order flag to true, so that they can't be added more than once
    */
    void distributeOrdersToTrucks();

    /**
    * Gets a vector of providers that entirely satisfies a set of orders given
    * This vector has some particular characteristics, it is optimized by the distance,
    * so the providers are added by distance from the headquarter, until the orders
    * are all able to be satisfied
    *
    * @param orders the orders from given from a truck
    * @return a vector of providers optimized that satisfy all the orders
    */
    std::vector<Provider *> getProvidersThatSatisfy(std::queue<Order*> orders);

    /**
    * Calculates initial path of the trucks to their providers (using function getProvidersThatSatisfy to get the providers list)
    * in order to fulfill their orders
    *
    */
    void calculateTrucksPathFromHeadToProviders();

    /**
     * Gets all the clients from a given set of orders
     * It also orders those clients, by the least distance between them, from the first client picked up
     * It's a pseudo optimization, because the first client it's randomly picked up
     *
     * @param orders the set of orders passed from trucks
     * @return the clients ordered with the respective optimization
     */
    std::vector<Client*> getClientsFromOrders(std::queue<Order*> orders);

     /**
     * Calculates final path of the trucks from providers to clients and to headquarter
     */
    void calculateTrucksPathFromProvidersToClients();

    /**
    * Calculate trucks paths (join the two functions: calculateTrucksPathFromHeadToProviders, calculateTrucksPathFromProvidersToClients)
    */
    void calculateTrucksPaths();

    /**
    * Delivering the respective orders to clients (empty all trucks)
    */
    void deliver();
};

#endif //SRC_HEADQUARTER_H
