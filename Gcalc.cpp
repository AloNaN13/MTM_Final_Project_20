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
bool isOpValid(char c);

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
    getline(cin, input);

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




    // FIRST PART!!!!!!!!!!!!!!!!!!!!

    while(*it != EOF) {
        if (!isCharValid(*it)) {
            //cout << "going through the char in isCharValid: " << *it << endl;
            cout << "got to an invalid character" << endl;
            break;
        }

        // what happens in the first character
        if (first_char_seen == false) {
            if (*it == ' ') {
                it++;
                continue;
            }
            if (isalpha(*it)) {
                first_char_seen = true;
                curr_word += *it;
                //cout << "going through the first char: " << *it << endl;
                it++;
                continue;
            } else {
                cout << "Invalid syntax." << endl;
                return false;
            }
        }

        // after the first character
        if (isalnum(*it)) {
            curr_word += *it;
            //cout << "going through the char (not first): " << *it << endl;
            it++;

            continue;
        }
        if (*it == '=') {
            op_code = OPERATION;
            //check if there is such a name of graph

            // put it in the dest_graph_vec
            dest_graph_vec.push_back(curr_word);

            it++;
            break;
        }
        if (*it == '(') {
            op_code = FUNCTION;
            // check if there is such a function
            // if not - error
            //
            // if yes - put the string in function_vec
            function_vec.push_back(curr_word);

            it++;
            break;
        }


        if (*it == ' ') {
            while (*it == ' ') {
                it++;
            }
            if (*it == '=') {
                op_code = OPERATION;
                //check if there is such a name of graph

                // put it in the dest_graph_vec
                dest_graph_vec.push_back(curr_word);

                it++;
                break;
            }
            if (*it == '(') {
                op_code = FUNCTION;
                // check if there is such a function
                // if not - error
                //
                // if yes - put the string in function_vec
                function_vec.push_back(curr_word);

                it++;
                break;
            } else {
                cout << "Invalid syntax." << endl;
                return false;
            }
        } else {
            cout << "Invalid syntax." << endl;
            return false;
        }
    }

    if(op_code == ERROR) {
        cout << "Invalid syntax." << endl;
        return false;
    }

    if(op_code == FUNCTION){
        cout << *function_vec.begin() << endl;
    }

    if(op_code == OPERATION){
        cout << *dest_graph_vec.begin() << endl;
    }

    curr_word = empty_word;











    // SECOND PART!!!!!!!!!!!!!!


    /*
    //opcode?
*/



    // just to check the 1 operator
    bool is_there_an_op = false;

    while(*it != EOF) {
        //just for the checking
        if (*it == '.') {
            break;
        }





        if (!isCharValid(*it)) {
            //cout << "going through the char in isCharValid: " << *it << endl;
            cout << "got to an invalid character" << endl;
            break;
        }

        // what happens in the first character
        if (first_char_seen == false) {
            if (*it == ' ') {
                it++;
                continue;
            }
            if (isalpha(*it)) {
                first_char_seen = true;
                curr_word += *it;
                //cout << "going through the first char: " << *it << endl;
                it++;
                continue;
            } else {
                cout << "GOT HERE" << endl;
                cout << "Invalid syntax." << endl;
                return false;
            }
        }

        // after the first character
        if (isalnum(*it)) {
            curr_word += *it;
            //cout << "going through the char (not first): " << *it << endl;
            it++;

            continue;
        }

        if (*it == '+') {

            // just to check the 1 operator
            is_there_an_op = true;

            // chech if curr_word is in graph
            // if not - error

            // if yes - put it in the op_graphs_vec
            op_graphs_vec.push_back(curr_word);

            //empty the curr_word for the next graph
            curr_word = empty_word;
            it++;
            break;
        }
        if (*it == ' ') {
            while (*it == ' ') {
                it++;
            }
            if (*it == '+') {

                // just to check the 1 operator
                is_there_an_op = true;

                // check if curr_word is in graph
                // if not - error

                // if yes - put it in the op_graphs_vec
                op_graphs_vec.push_back(curr_word);

                //empty the curr_word for the next graph
                curr_word = empty_word;
                it++;

                // add the + operator to the operations_vec

                if (!isalpha(*(it+1))) {
                    break;
                }
            } else {
                cout << "GOT HERE 2" << endl;
                cout << "Invalid syntax." << endl;
                return false;
            }
        } else {
            cout << "GOT HERE 3" << endl;
            cout << "Invalid syntax." << endl;
            return false;
        }
    }

    if(is_there_an_op == true){
        vector<string>::iterator iter = op_graphs_vec.begin();
        cout << *iter << "," << endl;
        iter++;
        cout << *iter << endl;
    }

    return false;
}




bool isCharValid(char c){
    return isalnum(c) || c == ' ' || c == '{' || c == '}' ||
           c == '(' || c == ')' || c == '|' || c == '+' ||
           c == '-' || c == '^' || c == '*' || c == '!' ||
           c == '=';
}


bool isOpValid(char c){
    return c == '+' || c == '-' || c == '^' || c == '*' || c == '!';
}

