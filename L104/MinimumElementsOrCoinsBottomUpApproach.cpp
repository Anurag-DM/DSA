#include <bits/stdc++.h>
int minimumElements(vector<int> &num, int x)
{
  vector<int> dp(x + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i <= x; i++)
  {
    for (int j : num)
    {
      if (i - j >= 0 && dp[i - j] != INT_MAX)
      {
        dp[i] = min(dp[i], 1 + dp[i - j]);
      }
    }
  }
  if (dp[x] == INT_MAX)
    return -1;
  return dp[x];
}
// space optimization cant be done further