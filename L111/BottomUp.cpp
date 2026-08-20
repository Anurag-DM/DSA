#include <bits/stdc++.h>
int findWays(vector<int> &num, int tar)
{
  vector<int> dp(tar + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= tar; i++)
  {
    for (int j : num)
    {
      if (i - j >= 0 && dp[i - j] != 0)
        dp[i] += dp[i - j];
    }
  }
  return dp[tar];
}