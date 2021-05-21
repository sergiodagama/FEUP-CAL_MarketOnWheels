/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include <algorithm>
#include "MutablePriorityQueue.h"

template<class T>
class Edge;

template<class T>
class Graph;

template<class T>
class Vertex;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

template<class T>
class Vertex {
    T info;                        // content of the vertex
    std::vector<Edge<T> > adj;        // outgoing edges

    double dist = 0;
    Vertex<T> *path = NULL;
    int queueIndex = 0;        // required by MutablePriorityQueue
    bool visited = false;        // auxiliary field
    bool processing = false;    // auxiliary field

    void addEdge(Vertex<T> *dest, double w);

public:
    Vertex(T in);

    T getInfo() const;

    double getDist() const;

    Vertex *getPath() const;

    bool operator<(Vertex<T> &vertex) const; // // required by MutablePriorityQueue
    friend class Graph<T>;
    friend class MutablePriorityQueue<Vertex<T>>;
};


template<class T>
Vertex<T>::Vertex(T in): info(in) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template<class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
    adj.push_back(Edge<T>(d, w));
}

template<class T>
bool Vertex<T>::operator<(Vertex<T> &vertex) const {
    return this->dist < vertex.dist;
}

template<class T>
T Vertex<T>::getInfo() const {
    return this->info;
}

template<class T>
double Vertex<T>::getDist() const {
    return this->dist;
}

template<class T>
Vertex<T> *Vertex<T>::getPath() const {
    return this->path;
}

/********************** Edge  ****************************/

template<class T>
class Edge {
    Vertex<T> *dest;      // destination vertex
    double weight;         // edge weight
public:
    Edge(Vertex<T> *d, double w);

    friend class Graph<T>;

    friend class Vertex<T>;
};

template<class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}


/*************************** Graph  **************************/

template<class T>
class Graph {
    std::vector<Vertex<T> *> vertexSet;    // vertex set
    std::vector<std::vector<double>> distMin;
    std::vector<std::vector<Vertex<T>*>> path;

public:
    Vertex<T> *findVertex(const T &in) const;

    bool addVertex(const T &in);

    bool addEdge(const T &sourc, const T &dest, double w);

    int getNumVertex() const;

    double getWeight(Vertex<T>* vertex1, Vertex<T>* vertex2);

    long double distanceFromPath(const std::vector<T> &path);

    std::vector<Vertex<T> *> getVertexSet() const;

    void floydWarshallShortestPath();
    std::vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;
    void dijkstraShortestPath(const T &s);
    std::vector<T> getPath(const T &origin, const T &dest) const;
    void travellingSalesmanProblem(const T &origin);

};

template<class T>
int Graph<T>::getNumVertex() const {
    return vertexSet.size();
}

template<class T>
std::vector<Vertex<T> *> Graph<T>::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template<class T>
Vertex<T> *Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template<class T>
bool Graph<T>::addVertex(const T &in) {
    if (findVertex(in) != NULL)
        return false;
    vertexSet.push_back(new Vertex<T>(in));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template<class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2, w);
    return true;
}

/**************** All Pairs Shortest Path  ***************/

template<class T>
double Graph<T>::getWeight(Vertex<T>* vertex1, Vertex<T>* vertex2)
{

    std::vector<Edge<T>> adj1 = vertex1->adj;

    for(int i = 0; i < adj1.size(); i++)
    {
        if(adj1[i].dest->info == vertex2->info)
        {

            return adj1[i].weight;
        }

    }

    return INF;
}


