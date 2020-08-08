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
    map<string, Graph> calc_graphs;
    //set<Graph, CompareByName<Graph>> calc_graphs;
    set<Vertex, CompareByName<Vertex>> calc_vertices;
    set<Edge, CompareByName<Edge>> calc_edges;

    set<string> calc_functions;
    set<char> calc_operators;

    // extra chars?


public:
    Calc() :  calc_functions({"print", "who", "delete", "reset", "quit"}),
              calc_operators({'+', '-', '^', '*', '!'}) {};
    ~Calc() = default;
    Calc(const Calc& v) = default;
    Calc& operator=(const Calc& v) = default;


    Graph& getGraphFromName(string graph_name) {
        Graph graph_to_find(graph_name);
        return calc_graphs.find(graph_name)->second;
    };

    void insertGraphByName(string g_name){
        Graph graph(g_name);
        calc_graphs.insert({g_name, graph});
    }
    void removeGraphByName(string g_name){
        Graph graph(g_name);
        calc_graphs.erase(g_name);
    };

    //implement funcs from HW
    void print(const Graph& graph){
        cout << graph << endl;
    };

    //void delete(const Graph& graph){
    //    delete(graph);
    //};


    void who() const{
        for(auto it = calc_graphs.begin(); it !=  calc_graphs.end(); ++it){
            cout << it->second.getName() << endl;
        }
    };

    //void reset(){
    //    for(set<Graph>::iterator i = calc_graphs.begin(); i != calc_graphs.end(); ++i) {
    //        delete (i);
    //    }
    //}

    //quit

};

#endif //MTM_FINAL_PROJECT_20_CALCULATOR_H
