#include "Headquarter.h"

using namespace std;

/**
 * Headquarters constructor
 * @param capital the capital (funds) that the company has
 */
Headquarter::Headquarter(unsigned int capital) {
    this->capital = capital;
}

/**
 * Gets the Graph of the map that is being used
 *
 * @return the graph of the map
 */
Graph<Position> Headquarter::getGraph() const {
    return graph;
}

/**
 * Adds a client to the headquarters database
 *
 * @param client to be added
 */
void Headquarter::addClient(Client* client) {
    clients.push_back(client);
}

/**
 * Adds a provider to the headquarters database
 *
 * @param provider to be added
 */
void Headquarter::addProvider(Provider *provider) {
    providers.push_back(provider);
}

/**
 * Adds a truck to the headquarters database
 *
 * @param truck to be added
 */
void Headquarter::addTruck(Truck *truck) {
    trucks.push_back(truck);
}

/**
 * Adds an order to the orders made to the company
 *
 * @param order the order to be added
 */
void Headquarter::addOrder(Order *order) {
    orders.push_back(order);
}

/**
 * Imports map into graph from file
 * @param nodes_path the path to the file where graph nodes are stored
 * @param edges_path the path to the file where graph edges are stored
 */
void Headquarter::loadMap(const std::string& nodes_path, const std::string& edges_path) {
    ifstream nodesFile(nodes_path);
    ifstream edgesFile(edges_path);

    string line;
    double id, id2;
    long double latitude, longitude;
    bool firstLine = true;

    //reading nodes file
    if (nodesFile.is_open()) {
        while(getline(nodesFile,line)){
            if(firstLine){
                firstLine = false;
                continue;
            }
            else{
                //removing parenthesis, followed by spaces
                line = line.substr(1, line.size() - 2);
                line.erase(remove(line.begin(), line.end(), ' '), line.end());

                //splitting each line into it's corresponding values
                stringstream ss(line);

                string splitted;
                getline(ss, splitted, ',');
                id = stod(splitted);
                getline(ss, splitted, ',');
                latitude = stold(splitted);
                getline(ss, splitted, ',');
                longitude = stold(splitted);

                //creating vertex and inserting into graph
                if(!graph.addVertex(Position(id, latitude, longitude))){
                    cout << "ERROR" << endl;
                }

                //cout << line << '\n';
            }
        }
        nodesFile.close();
    }
    else cout << "Unable to open nodes file";

    firstLine = true;

    //reading edges file
    if (edgesFile.is_open()) {
        while(getline(edgesFile,line)){
            if(firstLine){
                firstLine = false;
                continue;
            }
            else{
                //removing parenthesis, followed by spaces
                line = line.substr(1, line.size() - 2);
                line.erase(remove(line.begin(), line.end(), ' '), line.end());

                //splitting each line into it's corresponding values
                stringstream ss(line);

                string splitted;
                getline(ss, splitted, ',');
                id = stod(splitted);
                getline(ss, splitted, ',');
                id2 = stod(splitted);

                //retrieving both positions and distance and inserting edge into graph
                Position position = getPositionById(id);
                Position position2 = getPositionById(id2);
                if(!graph.addEdge(position, position2, distanceBetweenTwoPos(position, position2))){
                    cout << "ERROR" << endl;
                };

                //cout << line << '\n';
            }
        }
        nodesFile.close();
    }
    else cout << "Unable to open edges file";
}

/**
 * Gets the position in graph with the id specified
 *
 * @param id the id of the position to look for
 * @return the position wanted
 */
Position Headquarter::getPositionById(double id) {
    return graph.findVertex(Position(id, 0, 0))->getInfo();
}

/**
 * Loads all company data into the program
 *
 * @param clients_path path to the clients file
 * @param providers_path path to the providers file
 * @param trucks_path path to the trucks file
 */
void Headquarter::loadAllData(const string &clients_path, const string &providers_path, const string &trucks_path, const string& orders_path) {
/*    loadClientData(clients_path);
    loadProviderData(providers_path);
    loadTruckData(trucks_path);
    loadOrderData(orders_path);*/
}

/**
 * Saves all company data into the program
 *
 * @param clients_path path to the clients file
 * @param providers_path path to the providers file
 * @param trucks_path path to the trucks file
 */
void Headquarter::saveAllData(const string &clients_path, const string &providers_path, const string &trucks_path, const string &orders_path) {
    saveClientData(clients_path);
    saveProviderData(providers_path);
    saveTruckData(trucks_path);
    saveOrderData(orders_path);
}

/**
 * Displays trucks to user
 */
void Headquarter::showTrucks() {
    if(trucks.empty()){
        cout << "It does not exist any truck yet" << endl;
        return;
    }
    cout << "Id\tCapacity\tLoad\tState" << endl;
    for(auto it = trucks.begin(); it != trucks.end(); it++){
        cout << (*it)->getId() << "\t" << (*it)->getCapacity() << "\t" << (*it)->getLoad() << "\t" << (*it)->getState() << endl;
    }
}

