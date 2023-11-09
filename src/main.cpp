#include <iostream>
#include "Graph.h"

int main()
{
  Graph<int, int> g;

  g.addVertex(1);
  g.addVertex(2);
  g.addVertex(3);

  g.addEdge(1, 2, 10);
  g.addEdge(2, 3, 20);
  g.addEdge(3, 1, 30);

  std::cout << "Vertices: " << g.verticesCount() << std::endl;
  std::cout << "Edges: " << g.edgesCount() << std::endl;
}