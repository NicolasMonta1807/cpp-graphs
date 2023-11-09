#ifndef __GRAPH__
#define __GRAPH__

#include <vector>
#include <utility>

template <class T, class U>
class Graph
{
private:
  std::vector<T> vertices;
  std::vector<std::vector<std::pair<int, U>>> edges;

public:
  Graph();
  void setVertices(std::vector<T> v);
  void setEdges(std::vector<std::vector<std::pair<int, U>>> e);
  std::vector<T> getVertices() { return vertices; };
  std::vector<std::vector<std::pair<int, U>>> getEdges() { return edges; };
  int verticesCount() { return vertices.size(); };
  int edgesCount();
  bool addVertex(T v);
  bool addEdge(T v1, T v2, U weight);
  int findVertex(T v);
  U findEdge(T v1, T v2);
  bool deleteVertex(T v);
  bool deleteEdge(T v1, T v2);
};

#include "Graph.hxx"

#endif // __GRAPH__