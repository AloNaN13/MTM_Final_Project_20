//
// Created by User on 8/5/2020.
//

#include <iostream>
#include <fstream>
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
bool isCharValidVertex(char c);
void emptyVectors(vector<string>& v1, vector<string>& v2, vector<string>& v3,
                  vector<string>& v4, vector<string>& v5, vector<char>& v6);
void performFunction(Calc gcalc, vector<string>::iterator func, vector<string>::iterator dest);
void performOperation(Calc gcalc, char op, vector<string>::iterator operand1,
                        vector<string>::iterator operand2, vector<string>::iterator opee);
void performAssignment(Calc gcalc, vector<string> vertices_vec, vector<string> edges_vec, string dest);

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

    gcalc.getGraphFromName("c").insertVertexByName("x2");
    gcalc.getGraphFromName("c").insertEdgeByName("<x1,x2>");


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

    //vector<State> state_vec;
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

    while(*it != EOF && *it != 0) {
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
                emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
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
                emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
                return false;
            }
        } else {
            cout << "Invalid syntax." << endl;
            emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
            return false;
        }
    }

    if(op_code == ERROR) {
        cout << "Invalid syntax." << endl;
        emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
        return false;
    }


    curr_word = empty_word;






















    // SECOND PART!!!!!!!!!!!!!!
    // right side


    bool is_simple_assignment = true;
    bool first_char_seen_right = false;
    int num_of_vertex_seen = 0;
    bool inserting_vertices = false;
    bool inserting_edges = false;
    int num_of_openers = 0;

    while(*it != EOF && *it != 0) {
        if (op_code == ASSIGNMENT) {
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
                if (isalnum(*it)) {
                    first_char_seen_right = true;
                    curr_word += *it;
                    //cout << "going through the first char: " << *it << endl;
                    it++;
                    continue;
                }
                if (*it == '|') {
                    // it's an assignment
                    inserting_vertices = false;
                    inserting_edges = true;
                    first_char_seen_right = false;
                    it++;
                    continue;
                }
                else {
                    cout << "Invalid syntax." << endl;
                    emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
                    return false;
                }
            }


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
                }
                if (*it == '{') {
                    // it's an assignment
                    op_code = ASSIGNMENT;
                    inserting_vertices = true;
                    it++;
                    continue;
                }
                else {
                    cout << "Invalid syntax." << endl;
                    emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
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
                is_simple_assignment = false;

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
                    is_simple_assignment = false;

                    // put the op in the operations_vec
                    operations_vec.push_back(*it);
                    first_char_seen_right = false;
                    it++;
                    continue;
                } else {
                    cout << "Invalid syntax." << endl;
                    emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
                    return false;
                }
            } else {
                cout << "Invalid syntax." << endl;
                emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
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
                    emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
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
                    emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
                    return false;
                }
            } else {
                cout << "Invalid syntax." << endl;
                emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
                return false;
            }
        } else { //what happens if op_code is of assignment
            cout << "not func or op" << endl;
        }
    }





    // PRINTS FOR TESTS

    if(op_code == FUNCTION){
        if(it != input.end()-1){
            cout << "Invalid syntax." << endl;
            emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
            return false;
        }
        performFunction(gcalc, function_vec.begin(), dest_graph_vec.begin());
        //cout << *function_vec.begin() << endl;
        //cout << *dest_graph_vec.begin() << endl;
    }

    if(op_code == OPERATION){
        if(it != input.end()){
            cout << "Invalid syntax." << endl;
            emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
            return false;
        }
        if(curr_word == empty_word){
            cout << "Invalid syntax." << endl;
            emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
            return false;
        }

        // put the last operand in the op_graphs_vec
        op_graphs_vec.push_back(curr_word);

        if(is_simple_assignment == true){
            op_graphs_vec.push_back(curr_word);
            performOperation(gcalc, '=', op_graphs_vec.begin(), op_graphs_vec.begin(), dest_graph_vec.begin());
        }
        if(*operations_vec.begin() == '!'){
            performOperation(gcalc, *operations_vec.begin(), op_graphs_vec.begin(),
                            op_graphs_vec.begin(), dest_graph_vec.begin());
        } else {
            performOperation(gcalc, *operations_vec.begin(), op_graphs_vec.begin(),
                             (op_graphs_vec.begin()+1), dest_graph_vec.begin());
        }

        // printing tests

        //vector<string>::iterator op_iter = op_graphs_vec.begin();
        //cout << "what is actually inside: " << endl;
        //cout << *dest_graph_vec.begin() << endl;
        //cout << "=" << endl;
        //cout << *op_iter << *operations_vec.begin() << *(op_iter+1) << endl;
    }

    // END OF PRINTS FOR TESTS

    emptyVectors(dest_graph_vec, function_vec, op_graphs_vec, vertices_vec, edges_vec, operations_vec);
    return false;
}




