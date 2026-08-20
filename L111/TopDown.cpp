#include <bits/stdc++.h>
int solve(vector<int> &nums, int tar, vector<int> &dp)
{
  if (tar < 0)
    return 0;
  if (tar == 0)
    return 1;

  if (dp[tar] != -1)
    return dp[tar];

  int c = 0;
  for (int i : nums)
  {
    c += solve(nums, tar - i, dp);
  }
  dp[tar] = c;
  return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
  vector<int> dp(tar + 1, -1);
  return solve(num, tar, dp);
}