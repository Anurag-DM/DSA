#include <list>
#include <unordered_map>

void dfs(int node, int &timer, vector<int> &discovery, vector<int> &low, int parent, unordered_map<int, bool> &visited, vector<vector<int>> &result, unordered_map<int, list<int>> &adj)
{
  visited[node] = true;
  discovery[node] = low[node] = timer++;

  for (auto nbr : adj[node])
  {
    if (nbr == parent)
      continue;
    if (!visited[nbr])
    {
      dfs(nbr, timer, discovery, low, node, visited, result, adj);
      low[node] = min(low[node], low[nbr]);

      // check for bridge
      if (low[nbr] > discovery[node])
      {
        vector<int> ans;
        ans.push_back(node);
        ans.push_back(nbr);
        result.push_back(ans);
      }
    }
    else
    {
      // neighbor is visited but not the parent
      // this is back edge
      low[node] = min(low[node], discovery[nbr]);
    }
  }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
  unordered_map<int, list<int>> adj;
  // adj list
  for (int i = 0; i < e; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int timer = 0;
  vector<int> discovery(v, -1);
  vector<int> low(v, -1);
  int parent = -1;
  unordered_map<int, bool> visited;
  vector<vector<int>> result;

  for (int i = 0; i < v; i++)
  {
    if (!visited[i])
    {
      dfs(i, timer, discovery, low, parent, visited, result, adj);
    }
  }

  return result;
}