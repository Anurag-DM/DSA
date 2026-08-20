class Solution
{
  int solve(vector<int> &prices, int ind, int buy, int limit)
  {
    if (ind == prices.size() || limit == 0)
      return 0;

    int profit = 0;
    if (buy)
    {
      int buyKaro = -prices[ind] + solve(prices, ind + 1, 0, limit);
      int skipKaro = solve(prices, ind + 1, 1, limit);
      profit = max(buyKaro, skipKaro);
    }
    else
    {
      int sellKaro = prices[ind] + solve(prices, ind + 1, 1, limit - 1);
      int skipKaro = solve(prices, ind + 1, 0, limit);
      profit = max(sellKaro, skipKaro);
    }

    return profit;
  }

public:
  int maxProfit(vector<int> &prices)
  {
    return solve(prices, 0, 1, 2);
  }
};