bool isCharValid(char c){
    return isalnum(c) || c == ' ' || c == '{' || c == '}' ||
           c == '(' || c == ')' || c == '|' || c == '+' ||
           c == '-' || c == '^' || c == '*' || c == '!' ||
           c == '=' || c == '[' || c == ']' || c == ';';
}


bool isOpValid(char c){
    return c == '+' || c == '-' || c == '^' || c == '*' || c == '!';
}

bool isCharValidVertex(char c){
    return isalnum(c) || c == '[' || c == ']' || c == ';';
}






void performFunction(Calc gcalc, vector<string>::iterator func, vector<string>::iterator dest){
    if(*func == "print"){
        Graph dest_graph = gcalc.getGraphFromName(*dest);
        gcalc.print(dest_graph);
    }
}


void performOperation(Calc gcalc, char op, vector<string>::iterator operand1,
                        vector<string>::iterator operand2, vector<string>::iterator opee){
    Graph& operand1_graph = gcalc.getGraphFromName(*operand1);
    Graph& operand2_graph = gcalc.getGraphFromName(*operand2);
    Graph& opee_graph = gcalc.getGraphFromName(*opee);
    if(op == '+'){
        opee_graph = operand1_graph + operand2_graph;
    }
    else if(op == '-'){
        opee_graph = operand1_graph - operand2_graph;
    }
    else if(op == '^'){
        opee_graph = operand1_graph ^ operand2_graph;
    }
    else if(op == '!'){
        opee_graph = !operand1_graph;
    }
    else if(op == '='){
        opee_graph = operand1_graph;
    }
/*
    else if(op == '*'){

    }*/


    // print for test
    vector<string> vec_for_test_print({"print"});
    performFunction(gcalc, vec_for_test_print.begin(), opee);

}


void performAssignment(Calc gcalc, vector<string> vertices_vec, vector<string> edges_vec, string dest){
    Graph dest_graph(dest);
    for(vector<string>::iterator i = vertices_vec.begin(); i != vertices_vec.end(); ++i){
        dest_graph.insertVertexByName(*i);
    }
    for(vector<string>::iterator j = edges_vec.begin(); j != edges_vec.end(); ++j){
        dest_graph.insertEdgeByName(*j);
    }
    gcalc.insertGraphByElement(dest_graph);
}


void emptyVectors(vector<string>& v1, vector<string>& v2, vector<string>& v3,
                  vector<string>& v4, vector<string>& v5, vector<char>& v6){
    vector<string> empty_vec_str;
    vector<char> empty_vec_char;
    v1 = empty_vec_str;
    v2 = empty_vec_str;
    v3 = empty_vec_str;
    v4 = empty_vec_str;
    v5 = empty_vec_str;
    v6 = empty_vec_char;
}



















































































