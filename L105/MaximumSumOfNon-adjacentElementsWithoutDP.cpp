#include <bits/stdc++.h>
int solve(vector<int> &nums, int index)
{
  if (index < 0)
    return 0;
  if (index == 0)
    return nums[0];

  int incl = solve(nums, index - 2) + nums[index];
  int excl = solve(nums, index - 1) + 0;

  return max(incl, excl);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
  int n = nums.size();
  int ans = solve(nums, n - 1);
  return ans;
}