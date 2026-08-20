#include <unordered_map>
#include <list>
#include <stack>

void dfs(int node, stack<int> &st, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
  vis[node] = true;
  for (int nbr : adj[node])
  {
    if (!vis[nbr])
      dfs(nbr, st, adj, vis);
  }
  st.push(node);
}

void revDfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
  vis[node] = true;
  for (int nbr : adj[node])
  {
    if (!vis[nbr])
      revDfs(nbr, adj, vis);
  }
}
int stronglyConnectedComponents(int V, vector<vector<int>> &edges)
{
  // adj list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
  }

  unordered_map<int, bool> vis;

  // step1: topo sort
  stack<int> st;
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      dfs(i, st, adj, vis);
    }
  }

  // step2:transpose the graph
  unordered_map<int, list<int>> transpose;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    transpose[v].push_back(u);
  }

  // make the vis back to false for all vertices
  for (int i = 0; i < V; i++)
  {
    vis[i] = 0;
  }

  // step3: perform dfs on this transpose graph using stack order
  int count = 0;
  while (!st.empty())
  {
    int top = st.top();
    st.pop();
    if (!vis[top])
    {
      revDfs(top, transpose, vis);
      count++;
    }
  }
  return count;
}