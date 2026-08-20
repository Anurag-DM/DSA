// User function Template for C++

class Solution
{
public:
  vector<int> bellmanFord(int n, vector<vector<int>> &edges, int src)
  {
    // Code here
    // User function Template for C++
    int m = edges.size();
    vector<int> dist(n, 1e8);
    dist[src] = 0;

    // step1: update distance by traversing each edge for n-1 times
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
          dist[v] = dist[u] + wt;
      }
    }

    // step2: do 1 more iteration. If distance gets updated then -ve cycle exists and bellman ford algo cant give the shortest path
    bool flag = 0;
    for (int j = 0; j < m; j++)
    {
      int u = edges[j][0];
      int v = edges[j][1];
      int wt = edges[j][2];

      if (dist[u] != 1e8 && dist[u] + wt < dist[v])
        flag = 1;
    }

    if (flag == 0)
      return dist;
    return {-1};
  }
};
