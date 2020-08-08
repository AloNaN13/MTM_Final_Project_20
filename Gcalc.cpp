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
#include "Calculator.h"

using namespace std;

void shellGcalc();
void batchGcalc();

bool parseString(Calc gcalc);
bool isCharValid(char c);
bool isOpValid(char c);

void performFunction(Calc gcalc, string func, string dest);
void performOperation(Calc gcalc, char op, string operand1, string operand2, string opee);


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

    //ADDING SOME GRAPHS TO TEST
    Calc gcalc;
    gcalc.insertGraphByName("a");
    gcalc.insertGraphByName("b");
    gcalc.insertGraphByName("c");
    gcalc.getGraphFromName("b").insertVertexByName("x1");
    gcalc.getGraphFromName("b").insertVertexByName("x2");
    gcalc.getGraphFromName("b").insertEdgeByName("<x1,x2>");
    gcalc.getGraphFromName("c").insertVertexByName("x1");
    gcalc.getGraphFromName("c").insertVertexByName("x3");
    gcalc.getGraphFromName("c").insertEdgeByName("<x1,x3>");

    //END OF TEST

    parseString(gcalc);
    // the loop for the shell
    /* while(!quit*) {  // write it as needed
        cout << "Gcalc> ";
        to_quit = parseString();
        if (to_quit == true) {
            break;
        }
    }*/
}


bool parseString(Calc gcalc) {

    // remember to write a while loop for prompting the shell

    string input;
    getline(cin, input);

    //create all of the vectors needed

    vector<State> state_vec;
    vector<string> dest_graph_vec;
    vector<string> function_vec;
    vector<string> op_graphs_vec;
    vector<string> vertices_vec;
    vector<string> edges_vec;
    vector<char> operations_vec;

    State op_code = ERROR;
    string empty_word;
    string curr_word;
    bool first_char_seen_left = false;
    string::iterator it = input.begin();




    // FIRST PART!!!!!!!!!!!!!!!!!!!!

    while(*it != EOF) {
        if (!isCharValid(*it)) {
            //cout << "going through the char in isCharValid: " << *it << endl;
            cout << "got to an invalid character" << endl;
            break;
        }

        // what happens in the first character
        if (first_char_seen_left == false) {
            if (*it == ' ') {
                it++;
                continue;
            }
            if (isalpha(*it)) {
                first_char_seen_left = true;
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


    curr_word = empty_word;











    // SECOND PART!!!!!!!!!!!!!!
    // right side



    bool first_char_seen_right = false;

    while(*it != EOF) {
        if(*it == '.'){
            // put it in the op_graphs_vec
            op_graphs_vec.push_back(curr_word);
            // empty curr_word for the next graph for the operation
            curr_word = empty_word;
            it++;
            break;
        }
        if (op_code == OPERATION) {
            if (!isCharValid(*it)) {
                cout << "going through the char in isCharValid: " << *it << endl;
                cout << "got to an invalid character" << endl;
                break;
            }

            // what happens in the first character
            if (first_char_seen_right == false) {
                if (*it == ' ') {
                    it++;
                    continue;
                }
                if (isalpha(*it)) {
                    first_char_seen_right = true;
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
            if (isOpValid(*it)) {
                //check if there is such a name of graph

                // put it in the op_graphs_vec
                op_graphs_vec.push_back(curr_word);

                // empty curr_word for the next graph for the operation
                curr_word = empty_word;

                // put the op in the operations_vec
                operations_vec.push_back(*it);
                first_char_seen_right = false;
                it++;
                continue;
            }

            if (*it == ' ') {
                while (*it == ' ') {
                    it++;
                }
                if (isOpValid(*it)) {
                    //check if there is such a name of graph

                    // put it in the op_graphs_vec
                    op_graphs_vec.push_back(curr_word);

                    // empty curr_word for the next graph for the operation
                    curr_word = empty_word;

                    // put the op in the operations_vec
                    operations_vec.push_back(*it);
                    first_char_seen_right = false;
                    it++;
                    continue;
                } else {
                    cout << "Invalid syntax." << endl;
                    return false;
                }
            } else {
                cout << "Invalid syntax." << endl;
                return false;
            }
        } else if (op_code == FUNCTION) {
            if (!isCharValid(*it)) {
                //cout << "going through the char in isCharValid: " << *it << endl;
                cout << "got to an invalid character" << endl;
                break;
            }

            // what happens in the first character
            if (first_char_seen_right == false) {
                if (*it == ' ') {
                    it++;
                    continue;
                }
                if (isalpha(*it)) {
                    first_char_seen_right = true;
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
            if (*it == ')') {
                //check if there is such a name of graph

                // put it in the dest_graph_vec
                dest_graph_vec.push_back(curr_word);

                it++;
                break;
            }

            if (*it == ' ') {
                while (*it == ' ') {
                    it++;
                }
                if (*it == ')') {
                    //check if there is such a name of graph

                    // put it in the dest_graph_vec
                    dest_graph_vec.push_back(curr_word);

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
        } else { //what happens if op_code is of assignment
            cout << "not func or op" << endl;
        }
    }





    // PRINTS FOR TESTS

    if(op_code == FUNCTION){
        performFunction(gcalc, *function_vec.begin(), *dest_graph_vec.begin());
        //cout << *function_vec.begin() << endl;
        //cout << *dest_graph_vec.begin() << endl;
    }

    //vector<string>::iterator op_iter = op_graphs_vec.begin();
    if(op_code == OPERATION){
        performOperation(gcalc, *operations_vec.begin(), *op_graphs_vec.begin(),
                        *(op_graphs_vec.begin()+1), *dest_graph_vec.begin());
        //cout << *dest_graph_vec.begin() << endl;
        //cout << *operations_vec.begin() << endl;
        //cout << *op_iter << endl;
        //op_iter++;
        //cout << *op_iter << endl;
    }

    // END OF PRINTS FOR TESTS

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






void performFunction(Calc gcalc, string func, string dest){
    if(func == "print"){
        Graph dest_graph = gcalc.getGraphFromName(dest);
        gcalc.print(dest_graph);
    }
}


void performOperation(Calc gcalc, char op, string operand1, string operand2, string opee){
    if(op == '+'){
        Graph& operand1_graph = gcalc.getGraphFromName(operand1);
        Graph& operand2_graph = gcalc.getGraphFromName(operand2);
        Graph& opee_graph = gcalc.getGraphFromName(opee);
        opee_graph = operand1_graph + operand2_graph;

        // print for test
        performFunction(gcalc, "print", "a");
    }
}






































