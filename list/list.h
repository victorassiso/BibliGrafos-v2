#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "vertex.h"
#include "neighbor.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class AdjacencyList {
  private:
    std::vector<Vertex*> vertices;
    bool directed;
    bool hasWeights;
    bool hasNegativeWeihts;

    Vertex* createVertex(std::string label);
    void createEdge(Vertex* vertex1, Vertex* vertex2, float weight);

    Vertex* verticalSearch(std::string label);
    Neighbor* horizontalSearch(Vertex* vertex, std::string label, bool verbose = false);

    void log(std::string message, bool verbose);
    
  public:
    AdjacencyList();
    ~AdjacencyList();

    void read(std::string inputFilePath, bool verbose = false);

    void dijkstra(std::string _rootLabel);

    void printAdjacencyList();
    void generateGraph(std::string outputFilePath);
};

#endif