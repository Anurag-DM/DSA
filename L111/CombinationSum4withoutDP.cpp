#include <bits/stdc++.h>
int solve(vector<int> &nums, int tar)
{
  if (tar < 0)
    return 0;
  if (tar == 0)
    return 1;

  int c = 0;
  for (int i : nums)
  {
    c += solve(nums, tar - i);
  }
  return c;
}
int findWays(vector<int> &num, int tar)
{

  return solve(num, tar);
}