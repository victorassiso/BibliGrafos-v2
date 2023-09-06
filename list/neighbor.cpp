#include "neighbor.h"

  Neighbor::Neighbor(Vertex* _vertex, float _weight) {
    vertex = _vertex;
    neighbor = nullptr;
    weight = _weight;
  }

  Neighbor::~Neighbor() {}

  void Neighbor::setWeight(float _weight) {
    weight = _weight;
  }

  void Neighbor::setNeighbor(Neighbor* _neighbor) {
    neighbor = _neighbor;
  }

  Vertex* Neighbor::getVertex() {
    return vertex;
  }

  Neighbor* Neighbor::getNeighbor() {
    return neighbor;
  }

  float Neighbor::getWeight() {
    return weight;
  }