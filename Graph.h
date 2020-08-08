//
// Created by User on 8/5/2020.
//

#ifndef MTM_FINAL_PROJECT_20_GRAPH_H
#define MTM_FINAL_PROJECT_20_GRAPH_H

using namespace std;

// namesapce Grpah


#include "Vertex.h"
#include "Edge.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>
#include <memory>

template<class T>
class CompareByName {
public:
    bool operator()(const T t1, const T t2) const {
        return t1.getName() < t2.getName();
    }
};

class Graph {
private:
    string graph_name;
    set<Vertex, CompareByName<Vertex>> vertices;
    set<Edge, CompareByName<Edge>> edges;
public:
    explicit Graph(string s) : graph_name(s){};
    // 3 param ctor?
    ~Graph() = default;
    Graph(const Graph& g) = default;
    Graph& operator=(const Graph& g) = default;

    /*
    // to implement
    Graph& operator+=(const Graph& graph_to_add);
    Graph& operator-=(const Graph& graph_to_sub);
    */

    friend Graph operator!(const Graph& graph);
    friend Graph operator+(const Graph& graph1, const Graph& graph2);
    friend Graph operator-(const Graph& graph1, const Graph& graph2);
    friend Graph operator*(const Graph& graph1, const Graph& graph2);
    friend Graph operator^(const Graph& graph1, const Graph& graph2);

    string getName() const {return this->graph_name;};
    friend ostream& operator<<(ostream& os, const Graph& graph);

    void insertVertexByName(string v_name){
        Vertex vertex(v_name);
        vertices.insert(vertex);
    }
    void removeVertexByName(string v_name){
        Vertex vertex(v_name);
        vertices.erase(vertex);
    };
    void insertEdgeByName(string e_name) {
        Edge edge(e_name);
        edges.insert(edge);
    };
    void removeEdgeByName(string e_name){
        Edge edge(e_name);
        edges.erase(edge);
    };

};


#endif //MTM_FINAL_PROJECT_20_GRAPH_H
