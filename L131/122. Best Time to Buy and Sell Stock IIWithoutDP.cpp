class Solution
{
  int solve(vector<int> &prices, int ind, int buy)
  {
    if (ind == prices.size())
      return 0;

    int bought = 0, sold = 0, ignore = 0;
    if (buy == 0)
    {
      bought = -prices[ind] + solve(prices, ind + 1, 1);
      ignore = solve(prices, ind + 1, 0);
      return max(bought, ignore);
    }
    else
    {
      sold = prices[ind] + solve(prices, ind+1, 0);
      ignore = solve(prices, ind + 1, 1);
      return max(sold, ignore);
    }
  }

public:
  int maxProfit(vector<int> &prices)
  {
    return solve(prices, 0, 0);
  }
};