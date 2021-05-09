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
    unsigned int capital;
    Position* address;
    Graph<Position> graph;
    std::string admin_password = "123";
public:
    Headquarter(unsigned int capital);
    Graph<Position> getGraph() const;
    void addClient(Client* client);
    void addProvider(Provider* provider);
    void addTruck(Truck* truck);
    void addOrder(Order* order);
    Provider* getProviderById(unsigned int id);
    Client* getClientById(unsigned int id);
    Position getPositionById(double id);
    std::string getAdminPassword() const;

    //FILE LOADERS & SAVERS
    void loadMap(const std::string& nodes_path,const std::string& edges_path);  //imports the designated map in files into graph  //TODO change to exceptions
    void loadAllData(const std::string& clients_path, const std::string& providers_path, const std::string& trucks_path, const std::string& orders_path);
    void saveAllData(const std::string& clients_path, const std::string& providers_path, const std::string& trucks_path, const std::string& orders_path);  //TODO change to exceptions
    void saveClientData(const std::string& clients_path);
    void loadClientData(const std::string& clients_path);
    void loadProviderData(const std::string& providers_path);
    void saveProviderData(const std::string& providers_path);
    void saveTruckData(const std::string& trucks_path);
    void loadTruckData(const std::string& trucks_path);
    void saveOrderData(const std::string& orders_path);
    void loadOrderData(const std::string& orders_path);

    //DATA SHOWERS
    void showClients();
    void showProviders();
    void showTrucks();
    void showOrders();
};

#endif //SRC_HEADQUARTER_H
