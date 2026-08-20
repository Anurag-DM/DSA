// this is same q as L132 just instead of 2 transaction here k transaction. below is the space optimized bottom up approach code copied from L132

// time O(nk)  space O(k)
class Solution
{
public:
  int maxProfit(int k, vector<int> &prices)
  {
    int n = prices.size();

    vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    vector<vector<int>> next(2, vector<int>(k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int buy = 0; buy < 2; buy++)
      {
        for (int limit = 1; limit <= k; limit++)
        {
          int profit = 0;
          if (buy)
          {
            int buyKaro = -prices[ind] + next[0][limit];
            int skipKaro = next[1][limit];
            profit = max(buyKaro, skipKaro);
          }
          else
          {
            int sellKaro = prices[ind] + next[1][limit - 1];
            int skipKaro = next[0][limit];
            profit = max(sellKaro, skipKaro);
          }

          curr[buy][limit] = profit;
        }
      }
      next = curr;
    }
    return curr[1][k];
  }
};