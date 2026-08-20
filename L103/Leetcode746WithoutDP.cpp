class Solution
{
  int solve(vector<int> &cost, int n)
  {
    if (n == 0)
      return cost[0];
    if (n == 1)
      return cost[1];
    int ans = min(solve(cost, n - 1), solve(cost, n - 2)) + cost[n];
    return ans;
  }

public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    int n = cost.size();
    return min(solve(cost, n - 1), solve(cost, n - 2));
  }
};