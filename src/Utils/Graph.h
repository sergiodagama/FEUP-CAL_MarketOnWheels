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

/*#include "MutablePriorityQueue.h"// falta adicionar mutable*/


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
    /*  friend class MutablePriorityQueue<Vertex<T>>;*/
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

public:
    Vertex<T> *findVertex(const T &in) const;

    bool addVertex(const T &in);

    bool addEdge(const T &sourc, const T &dest, double w);

    int getNumVertex() const;

    double getWeight(Vertex<T>* vertex1, Vertex<T>* vertex2);

    std::vector<Vertex<T> *> getVertexSet() const;

    // Fp06 - single source
    void unweightedShortestPath(const T &s);    //TODO...
    void dijkstraShortestPath(const T &s);      //TODO...
    void bellmanFordShortestPath(const T &s);   //TODO...
    std::vector<T> getPath(const T &origin, const T &dest) const;   //TODO...

    // Fp06 - all pairs
    void floydWarshallShortestPath();   //TODO...
    std::vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;   //TODO...

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


/**************** Single Source Shortest Path algorithms ************/

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {
    //setting all vertex dist to infinite and all path's to null
    for (auto &it : vertexSet) {
        it->dist = INT_MAX;
        it->path = NULL;
    }

    //finding vertex to start the algorithm with
    Vertex<T> *origin = findVertex(orig);
    if (origin == NULL) return;
    origin->dist = 0;

    std::queue<Vertex<T> *> vertex_queue;

    vertex_queue.push(origin);

    //to hold the current vertex being treated
    Vertex<T> *current_vertex;

    while (!vertex_queue.empty()) {
        current_vertex = vertex_queue.front();
        vertex_queue.pop();

        for (auto itr : current_vertex->adj) {
            //check if the vertex wasn't processed yet
            if (itr.dest->dist == INT_MAX) {
                vertex_queue.push(itr.dest);

                itr.dest->dist = current_vertex->dist + 1;
                itr.dest->path = current_vertex;
            }
        }
    }
}

template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
    //setting up every vertex with initial values
    for (auto &it : vertexSet) {
        it->dist = INF;
        it->path = NULL;
    }

    //getting the first vertex
    Vertex<T> *start = findVertex(origin);
    if (start == NULL) return;
    start->dist = 0;

    /*  MutablePriorityQueue<Vertex<T>> vertex_queue;

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
      }*/
}


template<class T>
void Graph<T>::bellmanFordShortestPath(const T &orig) {
    //setting up initial vertex's values
    for (auto it : vertexSet) {
        it->dist = INF;
        it->path = NULL;
    }

    Vertex<T> *start = findVertex(orig);

    if (start == NULL) return;

    start->dist = 0;

    for (int i = 0; i < vertexSet.size() - 1; i++) {

        for (auto v : vertexSet) {
            Vertex<T> *current_vertex = v;

            for (auto itr : current_vertex->adj) {
                if (itr.dest->dist > current_vertex->dist + itr.weight) {
                    itr.dest->dist = current_vertex->dist + itr.weight;
                    itr.dest->path = current_vertex;
                }
            }
        }
    }

    for (auto v : vertexSet) {
        for (auto e : v->adj) {
            if (v->dist + e.weight < e.dest->dist) {
                std::cout << "NEGATIVE VALUES CYCLES FAIL" << std::endl;
                return;
            }
        }
    }

}


template<class T>
std::vector<T> Graph<T>::getPath(const T &origin, const T &dest) const {
    std::vector<T> res;

    //initial vertex of path to build
    Vertex<T> *v = findVertex(dest);

    //go through each vertex path until end
    while (v != NULL) {
        res.push_back(v->info);
        v = v->path;
    }

    std::reverse(res.begin(), res.end());

    return res;
}


/**************** All Pairs Shortest Path  ***************/

/*template<class T>
void Graph<T>::floydWarshallShortestPath() {
    //create matrix representation of vertexes and their relative distances to other vertexes
    std::vector<std::vector<double>> vertex_matrix(vertexSet.size(), std::vector<double>(vertexSet.size(), INF));

    for (int i = 0; i < vertex_matrix.size(); i++) {
        for (int j = 0; j < vertex_matrix.at(i).size(); j++) {
            if (i == j) vertex_matrix.at(i).at(j) = 0;
        }
    }

    //go through all vertexes
    for (int i = 0; i < vertexSet.size(); i++) {
        Vertex<T> *current_vertex;

        //again go through all vertexes to check if they have an outgoing edge to current vertex
        for (int j = 0; j < vertexSet.size(); j++) {
            if (i == j) continue; //ignore when the vertexes are the same

          // for(auto e : current_vertex->adj){

            //   if(e.dest == current_vertex){
            //       vertex_matrix.at(i).at(j) = e.weight;
            //       break;
               }
           }

        }
    }
}*/

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
    //create matrix representation of vertexes and their relative distances to other vertexes
    //std::vector<std::vector<double>> dist(vertexSet.size(), std::vector<double>(vertexSet.size(), INF));

    std::cout << vertexSet.size() << std::endl;
    std::vector<std::vector<double>> distMin(vertexSet.size(), std::vector<double>(vertexSet.size(), 0));
    std::vector<std::vector<Vertex<T>*>> path(vertexSet.size(), std::vector<Vertex<T>*>(vertexSet.size(), 0));


    for (int i = 0; i < distMin.size(); i++) {
        for (int j = 0; j < distMin[i].size(); j++) {

            if (i == j) distMin[i][j] = 0;
                /*else if (( edge = thereIsEdge(vertexSet[i], vertexSet[j])) != 0)
                {
                    distMin[i][j] = edge->weight;
                    cout << "WEIGHT DENTRO " << edge->weight << endl;
                }

                else
                    distMin[i][j] = INF;*/
            else
            {
                distMin[i][j] = getWeight(vertexSet[i], vertexSet[j]);
            }
        }
    }

    std::cout << "INF=" << INF << std::endl;

    std::cout << "After initialization" << std::endl;
    for(int i = 0; i < distMin.size(); i++)
    {
        for(int j = 0; j < distMin[i].size(); j++)
        {
            if(distMin[i][j] == INF) std::cout << "INF" << " ";
            else std::cout << distMin[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int k = 0; k < vertexSet.size(); k++) {
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

    std::cout << "After Floyd" << std::endl;
    for(int i = 0; i < distMin.size(); i++)
    {
        for(int j = 0; j < distMin[i].size(); j++)
        {
            if(distMin[i][j] == INF) std::cout << "INF" << " ";
            else std::cout << distMin[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


template<class T>
std::vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const {
    std::vector<T> res;
    // TODO implement this
    return res;
}


#endif /* GRAPH_H_ */
