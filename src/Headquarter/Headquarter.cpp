//
// Created by eunic on 24/04/2021.
//

#include <fstream>
#include <sstream>
#include <Utils.h>
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
 * Imports map into graph from file
 * @param nodes_path the path to the file where graph nodes are stored
 * @param edges_path the path to the file where graph edges are stored
 */
void Headquarter::loadMap(std::string nodes_path, std::string edges_path) {
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

Graph<Position> Headquarter::getGraph() const {
    return graph;
}

Position Headquarter::getPositionById(double id) {
    return graph.findVertex(Position(id, 0, 0))->getInfo();
}

/*id estadoTruck capacidade load
END TRUCK*/

void Headquarter::loadTrucks(std::string truck_path) {
    ifstream trucksFile(truck_path);

    string line;
    unsigned int id;
    int capacity, load;
    string state;

    //reading nodes file
    if (trucksFile.is_open()) {
        while(getline(trucksFile,line)){
            //splitting each line into it's corresponding values
            stringstream ss(line);
            ss  >> id >> state >> capacity >> load;

            state_t newState;

            if(state == "assign") newState = assigned;
            else if(state == "delivering") newState = delivering;
            else if(state == "completed") newState = completed;

            Truck* newTruck = new Truck(id, newState, capacity, load);
            trucks.push_back(newTruck);
        }
        trucksFile.close();
    }
    else cout << "Unable to open trucks file";


}

void Headquarter::showTrucks() {

    for(int i = 0; i < trucks.size(); i++)
    {
        cout << "ID: " << trucks[i]->getId() << " state: " <<  trucks[i]->returnStateString(trucks[i]->getState()) << " capacity: " << trucks[i]->getCapacity() << " load: "<< trucks[i]->getLoad() << endl;
    }

}
