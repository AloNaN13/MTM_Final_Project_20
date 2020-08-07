//
// Created by User on 8/5/2020.
//

#ifndef MTM_FINAL_PROJECT_20_EDGE_H
#define MTM_FINAL_PROJECT_20_EDGE_H

using namespace std;

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>


class Edge {
private:
    string e_name;
public:
    explicit Edge(string s) : e_name(s) {};
    ~Edge() = default;
    Edge(const Edge& e) = default;
    Edge& operator=(const Edge& e) = default;

    string getName() const {return this->e_name;};
};


#endif //MTM_FINAL_PROJECT_20_EDGE_H
