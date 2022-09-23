
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <sstream>
#include <algorithm>
#include "Graph.h"

const int MILES_PER_GALLON = 40;
const int CITY_COUNT = 5;
const std::string START_CITY = "Reno";

// Creates the graph, filling in the vertices and connecting them with edges
void createGraph(std::shared_ptr<Graph<std::string> > graph);
// Returns the cost of a path given a list of cities, -1 if a path does not exist
int calculatePathCost(Graph<std::string> & graph, LinkedList<std::string> & path);
// Runs through all permutations of paths between the cities and returns the cheapest one and its cost. Outputs them to output.txt
std::pair<LinkedList<std::string>, int> FindCheapestPath(Graph<std::string> & graph);


int main() {
    std::shared_ptr<Graph<std::string> > graph = std::make_shared<Graph<std::string> >();
    createGraph(graph);

    std::pair<LinkedList<std::string>, int> cheapest = FindCheapestPath(*graph);
    std::cout << "\nCheapest Path:\n";
    for (int i = 0; i < cheapest.first.size(); i++) {
        std::cout << (i == 0 ? cheapest.first[i] : " -> " + cheapest.first[i]);
    }
    std::cout << "\t - " << cheapest.second << " Miles" << " | " << (float) cheapest.second / MILES_PER_GALLON << " Gallons\n";

    return 0;
}

void createGraph(std::shared_ptr<Graph<std::string> > graph) {
    std::ifstream file("data.txt");
    std::string line;

    // Set up vertices
    while (std::getline(file, line)) {
        std::string startingCity(line);
        graph->addVertex(std::make_shared<Vertex<std::string> >(line));

        for (int i = 0; i < CITY_COUNT; i++) {
            std::getline(file, line);
        }

    }

    file.clear();
    file.seekg(0, std::ios::beg);

    // Set up edges
    while (!file.eof()) {
        std::getline(file, line);
        std::shared_ptr<Vertex<std::string> > v = graph->getVertex(line);

        for (int i = 0; i < CITY_COUNT - 1; i++) {
            std::getline(file, line);
            std::stringstream ss;
            int distance;

            std::string temp;
            std::stringstream lineStream(line);
            while (lineStream >> temp) {
                try {
                    distance = std::stoi(temp);
                }
                catch (std::invalid_argument const & e) {
                    ss << ((ss.str().length() == 0) ? temp : " " + temp);
                }
            }

            if (ss.str()[0] == '/') {
                continue;
            }
            
            std::shared_ptr<Edge<std::string> > edge(new Edge<std::string>(distance, graph->getVertex(ss.str())));
            v->addEdge(edge);

        }

        std::getline(file, line);
    }

}

int calculatePathCost(Graph<std::string> & graph, LinkedList<std::string> & path) {
    int total = 0;

    for (int i = 0; i < path.size() - 1; i++) {
        Vertex<std::string> v = *graph.getVertex(path[i]);
        for (int j = 0; j < v.getEdgeCount(); j++) {
            if (!v.connectedTo(path[i+1])) return -1;

            if (v.getEdge(j)->getDest()->getValue() == path[i+1]) {
                total += v.getEdge(j)->getCost();
                continue;
            }
        }
    }
    
    return total;
}

std::pair<LinkedList<std::string>, int> FindCheapestPath(Graph<std::string> & graph) {
    std::ofstream file("output.txt");

    std::cout << "Possible Paths:\n";
    file << "Possible Paths:\n";
    std::string citiesArr[graph.verticesLength() - 1];
    int j = 0;
    for (int i = 0; i < graph.verticesLength(); i++) {
        if (graph.getVertex(i)->getValue() != START_CITY) {
            citiesArr[j++] = graph.getVertex(i)->getValue();
        }
    }

    int minDistance = 999999;
    LinkedList<std::string> shortestPath;

    do {
        LinkedList<std::string> path = LinkedList<std::string>(citiesArr, graph.verticesLength() - 1);
        path.insert(START_CITY, 0);
        path.add(START_CITY);
        int distance = calculatePathCost(graph, path);

        if (distance == -1) continue;

        for (int i = 0; i < path.size(); i++) {
            std::cout << (i == 0 ? path[i] : " -> " + path[i]);
            file << (i == 0 ? path[i] : " -> " + path[i]);
        }
        std::cout << "\t - " << distance << " Miles\n";
        file << "\t - " << distance << " Miles\n";

        if (distance < minDistance) {
            minDistance = distance;
            shortestPath = path;
        }
    } while (std::next_permutation(citiesArr, citiesArr + graph.verticesLength() - 1));

    file << "\nCheapest Path:\n";
    for (int i = 0; i < shortestPath.size(); i++) {
        file << (i == 0 ? shortestPath[i] : " -> " + shortestPath[i]);
    }
    file << "\t - " << minDistance << " Miles" << " | " << (float) minDistance / MILES_PER_GALLON << " Gallons\n";
    
    return std::pair<LinkedList<std::string>, int>(shortestPath, minDistance);
}