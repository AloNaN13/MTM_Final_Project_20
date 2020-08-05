//
// Created by User on 8/5/2020.
//

#ifndef MTM_FINAL_PROJECT_20_GRAPH_H
#define MTM_FINAL_PROJECT_20_GRAPH_H

using namespace std;

#include "Vertex.h"
#include "Edge.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <memory>

class Graph {
private:
    string graph_name;
    map<int, shared_ptr<Vertex>> vertices;
    map<int, shared_ptr<Edge>> edges;
public:
    explicit Graph(string s) : graph_name(s),  {};
    ~Graph() = default;
    Graph(const Graph& v) = default;
    Graph& operator=(const Graph& v) = default;

    // to implement
    Graph& operator+=(const Graph& graph);
    Graph& operator-=(const Graph& graph);

};


Graph& Graph::operator+=(const Graph &graph) {

}

Graph& Graph::operator-=(const Graph &graph) {

}



Graph operator+(const Graph& graph1, const Graph& graph2) {

}

Graph operator-(const Graph& graph1, const Graph& graph2) {

}


Graph operator^(const Graph& graph1, const Graph& graph2){

}


Graph operator*(const Graph& graph1, const Graph& graph2) {

}


Graph operator!(const Graph& graph1) {

}






public:
Complex& operator+=(const Complex& c);
Complex& operator-=(const Complex& c);
Complex operator-() const;
bool operator==(const Complex& c) const;
};
 
Complex operator+(const Complex& a, const Complex& b);
Complex operator-(const Complex& a, const Complex& b);
 


#endif //MTM_FINAL_PROJECT_20_GRAPH_H
