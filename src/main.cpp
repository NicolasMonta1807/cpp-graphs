#include <iostream>
#include "Graph.h"

int main()
{
  Graph<int, float> g(false);

  g.addVertex(0);
  g.addVertex(1);
  g.addVertex(2);
  g.addVertex(3);
  g.addVertex(4);
  g.addVertex(5);
  g.addVertex(6);
  g.addVertex(7);

  g.addEdge(0, 1, 45);
  g.addEdge(0, 2, 32.01);
  g.addEdge(0, 3, 35.355);

  g.addEdge(1, 3, 32.015);
  g.addEdge(1, 4, 25);
  g.addEdge(1, 5, 32.015);

  g.addEdge(2, 6, 32.015);
  g.addEdge(2, 3, 45);

  g.addEdge(3, 6, 35.355);
  g.addEdge(3, 4, 20);
  g.addEdge(3, 7, 32.015);

  g.addEdge(4, 7, 25);
  g.addEdge(4, 5, 20);

  g.addEdge(5, 7, 32.015);

  g.addEdge(6, 7, 45);

  std::vector<std::vector<int>> prim = g.Prim(0);

  std::cout << "Prim MST from 0:" << std::endl;
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

  std::vector<std::vector<int>> paths = g.Dijkstra(0);
  std::cout << "Dijkstra from 5:" << std::endl;
  for (int i = 0; i < paths.size(); i++)
  {
    std::cout << i << ": ";
    for (int j = 0; j < paths[i].size(); j++)
    {
      if (j == paths[i].size() - 1)
        std::cout << paths[i][j];
      else
        std::cout << paths[i][j] << " - ";
    }
    std::cout << std::endl;
  }
}