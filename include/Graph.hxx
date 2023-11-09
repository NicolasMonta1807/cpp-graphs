#include "Graph.h"

template <class T, class U>
Graph<T, U>::Graph()
{
  this->vertices = std::vector<T>();
  this->edges = std::vector<std::vector<std::pair<int, U>>>();
  this->vertices.clear();
  this->edges.clear();
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

  for (int i = 0; i < this->edges[index2].size(); i++)
  {
    if (this->edges[index2][i].first == index1)
    {
      this->edges[index2].erase(this->edges[index2].begin() + i);
    }
  }
  return true;
}