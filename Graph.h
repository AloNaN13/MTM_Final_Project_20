//
// Created by User on 8/5/2020.
//

#ifndef MTM_FINAL_PROJECT_20_GRAPH_H
#define MTM_FINAL_PROJECT_20_GRAPH_H

using namespace std;

// namesapce Grpah


#include "Vertex.h"
#include "Edge.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>
#include <memory>

template<class T>
class CompareByName {
public:
    bool operator()(const T* t1, const T* t2) const
    {
        return t1->getName() < t2->getName();
    }
};

class Graph {
private:
    string graph_name;
    set<Vertex, CompareByName<Vertex>> vertices;
    set<Edge, CompareByName<Edge>> edges;
public:
    explicit Graph(string s) : graph_name(s), vertices(nullptr), edges(nullptr){};
    // 3 param ctor?
    ~Graph() = default;
    Graph(const Graph& v) = default;
    Graph& operator=(const Graph& v) = default;

    /*
    // to implement
    Graph& operator+=(const Graph& graph_to_add);
    Graph& operator-=(const Graph& graph_to_sub);
    */

    Graph& operator!();
    friend Graph operator+(const Graph& graph1, const Graph& graph2);
    friend Graph operator-(const Graph& graph1, const Graph& graph2);
    friend Graph operator*(const Graph& graph1, const Graph& graph2);
    friend Graph operator^(const Graph& graph1, const Graph& graph2);

    string getName() const {return this->graph_name};
    friend ostream& operator<<(ostream& os, const Graph& graph);

    void insertVertexByName(string v_name){
        Vertex vertex(v_name);
        vertices.insert(vertex);
    }
    void removeVertexByName(string v_name){
        Vertex vertex(v_name);
        vertices.erase(vertex);
    };
    void insertEdgeByName(string e_name) {
        Edge edge(e_name);
        edges.insert(edge);
    };
    void removeEdgeByName(string e_name){
        Edge edge(e_name);
        edges.erase(edge);
    };

};


Graph operator+(const Graph& graph1, const Graph& graph2) {

    Graph unioned_graph("unioned_graph");
    set_union(graph1.vertices.begin(), graph1.vertices.end(),
            graph2.vertices.begin(), graph2.vertices.end(),
            unioned_graph.vertices.begin(), CompareByName<Vertex>());

    set_union(graph1.edges.begin(), graph1.edges.end(),
              graph2.edges.begin(), graph2.edges.end(),
              unioned_graph.edges.begin(), CompareByName<Edge>());

    return unioned_graph;
}

Graph operator-(const Graph& graph1, const Graph& graph2) {

    Graph diff_graph("diff_graph");
    set_union(graph1.vertices.begin(), graph1.vertices.end(),
              graph2.vertices.begin(), graph2.vertices.end(),
              diff_graph.vertices.begin(), CompareByName<Vertex>());

    set_union(graph1.edges.begin(), graph1.edges.end(),
              graph2.edges.begin(), graph2.edges.end(),
              diff_graph.edges.begin(), CompareByName<Edge>());

    return diff_graph;

}


Graph operator^(const Graph& graph1, const Graph& graph2){

    Graph intersection_graph("intersection_graph");
    set_union(graph1.vertices.begin(), graph1.vertices.end(),
              graph2.vertices.begin(), graph2.vertices.end(),
              intersection_graph.vertices.begin(), CompareByName<Vertex>());

    set_union(graph1.edges.begin(), graph1.edges.end(),
              graph2.edges.begin(), graph2.edges.end(),
              intersection_graph.edges.begin(), CompareByName<Edge>());

    return intersection_graph;

}


Graph operator*(const Graph& graph1, const Graph& graph2) {

}


Graph& Graph::operator!() {
    Graph whole_graph("whole graph");
    whole_graph.vertices = this->vertices;
    for(set<Vertex>::iterator i = vertices.begin(); i != vertices.end(); ++i){
        for(set<Vertex>::iterator j = vertices.begin(); j != vertices.end(); ++j){
            if(i != j){
                string edge_name = "<" + i->getName() + "," + j->getName() + ">";
                whole_graph.insertEdgeByName(edge_name);
            }
        }
    }
    return whole_graph - this;
}




ostream& operator<<(ostream& os, const Graph& graph) {
    //implement
    for(set<Vertex>::iterator i = graph.vertices.begin(); i !=  graph.vertices.end(); ++i){
        cout << i->getName() << endl;
    }

    cout << '$' << endl;

    for(set<Edge>::iterator j = graph.edges.begin(); j !=  graph.edges.end(); ++j){
        string s = j->getName();
        for(string::iterator it = s.begin(); it != s.end(); ++it){
            if(*it != '<' && *it != ',' && *it != '>'){
                cout << *it;
            }
            if(*it == ','){
                cout << ' ';
            }
        }
        cout << endl;
    }

    return os;
}




#endif //MTM_FINAL_PROJECT_20_GRAPH_H




/*
Graph& Graph::operator+=(const Graph& graph_to_add) {
    for(set<Vertex, CompareByName<Vertex>>::iterator i = vertices.begin(); i =! vertices.end(); ++i){
        this->vertices.insert(*i);
    }
}

Graph& Graph::operator-=(const Graph& graph_to_sub) {

}
*/















/*


ostream& operator<<(ostream& os, const Graph& graph) {
    ParkingLotPrinter::printParkingLotTitle(os);

    vector<Vehicle> parking_lot_vector;
    //insert vehicles to the vector
    parkingLot.enterVehiclesToVectorFromArray(parking_lot_vector,
                                              parkingLot.motorbikes_arr);
    parkingLot.enterVehiclesToVectorFromArray(parking_lot_vector,
                                              parkingLot.handicapped_cars_arr);
    parkingLot.enterVehiclesToVectorFromArray(parking_lot_vector,
                                              parkingLot.cars_arr);
    //sorting the vehicle
    sort(parking_lot_vector.begin(), parking_lot_vector.end());
    //printing the vector
    for(unsigned int j = 0; j < parking_lot_vector.size(); j++) {
        ParkingLotPrinter::printVehicle(os, parking_lot_vector[j].getType(),
                                        parking_lot_vector[j].getLicensePlate(),
                                        parking_lot_vector[j].getEntranceTime());
        ParkingSpot parking_spot;
        parkingLot.getParkingSpot(parking_lot_vector[j].getLicensePlate(),
                                  parking_spot);
        ParkingLotPrinter::printParkingSpot(os, parking_spot);
    }
    return os;
}


 */