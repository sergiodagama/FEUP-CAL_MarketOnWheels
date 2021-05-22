#include <Headquarter.h>


using namespace std;

Headquarter::Headquarter(string admin_pass) {
    this->admin_password = admin_pass;
}

bool Headquarter::emptyAddress(double idVertex) {
    for (auto it = clients.begin(); it != clients.end(); it++) {
        if ((double) (*it)->getAddress() == idVertex) {
            return false;
        }
    }
    for (auto it = providers.begin(); it != providers.end(); it++) {
        if ((double) (*it)->getAddress() == idVertex) {
            return false;
        }
    }
    return true;
}

bool Headquarter::clientSearcher(std::string userName) {
    for (vector<Client *>::iterator it = clients.begin(); it != clients.end(); it++) {
        if ((*it)->getUserName() == userName) {
            return true;
        }
    }
    return false;
}

bool Headquarter::positionSearcher(double idVertex) {
    Vertex<Position> *pos = graph.findVertex(Position(idVertex, 0, 0));
    if (pos == NULL) return false;
    return true;
}

bool Headquarter::providerSearcher(std::string userName) {
    for (vector<Provider *>::iterator it = providers.begin(); it != providers.end(); it++) {
        if ((*it)->getUserName() == userName) {
            return true;
        }
    }
    return false;
}

Product *Headquarter::productSearcher(std::string name) {
    for (vector<Product *>::iterator it = products.begin(); it != products.end(); it++) {
        if ((*it)->getName() == name) {
            return *it;
        }
    }
    return NULL;
}

