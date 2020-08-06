//
// Created by User on 8/5/2020.
//

#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <cctype>

//#include "Gcalc.h"

using namespace std;

void shell_gcalc();


main() {
    shell_gcalc();
    return 0;
}





void shell_gcalc(){
    int opcode = 1;
            // opcode == 1 -> shell
            // opcode == 2 -> txt
    if(opcode == 1){

        string input;
        cin >> input;


        cout << 

        /*int x = 0;
        while(x >= 0){
            cout << "Gcalc> ";
            cin >> x;
            cout << "x+7 is now: " << x+7 << endl;
        }
         */
    }
    if(opcode == 2){
        // txt
    }
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