template<class T>
void Graph<T>::floydWarshallShortestPath() {

    distMin.resize(vertexSet.size());
    for (int i = 0; i < vertexSet.size(); i++)
        distMin[i].resize(vertexSet.size());
    path.resize(vertexSet.size());
    for (int i = 0; i < vertexSet.size(); i++)
        path[i].resize(vertexSet.size());


    for (int i = 0; i < distMin.size(); i++) {

        for (int j = 0; j < distMin[i].size(); j++) {

            if (i == j) distMin[i][j];

            else
            {
                distMin[i][j] = getWeight(vertexSet[i], vertexSet[j]);
            }
        }
    }

    for (int k = 0; k < vertexSet.size(); k++) {
        std::cout << "inside floydWarshall K: " << k << std::endl;

        for (int i = 0; i < vertexSet.size(); i++){
            for (int j = 0; j < vertexSet.size(); j++)
            {
                if(distMin[i][j] > distMin[i][k] + distMin[k][j])
                {
                    distMin[i][j] = distMin[i][k] + distMin[k][j];
                    path[i][j] = vertexSet[k];

                }
            }
        }
    }
}

template<class T>
std::vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const{


    std::vector<T> inverted;
    std::vector<T> res;

    if(path[orig - 1][dest - 1] == NULL) return inverted;

    T currentDest = dest;
    T currentOrig = orig;


    while(currentDest != orig)
    {
        inverted.push_back(currentDest);
        if(path[currentOrig - 1][currentDest - 1] == NULL) break;
        currentDest = path[currentOrig - 1][currentDest - 1]->info;
    }

    inverted.push_back(orig);

    for(int i = inverted.size() - 1; i != -1; i--)
    {
        res.push_back(inverted[i]);
    }

    return res;
}

template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
    //setting up every vertex with initial values
    for(auto &it : vertexSet){
        it->dist = INF;
        it->path = NULL;
    }

    //getting the first vertex
    Vertex<T> * start = findVertex(origin);
    if(start == NULL) return;
    start->dist = 0;

    MutablePriorityQueue<Vertex<T>> vertex_queue;

    vertex_queue.insert(start);

    Vertex<T> * current_vertex;

    while(!vertex_queue.empty()){
        //retrieve the minimum value from queue
        current_vertex = vertex_queue.extractMin();

        //go through all adjacent edges
        for(auto itr : current_vertex->adj){
            if(itr.dest->dist > current_vertex->dist + itr.weight){
                double old_dist = itr.dest->dist;

                //update current edge distance and path
                itr.dest->dist = current_vertex->dist + itr.weight;
                itr.dest->path = current_vertex;

                //if it wasn't processed yet, send it to the queue
                if(old_dist == INF) vertex_queue.insert(itr.dest);
                else vertex_queue.decreaseKey(itr.dest);
            }
        }
    }
}

template<class T>
std::vector<T> Graph<T>::getPath(const T &origin, const T &dest) const{
    std::vector<T> res;

    Vertex<T> * first = findVertex(origin);
    if(first == NULL) return std::vector<T>();
    Vertex<T> * end = findVertex(dest);
    if(end == NULL) return std::vector<T>();

    if(first->getInfo() == end->getInfo()) return std::vector<T>();

    Vertex<T> * current = end;
    res.push_back(current->info);

    while(current != first) {
        if(current->path == NULL) return std::vector<T>();
        current = current->path;
        res.push_back(current->info);
    }
    reverse(res.begin(), res.end());

    return res;
}

template<class T>
void Graph<T>::travellingSalesmanProblem(const T &origin) {

    Vertex<T> * first = findVertex(origin);
    for(auto vertexIt = vertexSet.begin() ; vertexIt != vertexSet.end(); vertexIt++)
    {
        if(*vertexIt != first)
            dijkstraShortestPath(origin, vertexIt);
    }

}

/**
 * Calculates the distance between two nodes, from a vector containing the path
 *
 * @return the distance between the nodes
 */
template<class T>
long double Graph<T>::distanceFromPath(const std::vector<T> &path) {
    long double distance = 0;
    for(auto it = path.begin(); it != path.end() - 1; it++){
        Vertex<T>* i = findVertex((*it));
        if(i == NULL) return 0;
        Vertex<T>* j = findVertex((*(it+1)));
        if(j == NULL) return 0;

        distance += getWeight(i, j);
    }
    return distance;
}
#endif /* GRAPH_H_ */