bool Headquarter::acceptOrder(Order *order) {
    ProductsWrapper total;

    for (auto it = products.begin(); it != products.end(); it++) {
        total.addProduct(*it, 0);
    }

    for (auto it = providers.begin(); it != providers.end(); it++) {
        map<Product *, unsigned int> providersProducts = (*it)->getProducts();
        for (auto it2 = providersProducts.begin(); it2 != providersProducts.end(); it2++) {
            try {
                total.addQuantityOfProduct((*it2).first, (*it2).second);
            }
            catch (ProductNotFound) {
                continue;
            }
        }
    }

    for (auto it = orders.begin(); it != orders.end(); it++) {
        map<Product *, unsigned int> ordersProducts = (*it)->getProducts();
        for (auto it2 = ordersProducts.begin(); it2 != ordersProducts.end(); it2++) {
            try {
                total.addQuantityOfProduct((*it2).first, -1 * (*it2).second);
            }
            catch (ProductNotFound) {
                continue;
            }
        }
    }

    map<Product *, unsigned int> ord = order->getProducts();
    for (auto it = ord.begin(); it != ord.end(); it++) {
        if (total.getQuantityOfProduct((*it).first) < (*it).second)
        {
            return false;
        }
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
    Vertex<Position> *v = graph.findVertex(Position(id, 0, 0));
    if (v != NULL) return v->getInfo();
    else return Position(0, 0, 0);
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

Truck* Headquarter::getTruckById(unsigned int id){
    for (auto it = trucks.begin(); it != trucks.end(); it++) {
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

std::vector<Truck *> Headquarter::getTrucks() const {
    return trucks;
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

void Headquarter::removeOrderById(unsigned int id) {
    for (auto it = orders.begin(); it != orders.end(); it++) {
        if ((*it)->getId() == id) {
            orders.erase(it);
            break;
        }
    }
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

    //checking connectivity after load
    if(graph.connectivity().size() != 1){
        cout << "THE MAP IMPORTED IS NOT STRONGLY CONNECTED" << std::endl;
        throw NotStronglyConnected();
    }
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
    cout << "----------------Products----------------" << endl;
    cout  << setw(SPACE) << "Id" << setw(SPACE) << "Name" << setw(SPACE)<< "Price"<< endl;
    for (auto it = products.begin(); it != products.end(); it++) {
        cout  << setw(SPACE) << (*it)->getId() << setw(SPACE) << (*it)->getName() << setw(SPACE) << (*it)->getPrice() << endl;
    }
}

void Headquarter::showTrucks() {
    cout << "----------------------Trucks----------------------" << endl;
    if (trucks.empty()) {
        cout << "It does not exist any truck yet" << endl;
        return;
    }
    cout  << setw(ID) << "Id" << setw(SPACE) << "Capacity" << setw(SPACE)<< "Load"<< setw(SPACE) << "Delivering" << endl;
    for (auto it = trucks.begin(); it != trucks.end(); it++) {
        cout << setw(ID) << (*it)->getId() << setw(SPACE) << (*it)->getCapacity() << setw(SPACE) << (*it)->getLoad() << setw(SPACE);
         (*it)->isDelivering() ? cout << "Yes" : cout << "No" << endl;
    }
}

void Headquarter::showOrders() {
    cout << "----------------Orders----------------" << endl;
    if (orders.empty()) {
        cout << "It does not exist any order yet" << endl;
        return;
    }

    cout  << setw(ID) << "ID" << setw(SPACE) << "ClientId" << setw(SPACE) << "Delivering" << setw(SPACE) << "Products" <<endl;
    for (auto it = orders.begin(); it != orders.end(); it++) {
        cout << setw(ID) << (*it)->getId();

        cout << setw(SPACE) << (*it)->getClientId() << setw(SPACE);
        (*it)->getFlag() ? cout << "Yes" : cout << "No";

        auto ordersProducts = (*it)->getProducts();
        for(auto it2 = ordersProducts.begin(); it2 != ordersProducts.end(); it2++)
        {
            cout << setw(SPACE ) << (*(*it2).first).getName() << setw(SPACE) << (*it2).second << " ";
        }
        cout << endl;
    }
}

void Headquarter::showClients() {
    cout << "---------------------Clients---------------------" << endl;
    if (clients.empty()) {
        cout << "It does not exist any client yet" << endl;
        return;
    }
    cout << setw(ID)<< "Id" << setw(SPACE) << "Name" << setw(SPACE) << "UserName" << setw(SPACE) << "AddressId" << endl;
    for (auto it = clients.begin(); it != clients.end(); it++) {
        cout <<  setw(ID) << (*it)->getId() <<  setw(SPACE) << (*it)->getName() <<  setw(SPACE) << (*it)->getUserName()
             <<  setw(SPACE) << (*it)->getAddress()  << endl;
    }
}

void Headquarter::showProviders() {
    cout << "---------------------Providers----------------------" << endl;
    if (providers.empty()) {
        cout << "It does not exist any provider yet" << endl;
        return;
    }
    cout << setw(ID)<< "Id" << setw(SPACE) << "Name" << setw(SPACE) << "UserName" << setw(SPACE) << "nProducts"  << setw(SPACE) << "AddressId" << endl;
    for (auto it = providers.begin(); it != providers.end(); it++) {
        cout << setw(ID)<< (*it)->getId() << setw(SPACE) << (*it)->getName() <<setw(SPACE)<< (*it)->getUserName() << setw(SPACE)
             << (*it)->getNumOfDifProducts() << setw(SPACE) << (*it)->getAddress() << endl;
    }
}

void Headquarter::showInventory(Provider * provider)
{
    cout << "---------------------Inventory----------------------" << endl;
    cout <<  setw(SPACE) << "Name" << setw(SPACE) << "Quantity" << endl;

    for(auto it = providers.begin(); it != providers.end(); it++)
    {
        auto providersProvider = (*it)->getProducts();
        for(auto it2 = providersProvider.begin(); it2 != providersProvider.end(); it2++)
        {
            cout << setw(SPACE ) << (*(*it2).first).getName() << setw(SPACE) << (*it2).second << " " << endl;
        }
    }
}

void Headquarter::distributeOrdersToTrucks() {
    //sorting trucks by their capacity (higher capacity first)
    sort(trucks.begin(), trucks.end(), [](Truck const *const truck1, Truck const *const truck2) {
        return truck1->getCapacity() > truck2->getCapacity();
    });

    //going through all the trucks
    for (int t = 0; t < trucks.size(); t++) {

        //sorting orders by their price (prices)
        sort(orders.begin(), orders.end(), [](Order const *const order1, Order const *const order2) {
            return order1->getPrice() > order2->getPrice();
        });

        vector<Order *> ords(orders);

        unsigned int current_client_id, cur_ord_id;

        vector<Order *> ordsSorted;

        //grouping orders by id, maintaining the order by price
        while (ords.size() != 0) {
            ordsSorted.push_back(ords.at(0));
            current_client_id = ords.at(0)->getClientId();
            cur_ord_id = ords.at(0)->getId();
            ords.erase(ords.begin());

            auto it = ords.begin();
            while (it != ords.end()) {
                if (current_client_id == (*it)->getClientId() && cur_ord_id != (*it)->getId()) {
                    ordsSorted.push_back((*it));
                    ords.erase(it);
                } else it++;
            }
        }

        //checking if truck is available
        if (!trucks[t]->isDelivering()) {
            //filling trucks [just needed to follow the order of the sorted vector]
            for (auto it = ordsSorted.begin(); it != ordsSorted.end(); it++) {
                if (getOrderById((*it)->getId())->getFlag()) continue; //if truck is already being delivered
                try {
                    trucks[t]->addOrder(getOrderById((*it)->getId()));
                    getOrderById((*it)->getId())->setFlag();
                    if (!trucks[t]->isDelivering()) trucks[t]->setDelivering(true);
                }
                catch (NotAvailableSpace e) {
                    continue;  //when there is no available space goes to next order, until finished
                }
                //here it's just an optimization, not actually necessary,
                //but prevents going through all orders, when truck it's already full
                if (trucks[t]->getCapacity() == trucks[t]->getLoad()) break;
            }
        }
    }
}

std::vector<Provider *> Headquarter::getProvidersThatSatisfy(std::queue<Order *> orders) {
    auto iter = providers.begin();

    graph.dijkstraShortestPath(getPositionById(position_id));

    //calculating distances from headquarter to providers
    while (iter != providers.end()) {
        vector<Position> path = graph.getPath(getPositionById(position_id), getPositionById((*iter)->getAddress()));
        long double distance = graph.distanceFromPath(path);
        (*iter)->setDist(distance);
        iter++;
    }

    //sorting the provider by their distance to headquarters
    sort(providers.begin(), providers.end(), [](Provider const *const provider1, Provider const *const provider2) {
        return provider1->getDist() < provider2->getDist();
    });

    std::vector<Provider *> providersNeeded;
    ProductsWrapper total;

    //building an auxiliary buffer that holds all orders products and respective quantities
    while (!orders.empty()) {
        Order *orderTop = orders.front();
        std::map<Product *, unsigned int> products = orderTop->getProducts();

        for (auto it = products.begin(); it != products.end(); it++) {
            try {
                total.addQuantityOfProduct((*it).first, (*it).second);
            } catch (ProductNotFound) {
                total.addProduct((*it).first, (*it).second);
            }
        }
        orders.pop();
    }
    std::map<Product *, unsigned int> totalProducts = total.getProducts();

    //getting the actual providers needed mantaining the optimization of getting the ones closer first
    for (auto itProvider = providers.begin(); itProvider != providers.end(); itProvider++) {
        bool firstProduct = false;

        for (auto itProduct = totalProducts.begin(); itProduct != totalProducts.end(); itProduct++) {
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

void Headquarter::calculateTrucksPathFromHeadToProviders() {

    //going through each truck
    for (auto it = trucks.begin(); it != trucks.end(); it++) {

        //getting first position (headquarter position)
        vector<Provider *> providersNeeded = getProvidersThatSatisfy((*it)->getOrders());
        Vertex<Position> *first = graph.findVertex(getPositionById(position_id));
        cout << "---------------Providers needed for truck " << (*it)->getId() << " ---------------" << endl;

        for (int i = 0; i < providersNeeded.size(); i++) {

            cout << "first: " << first->getInfo() << endl;

            //getting last position
            Vertex<Position> *end = graph.findVertex(getPositionById(providersNeeded.at(i)->getAddress()));
            cout << "end: " << end->getInfo() << endl;
            graph.dijkstraShortestPath(first->getInfo());

            vector<Position> path = graph.getPath(first->getInfo(), end->getInfo());

            first = end;

            for (auto itr = path.begin(); itr != path.end() - 1; itr++) {
                (*it)->addPositionToPath((*itr));
            }
            (*it)->addPositionToPath(first->getInfo());

        }
    }
}


std::vector<Client *> Headquarter::getClientsFromOrders(queue<Order *> orders) {
    set<unsigned int> cliens;
    vector<Client *> unique;

    while (!orders.empty()) {
        Order *ord = orders.front();
        cliens.insert(ord->getClientId());
        orders.pop();
    }

    for (auto elem : cliens) {
        unique.push_back(getClientById(elem));
    }

    //Getting pseudo minimal path that goes through all the clients
    vector<Client *> res;
    res.push_back(unique.at(0));

    if (unique.size() == 1) return res;

    for (int k = 0; k < unique.size(); k++) {
        graph.dijkstraShortestPath(getPositionById(unique[k]->getAddress()));

        long double smaller = INF;
        unsigned int smaller_offset = 1;

        for (int c = k + 1; c < unique.size(); c++) {
            vector<Position> path = graph.getPath(getPositionById(unique[k]->getAddress()),
                                                  getPositionById(unique[c]->getAddress()));

            long double distance = graph.distanceFromPath(path);

            if (distance < smaller) {
                smaller = distance;
                smaller_offset = c;
            }
        }
        res.push_back(unique.at(smaller_offset));
        unique.erase(unique.begin() + smaller_offset);
    }
    return res;
}

void Headquarter::calculateTrucksPathFromProvidersToClients() {
    //going through all trucks
    for (auto it = trucks.begin(); it != trucks.end(); it++) {
        //getting first position (headquarter position)
        queue<Order *> truckOrders = (*it)->getOrders();

        //using the getClientFromOrders function to obtain the optimized clients ordered vector
        vector<Client *> truckClients = getClientsFromOrders(truckOrders);

        //getting first position from path
        Vertex<Position> *first = graph.findVertex((*it)->getPath().back());

        cout << "---------------Clients of truck orders" << (*it)->getId() << " ---------------" << endl;
        for (auto u = truckClients.begin(); u != truckClients.end(); u++) {
            cout << *(*u) << endl;
        }


        for (int i = 0; i < truckClients.size(); i++) {

            cout << "first: " << first->getInfo() << endl;

            //getting last position
            Vertex<Position> *end = graph.findVertex(getPositionById(truckClients.at(i)->getAddress()));

            cout << "end: " << end->getInfo() << endl;

            graph.dijkstraShortestPath(first->getInfo());

            vector<Position> path = graph.getPath(first->getInfo(), end->getInfo());

            first = end;

            if (path.size() > 1) {
                for (auto itr = path.begin(); itr != path.end() - 1; itr++) {
                    (*it)->addPositionToPath((*itr));
                }
            }
            (*it)->addPositionToPath(first->getInfo());

        }

        graph.dijkstraShortestPath(first->getInfo());

        vector<Position> pathToHead = graph.getPath(first->getInfo(), getPositionById(position_id));
        cout << "---------------FINAL PATH TRUCK " << (*it)->getId() << " ---------------" << endl;
        for (auto itr = pathToHead.begin(); itr != pathToHead.end() - 1; itr++) {
            cout << "Position: " << (*itr).getId() << endl;
            (*it)->addPositionToPath((*itr));
        }
        cout << "-------------END TRUCK PATH-------------" << endl;
    }
}

void Headquarter::calculateTrucksPaths() {
    //dividing orders into all trucks
    distributeOrdersToTrucks();

    //calculating trucks path from headquarter to providers
    calculateTrucksPathFromHeadToProviders();

    //calculating trucks path from providers to clients and finish in headquarter
    calculateTrucksPathFromProvidersToClients();
}

void Headquarter::deliver() {
    //going through all trucks
    for(auto it : trucks){
        //clears all trucks paths
        (*it).clearPath();

        //setting trucks state to available again
        (*it).setDelivering(false);
    }

    //clear all orders that were delivered
    for(auto itr = orders.begin(); itr != orders.end();){
        if((*itr)->getFlag()) orders.erase(itr);
        else itr++;
    }
}


