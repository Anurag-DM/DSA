#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &nums)
{
  // Write your code here.
  int n = nums.size();

  int prev2 = nums[0];
  int prev1 = max(nums[0], nums[1]);
  for (int i = 2; i < n; i++)
  {
    int incl = prev2 + nums[i];
    int excl = prev1 + 0;
    int curr = max(incl, excl);
    prev2 = prev1;
    prev1 = curr;
  }
  return prev1;
}