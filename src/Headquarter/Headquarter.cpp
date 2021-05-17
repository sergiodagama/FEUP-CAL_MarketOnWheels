#include <Headquarter.h>

#include <algorithm>
#include <chrono>
#include <map>

using namespace std;

Headquarter::Headquarter(string admin_pass) {
    this->admin_password = admin_pass;
}

bool Headquarter::emptyAddress(double idVertex){
    for(auto it = clients.begin(); it != clients.end(); it++){
        if((double) (*it)->getAddress() == idVertex){
            return false;
        }
    }
    for(auto it = providers.begin(); it != providers.end(); it++){
        if((double) (*it)->getAddress() == idVertex){
            return false;
        }
    }
    return true;
}

bool Headquarter::clientSearcher(std::string userName){
    for(vector<Client*>::iterator it = clients.begin(); it != clients.end(); it++){
        if((*it)->getUserName() == userName){
            return true;
        }
    }
    return false;
}

bool Headquarter::positionSearcher(double idVertex) {
    Vertex<Position>* pos =  graph.findVertex(Position(idVertex, 0, 0));
    if(pos==NULL) return false;
    return true;
}

bool Headquarter::providerSearcher(std::string userName) {
    for(vector<Provider*>::iterator it = providers.begin(); it != providers.end(); it++){
        if((*it)->getUserName() == userName){
            return true;
        }
    }
    return false;
}

Product* Headquarter::productSearcher(std::string name){
    for(vector<Product*>::iterator it = products.begin(); it != products.end(); it++){
        if((*it)->getName() == name){
            return *it;
        }
    }
    return NULL;
}

bool Headquarter::acceptOrder(Order* order){
    ProductsWrapper total;
    for(auto it = products.begin(); it != products.end(); it ++){
        total.addProduct(*it, 0);
    }
    for(auto it = providers.begin(); it != providers.end(); it++){
        map<Product*, unsigned int> products = (*it)->getProducts();
        for (auto it2 = products.begin();  it2 != products.end(); it2++){
            try{
                total.addQuantityOfProduct((*it2).first, (*it2).second);
            }
            catch (ProductNotFound) {
                continue;
            }

        }
    }
    for(auto it = orders.begin(); it != orders.end(); it ++){
        map<Product*, unsigned int> products = (*it)->getProducts();
        for (auto it2 = products.begin();  it2 != products.end(); it2++){
            try{
                total.addQuantityOfProduct((*it2).first, -1*(*it2).second);
            }
            catch (ProductNotFound) {
                continue;
            }
        }
    }
    map<Product*, unsigned int> ord = order->getProducts();
    for(auto it = ord.begin(); it != ord.end(); it ++){
        if(total.getQuantityOfProduct((*it).first) < (*it).second) return false;
    }
    return true;
}

Graph<Position> Headquarter::getGraph() const {
    return graph;
}

string Headquarter::getAdminPassword() const {
    return admin_password;
}

Position Headquarter::getPositionById(double id) {
    return graph.findVertex(Position(id, 0, 0))->getInfo();
}

Product *Headquarter::getProductById(unsigned int id) {
    for (auto it = products.begin(); it != products.end(); it++) {
        if ((*it)->getId() == id) return (*it);
    }
    throw ProductNotFound();
}

Provider *Headquarter::getProviderById(unsigned int id) {
    for (auto it = providers.begin(); it != providers.end(); it++) {
        if ((*it)->getId() == id) return (*it);
    }
    return nullptr;
}

Client *Headquarter::getClientById(unsigned int id) {
    for (auto it = clients.begin(); it != clients.end(); it++) {
        if ((*it)->getId() == id) return (*it);
    }
    return nullptr;
}

Order *Headquarter::getOrderById(unsigned int id) {
    for (auto it = orders.begin(); it != orders.end(); it++) {
        if ((*it)->getId() == id) return (*it);
    }
    return nullptr;
}

unsigned int Headquarter::getNProducts() const {
    return products.size();
}

unsigned int Headquarter::getNClients() const {
    return clients.size();
}

unsigned int Headquarter::getNOrders() const {
    return orders.size();
}

unsigned int Headquarter::getNTrucks() const {
    return trucks.size();
}

