//
// Created by User on 8/5/2020.
//

#ifndef MTM_FINAL_PROJECT_20_GRAPH_H
#define MTM_FINAL_PROJECT_20_GRAPH_H

using namespace std;

#include "Vertex.h"
#include "Edge.h"

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

    Graph& operator+()

};


Graph operator+()


#endif //MTM_FINAL_PROJECT_20_GRAPH_H
