class Solution
{
  int solve(int n, vector<int> &dp)
  {
    if (n == 0)
      return 0;

    if (dp[n] != -1)
      return dp[n];

    int c = n; //in worst case n no of 1s used to build n
    for (int i = 1; i * i <= n; i++)
    {
      c = min(c, solve(n - i * i, dp) + 1);
    }
    return dp[n] = c;
  }

public:
  int minSquares(int n)
  {
    // Code here
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
  }
};