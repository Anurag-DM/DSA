#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &nums)
{
  // Write your code here.
  int n = nums.size();
  // step1
  vector<int> dp(n, -1);

  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);
  for (int i = 2; i < n; i++)
  {
    int incl = dp[i - 2] + nums[i];
    int excl = dp[i - 1] + 0;
    dp[i] = max(incl, excl);
  }
  return dp[n - 1];
}