void Headquarter::addClient(Client *client) {
    clients.push_back(client);
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

void Headquarter::addProduct(Product *product) {
    products.push_back(product);
}

void Headquarter::loadMap(const std::string &nodes_path, const std::string &edges_path) {
    ifstream nodesFile(nodes_path);
    ifstream edgesFile(edges_path);

    string line;
    double id, id2;
    long double latitude, longitude;
    bool firstLine = true;

    //reading nodes file
    if (nodesFile.is_open()) {
        while (getline(nodesFile, line)) {
            if (firstLine) {
                firstLine = false;
                continue;
            } else {
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
                if (!graph.addVertex(Position(id, latitude, longitude))) {
                    cout << "ERROR" << endl;
                }
            }
        }
        nodesFile.close();
    } else cout << "Unable to open nodes file";

    firstLine = true;

    //reading edges file
    if (edgesFile.is_open()) {
        while (getline(edgesFile, line)) {
            if (firstLine) {
                firstLine = false;
                continue;
            } else {
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
                if (!graph.addEdge(position, position2, distanceBetweenTwoPos(position, position2))) {
                    cout << "ERROR" << endl;
                };
            }
        }
        nodesFile.close();
    } else cout << "Unable to open edges file";
}

void Headquarter::loadAllData(const string &clients_path, const string &providers_path, const string &trucks_path,
                              const string &orders_path, const std::string &products_path) {
    loadProductData(products_path);
    loadClientData(clients_path);
    loadProviderData(providers_path);
    loadOrderData(orders_path);
    loadTruckData(trucks_path);
}

void Headquarter::saveAllData(const string &clients_path, const string &providers_path, const string &trucks_path,
                              const string &orders_path, const std::string &products_path) {
    saveProductData(products_path);
    saveClientData(clients_path);
    saveProviderData(providers_path);
    saveTruckData(trucks_path);
    saveOrderData(orders_path);
}

void Headquarter::saveProviderData(const string &providers_path) {
    ofstream providerFile(providers_path);

    if (providerFile.is_open()) {
        for (auto it = providers.begin(); it != providers.end(); it++) {
            providerFile << *(*it);
        }
    } else cout << "Unable to open providers file" << endl;
    providerFile.close();

}

void Headquarter::saveTruckData(const string &trucks_path) {
    ofstream truckFile(trucks_path);

    if (truckFile.is_open()) {
        for (auto it = trucks.begin(); it != trucks.end(); it++) {
            truckFile << *(*it);
        }
    } else cout << "Unable to open trucks file" << endl;
    truckFile.close();
}

void Headquarter::saveClientData(const string &clients_path) {
    ofstream clientFile(clients_path);

    if (clientFile.is_open()) {
        for (auto it = clients.begin(); it != clients.end(); it++) {
            clientFile << *(*it);
        }
    } else cout << "Unable to open clients file" << endl;
    clientFile.close();
}

void Headquarter::saveOrderData(const string &orders_path) {
    ofstream orderFile(orders_path);

    if (orderFile.is_open()) {
        for (auto it = orders.begin(); it != orders.end(); it++) {
            orderFile << *(*it);
        }
    } else cout << "Unable to open orders file" << endl;
    orderFile.close();
}

void Headquarter::loadProviderData(const string &providers_path) {
    ifstream providerFile(providers_path);

    string line;
    string name, user_name;
    unsigned int id, prod_id, size, quantity, pos_id;
    double price;

    if (providerFile.is_open()) {
        while (getline(providerFile, line)) {
            stringstream ss(line);
            ss >> id >> name >> user_name >> pos_id;
            Provider *provider = new Provider(name, user_name, pos_id);
            addProvider(provider);
            while (getline(providerFile, line) && line != "_") {
                stringstream ss(line);
                ss >> prod_id >> quantity;
                provider->addProduct(getProductById(prod_id), quantity);
            }
        }
    } else cout << "Unable to open providers file" << endl;
    providerFile.close();
}

void Headquarter::loadClientData(const string &clients_path) {
    ifstream clientFile(clients_path);

    string line;
    string name, user_name;
    unsigned int id;
    double pos_id;
    Date date;

    if (clientFile.is_open()) {
        while (getline(clientFile, line)) {
            stringstream ss(line);
            ss >> id >> name >> user_name >> date >> pos_id;
            Client *client = new Client(name, user_name, date, pos_id);
            addClient(client);
        }
    } else cout << "Unable to open clients file" << endl;
    clientFile.close();
}

void Headquarter::loadOrderData(const string &orders_path) {
    ifstream orderFile(orders_path);

    string line;
    unsigned int id, client_id, prod_id, quantity;

    if (orderFile.is_open()) {
        while (getline(orderFile, line)) {
            stringstream ss(line);
            ss >> id >> client_id;
            Order *order = new Order(client_id);
            addOrder(order);
            while (getline(orderFile, line) && line != "_") {
                stringstream ss(line);
                ss >> prod_id >> quantity;
                order->addProduct(getProductById(prod_id), quantity);
            }
        }
    } else cout << "Unable to open orders file" << endl;
    orderFile.close();
}

void Headquarter::loadTruckData(const string &trucks_path) {
    ifstream truckFile(trucks_path);

    string line;
    unsigned int cap, truck_id, order_id, load, state;
    double price;

    if (truckFile.is_open()) {
        while (getline(truckFile, line)) {
            stringstream ss(line);
            ss >> truck_id >> cap >> load >> state;
            Truck *truck = new Truck(cap);
            //truck->setState(truck->returnStateString(state));
            addTruck(truck);
            while (getline(truckFile, line) && line != "_") {
                stringstream ss(line);
                ss >> order_id;
                truck->addOrder(getOrderById(order_id));
            }
        }
    } else cout << "Unable to open trucks file" << endl;
    truckFile.close();
}

void Headquarter::saveProductData(const string &products_path) {
    ofstream productFile(products_path);

    if (productFile.is_open()) {
        for (auto it = products.begin(); it != products.end(); it++) {
            productFile << *(*it);
        }
    } else cout << "Unable to open products file" << endl;
    productFile.close();
}

void Headquarter::loadProductData(const string &products_path) {
    ifstream productFile(products_path);

    string line;
    string name;
    unsigned int id, prod_id, quantity, size;
    double price;

    if (productFile.is_open()) {
        while (getline(productFile, line) && line != "_") {
            stringstream ss(line);
            ss >> prod_id >> name >> price >> size;
            Product *product = new Product(name, price, size);
            addProduct(product);
        }
    } else cout << "Unable to open products file" << endl;
    productFile.close();
}

void Headquarter::showProducts() {
    cout << "Products" << endl;
    for (auto it = products.begin(); it != products.end(); it++) {
        cout << *(*it);
    }
}

void Headquarter::showTrucks() {
    if (trucks.empty()) {
        cout << "It does not exist any truck yet" << endl;
        return;
    }
    cout << "Id\tCapacity\tLoad\tState" << endl;
    for (auto it = trucks.begin(); it != trucks.end(); it++) {
        cout << (*it)->getId() << "\t" << (*it)->getCapacity() << "\t" << (*it)->getLoad() << "\t" << (*it)->getState()
             << endl;
    }
}

void Headquarter::showOrders() {
    if (orders.empty()) {
        cout << "It does not exist any order yet" << endl;
        return;
    }
    cout << "Id\t" << endl;
    for (auto it = orders.begin(); it != orders.end(); it++) {
        cout << (*it)->getId() << endl;
    }
}

void Headquarter::showClients() { //TODO investigate format
    if (clients.empty()) {
        cout << "It does not exist any client yet" << endl;
        return;
    }
    cout << "Id\tName\tUsername\tDate\t\tAdressId" << endl;
    for (auto it = clients.begin(); it != clients.end(); it++) {
        cout << (*it)->getId() << "\t" << (*it)->getName() << "\t" << (*it)->getUserName() << "\t\t" << (*it)->getDate()
             << "\t" << (*it)->getAddress() << endl;
    }
}

void Headquarter::showProviders() {
    if (providers.empty()) {
        cout << "It does not exist any provider yet" << endl;
        return;
    }
    cout << "Id\tName\t\tUserName\tnProducts\tAddressId" << endl;
    for (auto it = providers.begin(); it != providers.end(); it++) {
        cout << (*it)->getId() << "\t" << (*it)->getName() << "\t" << (*it)->getUserName() << "\t\t"
             << (*it)->getNumOfDifProducts() << "\t\t\t" << (*it)->getAddress() << endl;
    }
}

void Headquarter::distributeOrdersToTrucks() {
    //sorting trucks by their capacity (higher capacity first)
    sort(trucks.begin(), trucks.end(), [](Truck const *const truck1, Truck const *const truck2) {
        return truck1->getCapacity() > truck2->getCapacity();
    });

    //going through all the trucks
    for (int t = 0; t < trucks.size(); t++) {

        vector<Order*> ords(orders);

        //sorting orders by their price (higher prices first)
        sort(orders.begin(), orders.end(), [](Order const *const order1, Order const *const order2) {
            return order1->getPrice() > order2->getPrice();
        });

        cout << "CAPACITY: " << trucks[t]->getCapacity() << "\tID: " << trucks[t]->getId() << endl;

        cout << "------------ORDERS------------" << endl;
        for (auto it = orders.begin(); it != orders.end(); it++) {
            cout << "ID: " << (*it)->getId() << "\t";
            cout << "SIZE: " << (*it)->getSize() << "\t";
            cout << "PRICE: " << (*it)->getPrice() << endl;
        }
        cout << "------------------------------" << endl;

        bool notMoreSpace = false;

        for(auto it = ords.begin(); it != ords.end(); it++) {
            if(notMoreSpace) break;
            try {
                trucks[t]->addOrder(getOrderById((*it)->getId()));
            }
            catch (NotAvailableSpace e){
                notMoreSpace = true;
            }
            for(auto in = ++it; in != ords.end(); in++){
                if(notMoreSpace) break;
                if((*in)->getClientId() == (*it)->getClientId()){
                    try {
                        trucks[t]->addOrder(getOrderById((*in)->getId()));
                    }
                    catch (NotAvailableSpace e){
                        notMoreSpace = true;
                    }
                    ords.erase(in);
                }
            }
            ords.erase(it);
        }
    }
}


std::vector<Provider *> Headquarter::getProvidersThatSatisfy(std::queue<Order *> orders) {
    std::vector<Provider *> providersNeeded ;
    ProductsWrapper total;


    while(!orders.empty())
    {
        Order * orderTop = orders.front();
        std::map<Product *, unsigned int> products = orderTop->getProducts();

        for(auto it = products.begin(); it != products.end(); it ++){
            try{
                total.addQuantityOfProduct((*it).first, (*it).second);
            }
            catch (ProductNotFound) {
                total.addProduct((*it).first, (*it).second);
            }
        }

        orders.pop();
    }

    std::map<Product *, unsigned int> totalProducts = total.getProducts();

    for(auto itProvider = providers.begin(); itProvider != providers.end(); itProvider++) {
        cout << (*itProvider)->getName() << endl;
        bool firstProduct = false;

        for (auto itProduct = totalProducts.begin(); itProduct != totalProducts.end(); itProduct++) {
            cout << *(*itProduct).first << (*itProduct).second << endl;
            int stockProduct = 0;
            try {
                stockProduct = (*itProvider)->getQuantityOfProduct((*itProduct).first);
            }
            catch (ProductNotFound e) {
            }

            if (stockProduct >= (*itProduct).second) {
                if (!firstProduct) {
                    providersNeeded.push_back(*itProvider);
                    firstProduct = true;
                }
                (*itProvider)->removeQuantityOfProduct((*itProduct).first, (*itProduct).second);
            }
        }
    }

    return providersNeeded;
}

std::map<unsigned int, std::vector<int>> Headquarter::calculateTrucksToProvidersPath() {


    for(auto it = trucks.begin(); it != trucks.end(); it++)
    {
        Graph<Position> providersGraph;
        std::vector<Provider *>  providersNeeded = getProvidersThatSatisfy((*it)->getOrders());
        //Caixeiro vaijante talvez?
        /*providersGraph.dijkstraShortestPath(*address);
        providersGraph.getPath(*address, getPositionById(providersNeeded[0]->getAddress()));*/

        Vertex<Position> * first = graph.findVertex(*address);
        graph.dijkstraShortestPath(*address);
        vector<Position> path = graph.getPath(*address, getPositionById(providers[0]->getAddress()));
        for(int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " " << endl;
        }

        /*for(auto vertexIt = graph.getVertexSet().begin() ; vertexIt != vertexSet.end(); vertexIt++)
        {
            if(*vertexIt != first)
                dijkstraShortestPath(origin, vertexIt);
        }*/
    }
    return std::map<unsigned int, std::vector<int>>();
}
