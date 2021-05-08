#include "Headquarter.h"

using namespace std;

Headquarter::Headquarter(std::string adminPassword) : admin_password(adminPassword) {
}

//##################### GETTERS #########################################

Graph<Position> Headquarter::getGraph() const {
    return graph;
}

string Headquarter::getAdminPassword() const {
    return admin_password;
}


//##################### Add methods #####################################

void Headquarter::addClient(Client* client) {
    clients.push_back(client);
}

void Headquarter::addClient(std::string name, std::string userName, double id) {
    Position position =getPositionById(id);
    if(position == Position(-1, -1, -1)){
        std::cout << "You aren't in our map\n";
        return;
    }

    if(isClientRegistered(userName)){
        std::cout << "You are already registered!\n";
        return;
    }

    Client* client = new Client(name, userName, &position);

    addClient(client);
}

void Headquarter::addProvider(Provider *provider) {
    providers.push_back(provider);
}

void Headquarter::addTruck(Truck *truck) {
    trucks.push_back(truck);
}

void Headquarter::addOrder(Order *order) {
    orders.push_back(order);
}


//##################### Load data methods ###############################

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

                cout << line << '\n';
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

                cout << line << '\n';
            }
        }
        nodesFile.close();
    }
    else cout << "Unable to open edges file";
}

void Headquarter::loadData(const string &clients_path, const string &providers_path, const string &trucks_path) {
    //clients
    ifstream clientFile(clients_path);

    Client *client;

    if(clientFile.is_open()){
        while(!clientFile.eof()){
            clientFile >> *client;
            addClient(client);
        }
    }
    else cout << "Unable to open clients file" << endl;
    clientFile.close();
/*
    //providers
    ifstream providerFile(providers_path);

    Provider* provider;

    if(providerFile.is_open()){
        while(!providerFile.eof()){
            providerFile >> *provider;
            addProvider(provider);
        }
    }
    else cout << "Unable to open providers file" << endl;
    providerFile.close();

    //trucks
    ifstream truckFile(trucks_path);

    Truck* truck;

    if(truckFile.is_open()){
        while(!truckFile.eof()){
            truckFile >> *truck;
            addTruck(truck);
        }
    }
    else cout << "Unable to open trucks file" << endl;
    truckFile.close();
    */
}

void Headquarter::loadProvider(const string &providers_path) {
    //providers
    ifstream providerFile(providers_path);

    Provider* provider = new Provider();

    int acc = 5;

    if(providerFile.is_open()){

        //while(!providerFile.eof()){
        while (providerFile >> *provider){
            addProvider(provider);
        }
    }

    else cout << "Unable to open providers file" << endl;
    providerFile.close();
}

//##################### Save data methods ###############################

void Headquarter::saveProvider(const string &providers_path) {

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

void Headquarter::saveData(const string &clients_path, const string &providers_path, const string &trucks_path) {
    //clients
    ofstream clientFile(clients_path);

    if(clientFile.is_open()){
        for(auto it = clients.begin(); it != clients.end(); it++) {
            clientFile << *(*it);
        }
    }
    else cout << "Unable to open clients file" << endl;
    clientFile.close();

    //providers
    /*ofstream providerFile(providers_path);

    if(providerFile.is_open()){
        for(auto it = providers.begin(); it != providers.end(); it++) {
            providerFile << (*it);
        }
    }
    else cout << "Unable to open providers file" << endl;
    providerFile.close();

    //trucks
    ofstream truckFile(trucks_path);

    if(truckFile.is_open()){
        for(auto it = trucks.begin(); it != trucks.end(); it++) {
            truckFile << (*it);
        }
    }
    else cout << "Unable to open trucks file" << endl;
    truckFile.close();*/
}

//##################### Show collections methods ########################

void Headquarter::showTrucks() {
    if(trucks.empty()){
        cout << "It does not exist any truck yet" << endl;
        return;
    }
    cout << "Id\tCapacity\tLoad\tState" << endl;
    for(auto it = trucks.begin(); it != trucks.end(); it++){
        cout << (*it)->getId() << DELIMITER << (*it)->getCapacity() << DELIMITER << (*it)->getLoad() << DELIMITER << (*it)->getState() << endl;
    }
}

void Headquarter::showProviders() {
    if(providers.empty()){
        cout << "It does not exist any provider yet" << endl;
        return;
    }
    cout << "Id\tName\tUserName\tNumberOfProducts" << endl;
    for(auto it = providers.begin(); it != providers.end(); it++){
        //cout << *(*it);
        cout << (*it)->getId() << "\t" << (*it)->getName() << "\t" << (*it)->getUserName() << "\t\t" << endl;

    }

}

//##################### Search methods ##################################

Position Headquarter::getPositionById(double id) {
    Vertex<Position> * position = graph.findVertex(Position(id, 0, 0));
    if(position == NULL)
        return Position(-1, -1, -1);
    return position->getInfo();
}

Provider* Headquarter::getProviderById(unsigned int id) {
    for(auto it = providers.begin(); it != providers.end(); it++){
        if((*it)->getId() == id) return (*it);
    }
    return nullptr;
}

Client* Headquarter::getClientById(unsigned int id) {
    for(auto it = clients.begin(); it != clients.end(); it++){
        if((*it)->getId() == id) return (*it);
    }
    return nullptr;
}

bool Headquarter::isClientRegistered(std::string userName) {
    for(auto i = clients.begin(); i != clients.end(); i++){
        if((*i)->getUserName() == userName){
            return true;
        }
    }
    return false;
}