/*


 // remember is_simple_assignment = false;

assign_opcode() {
    if (op_code == ASSIGNMENT) {
        if (!isCharValid(*it)) {
            cout << "going through the char in isCharValid: " << *it << endl;
            cout << "got to an invalid character" << endl;
            break;
        }

        if (inserting_vertices == true){
            // what happens in the first character
            if (first_char_seen_right == false) {
                if (*it == ' ') {
                    it++;
                    continue;
                }
                if (isalnum(*it) || *it == '[') {
                    if(*it == '['){
                        num_of_openers++;
                    }
                    first_char_seen_right = true;
                    curr_word += *it;
                    //cout << "going through the first char: " << *it << endl;
                    it++;
                    continue;
                }
                if (*it == '}') {
                    // check if edges contain vertices that exist in the assignment order

                    // assignment ended
                    performAssignment(gcalc, vertices_vec, edges_vec, dest_graph_vec);
                    inserting_vertices = false;
                    inserting_edges = false;
                    it++;
                    break;
                }
                if (*it == '|') {
                    if(inserting_edges == true){
                        cout << "Invalid Syntax." << endl;
                        return false;
                    }
                    first_char_seen_right = false;
                    inserting_vertices = false;
                    inserting_edges = true;
                    it++;
                    continue;
                } else {
                    cout << "Invalid syntax." << endl;
                    return false;
                }
            }

            // after the first character
            if (isCharValidVertex(*it)) {
                if(*it == ';' || *it == ']'){
                    if(!(num_of_openers>0)){
                        cout << "Invalid Syntax." << endl;
                        return false;
                    }
                    num_of_openers--;
                }
                if(*it == '['){
                    num_of_openers++;
                }
                curr_word += *it;
                //cout << "going through the char (not first): " << *it << endl;
                it++;
                continue;
            }
            if (*it == ',') {

                //check for []
                if (num_of_openers != 0) {
                    cout << "Invalid syntax." << endl;
                    return false;
                }

                // put it in the vertices_vec
                vertices_vec.push_back(curr_word);

                // empty curr_word for the next vertex
                curr_word = empty_word;

                first_char_seen_right = false;
                it++;
                continue;
            }
            if (*it == '|') {
                if(inserting_edges == true){
                    cout << "Invalid Syntax." << endl;
                    return false;
                }
                first_char_seen_right = false;
                inserting_vertices = false;
                inserting_edges = true;
                it++;
                continue;
            }

            if (*it == ' ') {
                while (*it == ' ') {
                    it++;
                }
                if (*it == ',') {

                    //check for []
                    if (num_of_openers != 0) {
                        cout << "Invalid syntax." << endl;
                        return false;
                    }

                    // put it in the vertices_vec
                    vertices_vec.push_back(curr_word);

                    // empty curr_word for the next vertex
                    curr_word = empty_word;

                    first_char_seen_right = false;
                    it++;
                    continue;
                }
                if (*it == '|') {
                    if(inserting_edges == true){
                        cout << "Invalid Syntax." << endl;
                        return false;
                    }
                    first_char_seen_right = false;
                    inserting_vertices = false;
                    inserting_edges = true;
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
        }




        if (inserting_edges == true){

        }

    }

}


























edge_insertion(){
    // what happens if it is <
    if (first_char_seen_right == false) {
        if (*it == ' ') {
            it++;
            continue;
        }
        if (*it == '<') {
            first_char_seen_right = true;
            curr_word += *it;
            //cout << "going through the first char: " << *it << endl;
            it++;
            continue;
        }
        if (*it == '}') {
            // check if edges contain vertices that exist in the assignment order

            // assignment ended
            performAssignment(gcalc, vertices_vec, edges_vec, dest_graph_vec);
            inserting_vertices = false;
            inserting_edges = false;
            it++;
            break;
        } else {
            cout << "Invalid syntax." << endl;
            return false;
        }
    }

    // after the <

    if (num_of_vertex_seen == 0){
        if (*it == ' ') {
            it++;
            continue;
        }
        if (isalnum(*it) || *it == '[') {
            if(*it == '['){
                num_of_openers++;
            }
            first_char_seen_right = true;
            curr_word += *it;
            //cout << "going through the first char: " << *it << endl;
            it++;
            continue;
        }
        if (*it == '}') {
            // check if edges contain vertices that exist in the assignment order

            // assignment ended
            performAssignment(gcalc, vertices_vec, edges_vec, dest_graph_vec);
            inserting_vertices = false;
            inserting_edges = false;
            it++;
            break;
        }
        if (*it == '|') {
            if(inserting_edges == true){
                cout << "Invalid Syntax." << endl;
                return false;
            }
            first_char_seen_right = false;
            inserting_vertices = false;
            inserting_edges = true;
            it++;
            continue;
        } else {
            cout << "Invalid syntax." << endl;
            return false;
        }
    }







    // ad the vertex inside, two of them

    if (num_of_vertex_seen == 2) {
        if (*it == ' ') {
            it++;
            continue;
        }
        if (*it == '>') {
            first_char_seen_right = false;
            num_of_vertex_seen = 0;
            curr_word += *it;
            //cout << "going through the first char: " << *it << endl;
            it++;
            continue;
        }
        if (*it == '}') {
            // check if edges contain vertices that exist in the assignment order

            // assignment ended
            performAssignment(gcalc, vertices_vec, edges_vec, dest_graph_vec);
            inserting_vertices = false;
            inserting_edges = false;
            it++;
            break;
        } else {
            cout << "Invalid syntax." << endl;
            return false;
        }
    }




}












*/


