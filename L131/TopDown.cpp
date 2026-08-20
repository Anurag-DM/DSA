// Time: O(n) Space: O(n)
class Solution
{
  int solve(vector<int> &prices, int ind, int buy, vector<vector<int>> &dp)
  {
    if (ind == prices.size())
      return 0;

    if (dp[ind][buy] != -1)
      return dp[ind][buy];

    int bought = 0, sold = 0, ignore = 0;
    if (buy == 0)
    {
      bought = -prices[ind] + solve(prices, ind + 1, 1, dp);
      ignore = solve(prices, ind + 1, 0, dp);
      return dp[ind][buy] = max(bought, ignore);
    }
    else
    {
      sold = prices[ind] + solve(prices, ind + 1, 0, dp);
      ignore = solve(prices, ind + 1, 1, dp);
      return dp[ind][buy] = max(sold, ignore);
    }
  }

public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(prices, 0, 0, dp);
  }
};