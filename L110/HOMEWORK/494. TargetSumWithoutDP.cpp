class Solution
{
  int solve(vector<int> &nums, int ind, int target)
  {
    if (ind == nums.size())
    {
      if (target == 0)
        return 1;
      else
        return 0;
    }

    int add = solve(nums, ind + 1, target - nums[ind]);
    int sub = solve(nums, ind + 1, target + nums[ind]);
    return add + sub;
  }

public:
  int findTargetSumWays(vector<int> &nums, int target)
  {

    return solve(nums, 0, target);
  }
};