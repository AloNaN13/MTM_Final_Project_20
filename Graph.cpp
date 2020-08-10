//
// Created by User on 8/5/2020.
//

#include "Graph.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>


Graph operator+(const Graph& graph1, const Graph& graph2) {

    Graph unioned_graph("unioned_graph");
    set_union(graph1.vertices.begin(), graph1.vertices.end(),
                   graph2.vertices.begin(), graph2.vertices.end(),
                   inserter(unioned_graph.vertices, unioned_graph.vertices.begin()), CompareByName<Vertex>());

    set_union(graph1.edges.begin(), graph1.edges.end(),
                   graph2.edges.begin(), graph2.edges.end(),
                   inserter(unioned_graph.edges, unioned_graph.edges.begin()), CompareByName<Edge>());

    return unioned_graph;

}

Graph operator-(const Graph& graph1, const Graph& graph2) {

    Graph diff_graph("diff_graph");
    set_difference(graph1.vertices.begin(), graph1.vertices.end(),
              graph2.vertices.begin(), graph2.vertices.end(),
              inserter(diff_graph.vertices, diff_graph.vertices.begin()), CompareByName<Vertex>());

    set_difference(graph1.edges.begin(), graph1.edges.end(),
              graph2.edges.begin(), graph2.edges.end(),
              inserter(diff_graph.edges, diff_graph.edges.begin()), CompareByName<Edge>());

    return diff_graph;

}


Graph operator^(const Graph& graph1, const Graph& graph2){

    Graph intersection_graph("intersection_graph");
    set_intersection(graph1.vertices.begin(), graph1.vertices.end(),
              graph2.vertices.begin(), graph2.vertices.end(),
              inserter(intersection_graph.vertices, intersection_graph.vertices.begin()),
              CompareByName<Vertex>());

    set_intersection(graph1.edges.begin(), graph1.edges.end(),
              graph2.edges.begin(), graph2.edges.end(),
              inserter(intersection_graph.edges, intersection_graph.edges.begin()),
              CompareByName<Edge>());

    return intersection_graph;

}

/*
Graph operator*(const Graph& graph1, const Graph& graph2) {

}
*/

Graph operator!(const Graph& graph){
    Graph whole_graph("whole graph");
    whole_graph.vertices = graph.vertices;
    for(set<Vertex>::iterator i = graph.vertices.begin(); i != graph.vertices.end(); ++i){
        for(set<Vertex>::iterator j = graph.vertices.begin(); j != graph.vertices.end(); ++j){
            if(i != j){
                string edge_name = "<" + i->getName() + "," + j->getName() + ">";
                whole_graph.insertEdgeByName(edge_name);
            }
        }
    }
    return whole_graph - graph;
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
