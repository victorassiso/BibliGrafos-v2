#include "vertex.h"

Vertex::Vertex(std::string _label) {
  label = _label;
  neighbor = nullptr;
  hasBeenVisited = false;
}

Vertex::~Vertex(){}

void Vertex::setLabel(std::string _label) {
  label = _label;
}

void Vertex::setNeighbor(Neighbor* _neighbor) {
  neighbor = _neighbor;
}

void Vertex::setHasBeenVisited(bool _hasBeenVisited) {
  hasBeenVisited = _hasBeenVisited;
}

Neighbor* Vertex::getNeighbor() {
  return neighbor;
}

std::string Vertex::getLabel() {
  return label;
}

bool Vertex::getHasBeenVisited() {
  return hasBeenVisited;
}
