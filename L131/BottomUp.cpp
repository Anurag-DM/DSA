class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int buy = 0; buy < 2; buy++)
      {
        int bought = 0, sold = 0, ignore = 0;
        if (buy == 0)
        {
          bought = -prices[ind] + dp[ind + 1][1];
          ignore = dp[ind + 1][0];
          dp[ind][buy] = max(bought, ignore);
        }
        else
        {
          sold = prices[ind] + dp[ind + 1][0];
          ignore = dp[ind + 1][1];
          dp[ind][buy] = max(sold, ignore);
        }
      }
    }

    return dp[0][0];
  }
};