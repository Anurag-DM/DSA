class Solution
{
  int solve(int start, int end, vector<vector<int>> &dp)
  {
    if (start >= end)
      return 0;

    if (dp[start][end] != -1)
      return dp[start][end];

    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
      int left = solve(start, i - 1, dp);
      int right = solve(i + 1, end, dp);

      ans = min(ans, i + max(left, right));
    }
    return dp[start][end] = ans;
  }

public:
  int getMoneyAmount(int n)
  {
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int step = 1; step <= n; step++)
    {
      for (int start = 1; start + step <= n; start++)
      {
        int end = start + step;
        int ans = INT_MAX;
        for (int i = start; i <= end; i++)
        {
          int left = dp[start][i - 1];
          int right = dp[i + 1][end];

          ans = min(ans, i + max(left, right));
        }
        dp[start][end] = ans;
      }
    }
    return dp[1][n];
  }
};