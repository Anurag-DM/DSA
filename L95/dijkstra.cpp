#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{

  // adjacency list: node -> {neighbor, weight}
  unordered_map<int, list<pair<int, int>>> adj;

  for (int i = 0; i < edges; i++)
  {
    int u = vec[i][0];
    int v = vec[i][1];
    int w = vec[i][2];

    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); // remove if graph is directed
  }

  vector<int> dist(vertices, INT_MAX);
  dist[source] = 0;

  // {distance, node}
  set<pair<int, int>> s;
  s.insert({0, source});

  while (!s.empty())
  {

    auto top = *s.begin();
    s.erase(s.begin());

    int nodeDistance = top.first;
    int node = top.second;

    for (auto neighbor : adj[node])
    {

      int nbr = neighbor.first;
      int weight = neighbor.second;

      if (nodeDistance + weight < dist[nbr])
      {

        // remove old pair if exists
        auto it = s.find({dist[nbr], nbr});
        if (it != s.end())
          s.erase(it);

        // update distance
        dist[nbr] = nodeDistance + weight;

        // insert new pair
        s.insert({dist[nbr], nbr});
      }
    }
  }

  return dist;
}