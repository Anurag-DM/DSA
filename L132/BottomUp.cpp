class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int buy = 0; buy < 2; buy++)
      {
        for (int limit = 1; limit <= 2; limit++)
        {
          int profit = 0;
          if (buy)
          {
            int buyKaro = -prices[ind] + dp[ind + 1][0][limit];
            int skipKaro = dp[ind + 1][1][limit];
            profit = max(buyKaro, skipKaro);
          }
          else
          {
            int sellKaro = prices[ind] + dp[ind + 1][1][limit - 1];
            int skipKaro = dp[ind + 1][0][limit];
            profit = max(sellKaro, skipKaro);
          }

          dp[ind][buy][limit] = profit;
        }
      }
    }
    return dp[0][1][2];
  }
};