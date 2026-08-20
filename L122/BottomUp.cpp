class Solution
{
public:
  int noOfWays(int m, int n, int x)
  {

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;

    for (int dices = 1; dices <= n; dices++)
    {
      for (int target = 1; target <= x; target++)
      {
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
          if (target - i >= 0)
            ans += dp[dices - 1][target - i];
        }
        dp[dices][target] = ans;
      }
    }
    return dp[n][x];
  }
};