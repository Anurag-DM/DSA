class Solution
{
  int solve(vector<int> &prices, int ind, int buy, int limit, vector<vector<vector<int>>> &dp)
  {
    if (ind == prices.size() || limit == 0)
      return 0;

    if (dp[ind][buy][limit] != -1)
      return dp[ind][buy][limit];

    int profit = 0;
    if (buy)
    {
      int buyKaro = -prices[ind] + solve(prices, ind + 1, 0, limit, dp);
      int skipKaro = solve(prices, ind + 1, 1, limit, dp);
      profit = max(buyKaro, skipKaro);
    }
    else
    {
      int sellKaro = prices[ind] + solve(prices, ind + 1, 1, limit - 1, dp);
      int skipKaro = solve(prices, ind + 1, 0, limit, dp);
      profit = max(sellKaro, skipKaro);
    }

    return dp[ind][buy][limit] = profit;
  }

public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(prices, 0, 1, 2, dp);
  }
};