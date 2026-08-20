class Solution
{
public:
  vector<int> topoSort(int n, vector<vector<int>> &edges)
  {
    int m = edges.size();
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];

      adj[u].push_back(v);
    }
    vector<int> ans;
    vector<int> indegree(n, 0);

    for (auto i : adj)
    {
      for (auto j : i.second)
      {
        indegree[j]++;
      }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }

    while (!q.empty())
    {
      int front = q.front();
      q.pop();
      ans.push_back(front);
      for (auto i : adj[front])
      {
        indegree[i]--;
        if (indegree[i] == 0)
          q.push(i);
      }
    }

    return ans;
  }
};