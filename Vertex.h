//
// Created by User on 8/5/2020.
//

#ifndef MTM_FINAL_PROJECT_20_VERTEX_H
#define MTM_FINAL_PROJECT_20_VERTEX_H

using namespace std;

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>


class Vertex {
private:
    string v_name;
public:
    explicit Vertex(string s) : v_name(s) {};
    ~Vertex() = default;
    Vertex(const Vertex& v) = default;
    Vertex& operator=(const Vertex& v) = default;
};

#endif //MTM_FINAL_PROJECT_20_VERTEX_H
