#ifndef __GRAPH__
#define __GRAPH__

#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define INF 9999999

template <class T, class U>
class Graph
{
private:
  std::vector<T> vertices;
  std::vector<std::vector<std::pair<int, U>>> edges;
  bool directed;

public:
  Graph(bool directed);
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
  std::vector<std::vector<int>> Prim(T source);
  std::vector<std::vector<int>> Dijkstra(T source);
};

#include "Graph.hxx"

#endif // __GRAPH__