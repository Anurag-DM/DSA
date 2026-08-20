class Solution
{
  int solve(vector<int> &cost, int n, vector<int> &dp)
  {
    if (n <= 1)
      return cost[n];

    // step3
    if (dp[n] != -1)
      return dp[n];

    // step2
    dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return dp[n];
  }

public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    int n = cost.size();

    // step1
    vector<int> dp(n, -1);

    int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return ans;
  }
};