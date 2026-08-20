#include <bits/stdc++.h>
int solve(vector<int> &nums, int index, vector<int> &dp)
{
  if (index < 0)
    return 0;
  if (index == 0)
    return nums[0];

  // step3:
  if (dp[index] != -1)
    return dp[index];

  int incl = solve(nums, index - 2, dp) + nums[index];
  int excl = solve(nums, index - 1, dp) + 0;

  // step2:
  dp[index] = max(incl, excl);
  return dp[index];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
  int n = nums.size();
  // step 1:
  vector<int> dp(n, -1);
  int ans = solve(nums, n - 1, dp);
  return ans;
}