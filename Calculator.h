//
// Created by User on 8/5/2020.
//

#ifndef MTM_FINAL_PROJECT_20_CALCULATOR_H
#define MTM_FINAL_PROJECT_20_CALCULATOR_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>

#include "Graph.h"

using namespace std;



class Calc {
private:
    set<Graph, CompareByName> calc_graphs;
    set<Vertex, CompareByName> calc_vertices;
    set<Edge, CompareByName> calc_edges;

    set<string> calc_functions;
    set<string> calc_operators;

    // extra chars?


public:
    Graph() : calc_graphs(nullptr), calc_vertices(nullptr), calc_edges(nullptr),
              calc_functions({"print", "who", "delete", "reset", "quit"}),
              calc_operators("+", "-", "^", "*", "!") {};
    ~Graph() = default;
    Graph(const Graph& v) = default;
    Graph& operator=(const Graph& v) = default;


    Graph& getGraphFromName(string graph_name) const{
        return *calc_graphs.find(graph_name);
    };

    //implement funcs from HW
    void print(const Graph& graph){
        cout << graph << endl;
    };

    void delete(const Graph& graph){
        delete(graph);
    };

    void who() const{
        for(set<Graph>::iterator i = calc_graphs.begin() ; i !=  calc_graphs.end(); ++i){
            cout << i->getName() << endl;
        }
    };

    void reset(){
        for(set<Graph>::iterator i = calc_graphs.begin(); i != calc_graphs.end(); ++i) {
            delete (i);
        }
    }

    //quit

};

#endif //MTM_FINAL_PROJECT_20_CALCULATOR_H