/**
 * Displays clients to user
 */
void Headquarter::showClients() {
    if(clients.empty()){
        cout << "It does not exist any client yet" << endl;
        return;
    }
    cout << "Id\tName\tUsername\tDate\t\tAdressId" << endl;
    for(auto it = clients.begin(); it != clients.end(); it++){
        cout << (*it)->getId() << "\t" << (*it)->getName() << "\t" << (*it)->getUserName() << "\t\t" << (*it)->getDate() << "\t" << *(*it)->getAddress() << endl;
    }
}

/**
 * Gets the headquarters admin password
 *
 * @return the admin password
 */
string Headquarter::getAdminPassword() const {
    return admin_password;
}

/**
 * Gets a specific provider
 *
 * @param id the id of the provider
 * @return the provider wanted if exists, else nullptr
 */
Provider* Headquarter::getProviderById(unsigned int id) {
    for(auto it = providers.begin(); it != providers.end(); it++){
        if((*it)->getId() == id) return (*it);
    }
    return nullptr;
}

/**
 * Gets a specific client
 *
 * @param id the id of the client
 * @return the client wanted if exists, else nullptr
 */
Client* Headquarter::getClientById(unsigned int id) {
    for(auto it = clients.begin(); it != clients.end(); it++){
        if((*it)->getId() == id) return (*it);
    }
    return nullptr;
}

/**
 * Shows the providers to the user
 */
void Headquarter::showProviders() {
    if(providers.empty()){
        cout << "It does not exist any provider yet" << endl;
        return;
    }
    cout << "Id\tName\t\tUserName\tNumberOfProducts" << endl;
    for(auto it = providers.begin(); it != providers.end(); it++){
        cout << (*it)->getId() << "\t" << (*it)->getName() << "\t" << (*it)->getUserName() << "\t\t" << (*it)->getNumOfDifProducts() << endl;
    }

}

/**
 * Saves all providers data in it respective file
 * @param providers_path the path to the providers path
 */
void Headquarter::saveProviderData(const string &providers_path) {
    //providers
    ofstream providerFile(providers_path);

    if(providerFile.is_open()){
        for(auto it = providers.begin(); it != providers.end(); it++) {
            providerFile << *(*it);
        }
    }
    else cout << "Unable to open providers file" << endl;
    providerFile.close();

}


void Headquarter::saveTruckData(const string& trucks_path) {
    //trucks
    ofstream truckFile(trucks_path);

    if(truckFile.is_open()){
        for(auto it = trucks.begin(); it != trucks.end(); it++) {
            truckFile << *(*it);
        }
    }
    else cout << "Unable to open trucks file" << endl;
    truckFile.close();
}

void Headquarter::saveClientData(const string &clients_path) {
    ofstream clientFile(clients_path);

    if(clientFile.is_open()){
        for(auto it = clients.begin(); it != clients.end(); it++) {
            clientFile << *(*it);
        }
    }
    else cout << "Unable to open clients file" << endl;
    clientFile.close();
}

void Headquarter::saveOrderData(const string &orders_path) {
    ofstream orderFile(orders_path);

    if(orderFile.is_open()){
        for(auto it = orders.begin(); it != orders.end(); it++) {
            orderFile << *(*it);
        }
    }
    else cout << "Unable to open orders file" << endl;
    orderFile.close();
}


void Headquarter::loadProviderData(const string &providers_path) {
    ifstream providerFile(providers_path);

    string line;
    string name, user_name;
    unsigned int id, size, quantity;
    double price;

    if(providerFile.is_open()){
        while (getline(providerFile, line)){
            stringstream ss(line);
            ss >> id >> name >> user_name;
            Provider *provider = new Provider(name, user_name);
            addProvider(provider);
            while(getline(providerFile, line) && line != "_"){
                stringstream ss(line);
                ss >> id >> name >> price >> size >> quantity;
                Product * product = new Product(name, price, size);
                provider->addProduct(product, quantity);
            }
        }
    }

    else cout << "Unable to open providers file" << endl;
    providerFile.close();
}


void Headquarter::loadClientData(const string &clients_path) {
    ifstream clientFile(clients_path);

    string line;
    string name, user_name;
    unsigned int id;
    double pos_id;
    Date date;

    if(clientFile.is_open()){
        while (getline(clientFile, line)){
            stringstream ss(line);
            ss >> id >> name >> user_name >> date >> pos_id;
            Position position = getPositionById(pos_id);
            Client *client = new Client(name, user_name, date, &position);
            addClient(client);
        }
    }

    else cout << "Unable to open clients file" << endl;
    clientFile.close();
}


