class Solution
{
public:
  vector<int> minMaxCandy(vector<int> &prices, int k)
  {
    sort(prices.begin(), prices.end());

    vector<int> ans(2);
    int n = prices.size();

    // minimum case
    int i = 0, j = n - 1;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
      total += prices[i];
      j -= k;
      if (j <= i)
        break;
    }

    ans[0] = total;

    // max case
    i = n - 1;
    j = 0;
    total = 0;

    for (int i = n - 1; i >= 0; i--)
    {
      total += prices[i];
      j += k;
      if (j >= i)
        break;
    }
    ans[1] = total;

    return ans;
  }
};