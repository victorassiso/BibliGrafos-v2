#include "list.h"

  AdjacencyList::AdjacencyList() {
    directed = false;
    hasWeights = false;
    hasNegativeWeihts = false;
  }

  AdjacencyList::~AdjacencyList(){}

  void AdjacencyList::read(std::string _inputFilePath, bool _verbose){
    // std::cout << "Building Adjacency List..." << std::endl;
    log("Building Adjacency List...\n", _verbose);
    
    directed = false;
    hasWeights = false;
    hasNegativeWeihts = false;

    std::string line, label1, label2, graphType;
    float weight;
    std::fstream file;

    file.open(_inputFilePath, std::fstream::in);
    if(!file.is_open()) {
      std::cout << "File does not Exist!" << std::endl;
      return;
    }

    file >> graphType;
    if (graphType == "D") {
      directed = true;
    }

    // Ignore first line
    std::getline(file, line);

    while(std::getline(file, line)) {
      std::stringstream ss(line);
      ss >> label1 >> label2;
      
      if (!(ss >> weight)) {
        weight = 1.0f;
      }
      else {
        hasWeights = true;
      }

      if (weight<0) {
        hasNegativeWeihts = true;
      }

      Vertex* vertex1 = this->createVertex(label1);
      Vertex* vertex2 = this->createVertex(label2);
      this->createEdge(vertex1, vertex2, weight);
      log(label1 + " " + label2 + " " + std::to_string(weight) + "\n", _verbose);
    }

    file.close();
    log("Adjacency List built successfully!\n", _verbose);

  }

  Vertex* AdjacencyList::createVertex(std::string _label) {
    Vertex* vertex = verticalSearch(_label);

    if (!vertex) {
      vertex = new Vertex(_label);
      vertices.push_back(vertex);
    }

    return vertex;
  }
  void AdjacencyList::createEdge(Vertex* _vertex1, Vertex* _vertex2, float _weight) {
    Neighbor* lastNeighbor = horizontalSearch(_vertex1, _vertex2->getLabel());
    
    // If vertex1 has no Neighbor yet...
    if (!lastNeighbor){
      Neighbor* newNeighbor = new Neighbor(_vertex2, _weight);
      // Set neighbor directly to vertex1
      _vertex1->setNeighbor(newNeighbor);
    } else {
      // If Edge already exists...
      if (lastNeighbor->getVertex()->getLabel() == _vertex2->getLabel()) {
        return;
      }
      else {
        Neighbor* newNeighbor = new Neighbor(_vertex2, _weight);
        // Set neighbor to the last neighbor of vertex1 neighbors list
        lastNeighbor->setNeighbor(newNeighbor);
      }
    }

  }

  Vertex* AdjacencyList::verticalSearch(std::string _label) {
    for (int i=0; i<vertices.size(); i++) {
      if (vertices.at(i)->getLabel() == _label)
        return vertices.at(i);
    }
    return nullptr;
  }

  Neighbor* AdjacencyList::horizontalSearch(Vertex* _vertex, std::string _label, bool _verbose) {
    log("Horizontal Search...\n", _verbose);
    Neighbor* currentNeighbor = _vertex->getNeighbor();

    if (!currentNeighbor)
      return nullptr;
 
    while(currentNeighbor->getNeighbor() && currentNeighbor->getVertex()->getLabel() != _label) {
      currentNeighbor = currentNeighbor->getNeighbor();
    }

    return currentNeighbor;
  }

  void AdjacencyList::generateGraph(std::string _outputFilePath) {
    
  }

  void AdjacencyList::printAdjacencyList() {
    Neighbor* currentNeighbor;

    for (int i=0; i<vertices.size(); i++) {
      std::cout << vertices.at(i)->getLabel() << " -> ";

      currentNeighbor = vertices.at(i)->getNeighbor();
      while(currentNeighbor) {
        std::cout << currentNeighbor->getVertex()->getLabel() << " -> ";
        currentNeighbor = currentNeighbor->getNeighbor();
      }
      std::cout << "nullptr" << std::endl;
    }
  }

void AdjacencyList::log(std::string _message, bool _verbose) {
  if (_verbose){
    std::cout << _message;
  }
}

void AdjacencyList::dijkstra(std::string _rootLabel) {
  std::vector<float> costs;
  std::vector<std::vector<Vertex*>> shortestPaths;

  Vertex* rootVertex = verticalSearch(_rootLabel);
  if (!rootVertex) {
    std::cout << "Label not found!" << std::endl;
    return;
  }

  // Para cada vértice v
  for (int i=0; i<vertices.size(); i++) {
    // Para cada vizinho N de V
    Neighbor* currentNeighbor = vertices.at(i)->getNeighbor();
    while (currentNeighbor) {
      // Adicionar no heap
    }
  }
      // Inserir peso da aresta no heap
    // 
}