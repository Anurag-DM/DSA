class Solution
{
  int solve(int dices, int faces, int target, vector<vector<int>> &dp)
  {
    // base cases
    if (target < 0)
      return 0;
    if (dices == 0 && target != 0)
      return 0;
    if (dices != 0 && target == 0)
      return 0;
    if (dices == 0 && target == 0)
      return 1;

    if (dp[dices][target] != -1)
      return dp[dices][target];

    int ans = 0;
    for (int i = 1; i <= faces; i++)
    {
      ans += solve(dices - 1, faces, target - i, dp);
    }
    return dp[dices][target] = ans;
  }

public:
  int noOfWays(int m, int n, int x)
  {
    // code here
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    return solve(n, m, x, dp);
  }
};