#ifndef VERTEX_H
#define VERTEX_H

#include <string>

class Neighbor;

class Vertex {
  private:
    std::string label;
    Neighbor* neighbor;
    bool hasBeenVisited;

  public:
    Vertex(std::string label);
    ~Vertex();

    void setLabel(std::string label);
    void setNeighbor(Neighbor* neighbor);
    void setHasBeenVisited(bool visited);

    Neighbor* getNeighbor();
    std::string getLabel();
    bool getHasBeenVisited();
};

#endif