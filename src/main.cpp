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

  Graph<int, int> h(false);

  h.addVertex(0);
  h.addVertex(1);
  h.addVertex(2);
  h.addVertex(3);
  h.addVertex(4);
  h.addVertex(5);
  h.addVertex(6);
  h.addVertex(7);

  h.addEdge(5, 3, 4);
  h.addEdge(3, 1, 2);
  h.addEdge(3, 0, 3);
  h.addEdge(1, 0, 5);
  h.addEdge(0, 2, 6);
  h.addEdge(2, 4, 6);
  h.addEdge(4, 6, 7);
  h.addEdge(6, 7, 3);
  h.addEdge(4, 7, 3);

  std::vector<std::vector<int>> paths = h.Dijkstra(5);
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