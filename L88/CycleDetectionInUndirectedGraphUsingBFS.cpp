#include <unordered_map>
#include <queue>
#include <list>
void bfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node,
         bool &ans, unordered_map<int, int> &parent)
{
  queue<int> q;
  q.push(node);
  visited[node] = true;
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    for (auto i : adj[front])
    {
      if (!visited[i])
      {
        q.push(i);
        visited[i] = true;
        parent[i] = front;
      }
      else
      {
        if (parent[front] != i)
        {
          ans = true;
          return;
        }
      }
    }
  }
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
  // Write your code here.
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < m; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  unordered_map<int, bool> visited(n + 1);
  bool ans = false;
  unordered_map<int, int> parent;
  for (int i = 1; i <= n; i++)
  {
    if (ans == true)
      break;
    if (!visited[i])
    {
      parent[i] = -1;
      bfs(adj, visited, i, ans, parent);
    }
  }
  if (ans)
    return "Yes";
  else
    return "No";
}
