// time O(n)  space: O(1)
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();

    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int buy = 0; buy < 2; buy++)
      {
        for (int limit = 1; limit <= 2; limit++)
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
    return curr[1][2];
  }
};