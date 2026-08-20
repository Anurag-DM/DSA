#define MOD 1000000007
class Solution
{
  int solve(int e, long long sum, vector<int> &dp)
  {
    if (e == 0)
    {
      if (sum % 2 == 1)
        return 1;
      else
        return 0;
    }

    if (dp[e] != -1)
      return dp[e];

    int op1 = solve(e - 1, sum + 1, dp);
    int op2 = solve(e - 1, sum + 2, dp);

    return dp[e] = (op1 + op2) % MOD;
  }

public:
  int assignEdgeWeights(vector<vector<int>> &edges)
  {
    unordered_map<int, vector<int>> adj;

    int n = edges.size() + 1;

    for (auto &i : edges)
    {
      int u = i[0];
      int v = i[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);

    queue<int> q;
    q.push(1);
    q.push(-1);

    int depth = 0;
    while (!q.empty())
    {
      int front = q.front();
      q.pop();

      if (front != -1)
      {
        visited[front] = true;
        for (int i : adj[front])
        {
          if (!visited[i])
            q.push(i);
        }
      }
      else
      {
        if (!q.empty())
        {
          q.push(-1);
          depth++;
        }
      }
    }

    vector<int> dp(depth + 1, -1);
    int ans = solve(depth, 0, dp);
    return ans;
  }
};