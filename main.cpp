#include "list/list.h"

#include <iostream>

int main() {
  AdjacencyList adjacencyList;
  adjacencyList.read("input/g1.txt");
  adjacencyList.printAdjacencyList();
}