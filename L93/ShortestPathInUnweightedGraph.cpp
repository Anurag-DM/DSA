#include <unordered_map>
#include <list>
#include <queue>
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < m; i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<bool> visited(n + 1, 0);
  vector<int> parent(n + 1, 0);
  queue<int> q;

  q.push(s);
  visited[s] = 1;
  parent[s] = -1;
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    for (auto i : adj[front])
    {
      if (!visited[i])
      {
        q.push(i);
        parent[i] = front;
        visited[i] = 1;
      }
    }
  }
  vector<int> ans;
  int dest = t;
  while (dest != -1)
  {
    ans.push_back(dest);
    dest = parent[dest];
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
