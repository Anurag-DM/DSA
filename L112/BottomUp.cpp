class Solution
{
public:
  int minSquares(int n)
  {
    // Code here
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
      int c = INT_MAX;
      for (int j = 1; j * j <= i; j++)
      {
        c = min(c, dp[i - j * j] + 1);
      }
      dp[i] = c;
    }
    return dp[n];
  }
};