#include "Graph.h"

template <class T, class U>
Graph<T, U>::Graph(bool directed)
{
  this->vertices = std::vector<T>();
  this->edges = std::vector<std::vector<std::pair<int, U>>>();
  this->vertices.clear();
  this->edges.clear();
  this->directed = directed;
}

template <class T, class U>
void Graph<T, U>::setVertices(std::vector<T> v)
{
  this->vertices = v;
}

template <class T, class U>
void Graph<T, U>::setEdges(std::vector<std::vector<std::pair<int, U>>> e)
{
  this->edges = e;
}

template <class T, class U>
int Graph<T, U>::edgesCount()
{
  int count = 0;
  for (int i = 0; i < this->edges.size(); i++)
  {
    count += this->edges[i].size();
  }
  return count;
}

template <class T, class U>
bool Graph<T, U>::addVertex(T v)
{
  if (this->findVertex(v) != -1)
  {
    return false;
  }

  this->vertices.push_back(v);
  this->edges.push_back(std::vector<std::pair<int, U>>());
  return true;
}

template <class T, class U>
bool Graph<T, U>::addEdge(T v1, T v2, U weight)
{
  int index1 = this->findVertex(v1);
  int index2 = this->findVertex(v2);

  if (index1 == -1 || index2 == -1)
  {
    return false;
  }

  this->edges[index1].push_back(std::make_pair(index2, weight));

  if (!this->directed)
  {
    this->edges[index2].push_back(std::make_pair(index1, weight));
  }

  return true;
}

template <class T, class U>
int Graph<T, U>::findVertex(T v)
{
  for (int i = 0; i < this->vertices.size(); i++)
  {
    if (this->vertices[i] == v)
    {
      return i;
    }
  }
  return -1;
}

template <class T, class U>
U Graph<T, U>::findEdge(T v1, T v2)
{
  int index1 = this->findVertex(v1);
  int index2 = this->findVertex(v2);

  if (index1 == -1 || index2 == -1)
  {
    return -1;
  }

  for (int i = 0; i < this->edges[index1].size(); i++)
  {
    if (this->edges[index1][i].first == index2)
    {
      return this->edges[index1][i].second;
    }
  }
  return -1;
}

template <class T, class U>
bool Graph<T, U>::deleteVertex(T v)
{
  int index = this->findVertex(v);

  if (index == -1)
  {
    return false;
  }

  this->vertices.erase(this->vertices.begin() + index);
  this->edges.erase(this->edges.begin() + index);

  for (int i = 0; i < this->edges.size(); i++)
  {
    for (int j = 0; j < this->edges[i].size(); j++)
    {
      if (this->edges[i][j].first == index)
      {
        this->edges[i].erase(this->edges[i].begin() + j);
      }
    }
  }
  return true;
}

template <class T, class U>
bool Graph<T, U>::deleteEdge(T v1, T v2)
{
  int index1 = this->findVertex(v1);
  int index2 = this->findVertex(v2);

  if (index1 == -1 || index2 == -1)
  {
    return false;
  }

  for (int i = 0; i < this->edges[index1].size(); i++)
  {
    if (this->edges[index1][i].first == index2)
    {
      this->edges[index1].erase(this->edges[index1].begin() + i);
    }
  }

  if (!this->directed)
  {
    for (int i = 0; i < this->edges[index2].size(); i++)
    {
      if (this->edges[index2][i].first == index1)
      {
        this->edges[index2].erase(this->edges[index2].begin() + i);
      }
    }
  }

  return true;
}

template <class T, class U>
std::vector<std::vector<int>> Graph<T, U>::Prim(T source)
{
  int vertices = this->verticesCount();  // Amount of vertices in the graph
  std::vector<U> weights(vertices, INF); // Creates a vector of costs with INF to be compared
  std::vector<int> predecesors(vertices, -1);
  std::vector<bool> visited(vertices, false); // Vector to keep track of visited vectors, all are false at start

  std::priority_queue<std::pair<int, U>, std::vector<std::pair<int, U>>, std::greater<std::pair<int, U>>> pq;

  int sourceIndex = this->findVertex(source);
  weights[sourceIndex] = 0; // Setting first cost to 0 - Itself

  pq.push({sourceIndex, 0});

  while (!pq.empty())
  {
    int u_index = pq.top().first;
    pq.pop();

    visited[u_index] = true;

    for (int v = 0; v < vertices; v++)
    {
      U u_v_edge = this->findEdge(this->vertices[u_index], this->vertices[v]);
      if (u_v_edge != -1 && !visited[v] && u_v_edge < weights[v])
      {
        weights[v] = u_v_edge;
        pq.push({v, weights[v]});
        predecesors[v] = u_index;
      }
    }
  }

  std::vector<std::vector<int>> mst(vertices);
  for (int i = 0; i < vertices; i++)
  {
    if (predecesors[i] != -1 || i == sourceIndex)
    {
      int vertex = this->vertices[i];
      while (vertex != -1)
      {
        mst[i].push_back(vertex);
        vertex = predecesors[vertex];
      }
    }
  }

  for (int i = 0; i < vertices; i++)
  {
    std::reverse(mst[i].begin(), mst[i].end());
  }

  return mst;
}
