//
// Created by User on 8/5/2020.
//

#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>

//#include "Gcalc.h"


//void run_gcalc();


main() {

    //char x1[5] = "x1";
    //char x2[5] = "x2";
    //std::string s();
    //std::strcat(s, "<");
    //std::strcat(s, x1);
    //std::strcat(s, ",");
    //std::strcat(s, x2);
    //std::strcat(s, ">");


    std::string x1("x1");
    std::string x2("x2");
    std::string s("");
    s = "<" + x1 + "," + x2 + ">";
    std::cout << s << std::endl;
    //shell_gcalc();
    return 0;
}







/*

class Vertex {
public:
    int num;
    explicit Vertex(int num) : num(num) {};
    bool operator<(const Vertex& v) const {
        return this->num < v.num;
    }
};

main() {

    Vertex a(1);
    Vertex b(8);
    Vertex c(3);
    Vertex d(8);

    std::set<Vertex> ab = {a, b};
    std::set<Vertex> cd = {c, d};

    std::set<Vertex> s;
    std::set_difference(ab.begin(), ab.end(),
                   cd.begin(), cd.end(),
                   std::inserter(s, s.begin()));

    for (auto const &e: s) {
        std::cout << e.num << ' ';
    }

    //shell_gcalc();
    return 0;
}

*/






/*
void shell_gcalc(){
    int x = 0;
    while(x >= 0){
        std::cout << "Gcalc> ";
        std::cin >> x;
        std::cout << "x+7 is now: " << x+7 << std::endl;
    }
}
*/

