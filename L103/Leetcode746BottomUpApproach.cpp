class Solution
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    int n = cost.size();

    // step1: create dp array
    vector<int> dp(n);

    // step2: base case analysis
    dp[0] = cost[0];
    dp[1] = cost[1];

    // step3
    for (int i = 2; i < n; i++)
      dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);

    return min(dp[n - 1], dp[n - 2]);
  }
};