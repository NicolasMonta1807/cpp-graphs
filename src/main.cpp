#include <iostream>
#include "Graph.h"

int main()
{
  Graph<int, int> g(false);

  g.addVertex(0);
  g.addVertex(1);
  g.addVertex(2);
  g.addVertex(3);
  g.addVertex(4);
  g.addVertex(5);
  g.addVertex(6);

  g.addEdge(0, 1, 3);
  g.addEdge(0, 3, 2);
  g.addEdge(0, 2, 7);
  g.addEdge(2, 5, 3);
  g.addEdge(2, 6, 9);
  g.addEdge(2, 4, 6);
  g.addEdge(4, 6, 9);

  std::vector<std::vector<int>> prim = g.Prim(5);

  std::cout << "Prim MST from 5:" << std::endl;
  for (int i = 0; i < prim.size(); i++)
  {
    std::cout << i << ": ";
    for (int j = 0; j < prim[i].size(); j++)
    {
      if (j == prim[i].size() - 1)
        std::cout << prim[i][j];
      else
        std::cout << prim[i][j] << " - ";
    }
    std::cout << std::endl;
  }
}