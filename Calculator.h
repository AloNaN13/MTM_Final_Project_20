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
    set<Graph, CompareByName> graphs;
public:
    Graph() : graphs(nullptr) {};
    ~Graph() = default;
    Graph(const Graph& v) = default;
    Graph& operator=(const Graph& v) = default;

    //implement funcs from HW
    void print(const Graph& graph){
        cout << graph << endl;
    };

    void delete(const Graph& graph){
        delete(graph);
    };

    void who(const Graph& graph){

    };

    void reset(){
        for(set<Graph>::iterator i = graphs.begin(); i != graphs.end(); ++i) {
            delete (i);
        }
    }

    quit

};

#endif //MTM_FINAL_PROJECT_20_CALCULATOR_H
