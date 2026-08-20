#include <bits/stdc++.h>

void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node, stack<int> &s)
{
  visited[node] = true;
  for (auto i : adj[node])
  {
    if (!visited[i])
    {
      dfs(adj, visited, i, s);
    }
  }
  s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < e; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
  }
  stack<int> s;
  unordered_map<int, bool> visited;
  for (int i = 0; i < v; i++)
  {
    if (!visited[i])
      dfs(adj, visited, i, s);
  }
  vector<int> ans;
  while (!s.empty())
  {
    ans.push_back(s.top());
    s.pop();
  }
  return ans;
}