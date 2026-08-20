class Solution
{
  int solve(int ind, int noOfOperations, int k, vector<int> &prices)
  {
    if (ind == prices.size() || noOfOperations == 2 * k)
      return 0;

    int profit = 0;
    if (noOfOperations % 2 == 0)
    {
      int buyKaro = -prices[ind] + solve(ind + 1, noOfOperations + 1, k, prices);
      int skipKaro = solve(ind + 1, noOfOperations, k, prices);
      profit = max(buyKaro, skipKaro);
    }
    else
    {
      int sellKaro = prices[ind] + solve(ind + 1, noOfOperations + 1, k, prices);
      int skipKaro = solve(ind + 1, noOfOperations, k, prices);
      profit = max(sellKaro, skipKaro);
    }
    return profit;
  }

public:
  int maxProfit(int k, vector<int> &prices)
  {
    return solve(0, 0, k, prices);
  }
};