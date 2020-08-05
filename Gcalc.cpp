//
// Created by User on 8/5/2020.
//

#include <iostream>
//#include "Gcalc.h"

void run_gcalc();

main(){
    run_gcalc();
    return 0;
}


void run_gcalc(){
    int x = 0;
    while(x >= 0){
        std::cout << "Gcalc> ";
        std::cin >> x;
        std::cout << "x+7 is now: " << x+7 << std::endl;
    }
}


