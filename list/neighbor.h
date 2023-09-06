#ifndef NEIGHBOR_H
#define NEIGHBOR_H

class Vertex;

class Neighbor {
  private:
    Vertex* vertex;
    Neighbor* neighbor;
    float weight;

  public:
    Neighbor(Vertex* vertex, float weight);
    ~Neighbor();

    void setWeight(float weight);
    void setNeighbor(Neighbor* neighbor);

    Vertex* getVertex();
    Neighbor* getNeighbor();
    float getWeight();
};

#endif