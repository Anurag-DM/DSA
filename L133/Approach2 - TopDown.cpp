class Solution
{
  int solve(int ind, int noOfOperations, int k, vector<int> &prices, vector<vector<int>> &dp)
  {
    if (ind == prices.size() || noOfOperations == 2 * k)
      return 0;

    if (dp[ind][noOfOperations] != -1)
      return dp[ind][noOfOperations];

    int profit = 0;
    if (noOfOperations % 2 == 0)
    {
      int buyKaro = -prices[ind] + solve(ind + 1, noOfOperations + 1, k, prices, dp);
      int skipKaro = solve(ind + 1, noOfOperations, k, prices, dp);
      profit = max(buyKaro, skipKaro);
    }
    else
    {
      int sellKaro = prices[ind] + solve(ind + 1, noOfOperations + 1, k, prices, dp);
      int skipKaro = solve(ind + 1, noOfOperations, k, prices, dp);
      profit = max(sellKaro, skipKaro);
    }
    return dp[ind][noOfOperations] = profit;
  }

public:
  int maxProfit(int k, vector<int> &prices)
  {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    return solve(0, 0, k, prices, dp);
  }
};