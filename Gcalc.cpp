//
// Created by User on 8/5/2020.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

//#include "Gcalc.h"
//#include "Calculator.h"

using namespace std;

void shellGcalc();
void batchGcalc();

bool parseString();
bool isCharValid(char c);

enum State{
    ERROR,
    FUNCTION,
    OPERATION,
    ASSIGNMENT
};

//if for 0 or 2 args

int main() {
    shellGcalc();
    return 0;
}



void shellGcalc() {
    bool to_quit = false;
    parseString();
    // the loop for the shell
    /* while(!quit*) {  // write it as needed
        cout << "Gcalc> ";
        to_quit = parseString();
        if (to_quit == true) {
            break;
        }
    }*/
}


bool parseString() {

    // remember to write a while loop for prompting the shell

    //Calc gcalc;

    string input;
    cin >> input;

    //create all of the vectors needed

    vector<State> state_vec;
    vector<string> dest_graph_vec;
    vector<string> function_vec;
    vector<string> op_graphs_vec;
    vector<string> vertices_vec;
    vector<string> edges_vec;
    vector<string> operations_vec;

    State op_code = ERROR;
    string empty_word;
    string curr_word;
    bool first_char_seen = false;
    string::iterator it = input.begin();

    while(*it != EOF) {
        if(!isCharValid(*it)) {
            cout << "going through the char in isCharValid: " << *it << endl;
            cout << "got to an invalid character" << endl;
            break;
        }

        // what happens in the first character
        if(first_char_seen == false) {
            if(*it == ' ') {
                it++;
                continue;
            }
            if(isalpha(*it)) {
                first_char_seen = true;
                curr_word += *it;
                cout << "going through the char: " << *it << endl;
                it++;
                continue;
            }
            else {
                cout << "Invalid syntax." << endl;
                return false;
            }
        }

        // after the first character
        if(isalnum(*it)) {
            curr_word += *it;
            cout << "going through the char: " << *it << endl;
            it++;

            continue;
        }
        if(*it == '=') {
            op_code = OPERATION;
            //check if there is such a name of graph

            // put it in the dest_graph_vec
            dest_graph_vec.push_back(curr_word);

            it++;
            break;
        }
        if(*it == '(') {
            op_code = FUNCTION;
            // check if there is such a function
            // if not - error
            //
            // if yes - put the string in function_vec
            function_vec.push_back(curr_word);

            it++;
            break;
        }



        if(*it == ' ') {
            while(*it == ' ') {
                it++;
                cout << "WOHHOOO" << endl;
            }
            if(*(it+1) == '=') {
                op_code = OPERATION;
                //check if there is such a name of graph

                // put it in the dest_graph_vec
                dest_graph_vec.push_back(curr_word);

                it = it+2;
                break;
            }
            if(*(it+1) == '(') {
                op_code = FUNCTION;
                // check if there is such a function
                // if not - error
                //
                // if yes - put the string in function_vec
                function_vec.push_back(curr_word);

                it = it+2;
                break;
            }
        }
    }




    if(op_code == ERROR) {
        cout << "Invalid syntax." << endl;
        return false;
    }

    curr_word = empty_word;


    //cout << "NICE" << endl;




    if(op_code == FUNCTION){
        cout << *function_vec.begin() << endl;
    }

    if(op_code == OPERATION){
        cout << *dest_graph_vec.begin() << endl;
    }


    /*
    //opcode?


    while(){
        if(isCharValid(*it)){
            cout << "got to an invalid character" << endl;
            break;
        }
    }

        cout << *i << " is valid." << endl;

    }
     */

    return false;
}




bool isCharValid(char c){
    return isalnum(c) || c == ' ' || c == '{' || c == '}' ||
           c == '(' || c == ')' || c == '|' || c == '+' ||
           c == '-' || c == '^' || c == '*' || c == '!' ||
           c == '=' || isblank(c) || isspace(c);
}

