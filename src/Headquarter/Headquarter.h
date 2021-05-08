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
    void loadMap(const std::string& nodes_path,const std::string& edges_path);  //imports the designated map in files into graph  //TODO change to exceptions
    void loadData(const std::string& clients_path, const std::string& providers_path, const std::string& trucks_path, const std::string& orders_path);
    void saveData(const std::string& clients_path, const std::string& providers_path, const std::string& trucks_path, const std::string& orders_path);  //TODO change to exeptions
    void showTrucks();
    void showClients();
    Position getPositionById(double id);
    std::string getAdminPassword() const;
    Provider* getProviderById(unsigned int id);
    Client* getClientById(unsigned int id);
};

#endif //SRC_HEADQUARTER_H
