class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int buy = 0; buy < 2; buy++)
      {
        int bought = 0, sold = 0, ignore = 0;
        if (buy == 0)
        {
          bought = -prices[ind] + next[1];
          ignore = next[0];
          curr[buy] = max(bought, ignore);
        }
        else
        {
          sold = prices[ind] + next[0];
          ignore = next[1];
          curr[buy] = max(sold, ignore);
        }
      }
      next = curr;
    }

    return curr[0];
  }
};