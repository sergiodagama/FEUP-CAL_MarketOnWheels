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
void Headquarter::loadData(const string &clients_path, const string &providers_path, const string &trucks_path) {
//TODO
}

/**
 * Saves all company data into the program
 *
 * @param clients_path path to the clients file
 * @param providers_path path to the providers file
 * @param trucks_path path to the trucks file
 */
void Headquarter::saveData(const string &clients_path, const string &providers_path, const string &trucks_path) {
    //clients
    ofstream clientFile(clients_path);

    if(clientFile.is_open()){
        for(auto it = clients.begin(); it != clients.end(); it++) {
            clientFile << (*it);
        }
    }
    else cout << "Unable to open clients file" << endl;
    clientFile.close();

    //providers
    ofstream providerFile(providers_path);

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
    truckFile.close();
}
