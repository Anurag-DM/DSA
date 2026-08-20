class Solution
{
public:
  int maxProfit(int k, vector<int> &prices)
  {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int noOfOperations = 0; noOfOperations < 2 * k; noOfOperations++)
      {
        int profit = 0;
        if (noOfOperations % 2 == 0)
        {
          int buyKaro = -prices[ind] + dp[ind + 1][noOfOperations + 1];
          int skipKaro = dp[ind + 1][noOfOperations];
          profit = max(buyKaro, skipKaro);
        }
        else
        {
          int sellKaro = prices[ind] + dp[ind + 1][noOfOperations + 1];
          int skipKaro = dp[ind + 1][noOfOperations];
          profit = max(sellKaro, skipKaro);
        }
        dp[ind][noOfOperations] = profit;
      }
    }
    return dp[0][0];
  }
};