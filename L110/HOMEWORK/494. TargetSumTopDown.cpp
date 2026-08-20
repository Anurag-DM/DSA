class Solution
{
  int solve(vector<int> &nums, int ind, int target, vector<vector<int>> &dp)
  {
    if (ind == nums.size())
    {
      if (target == 0)
        return 1;
      else
        return 0;
    }

    if (dp[ind][target + 2000] != -1)
      return dp[ind][target + 2000];

    int add = solve(nums, ind + 1, target - nums[ind], dp);
    int sub = solve(nums, ind + 1, target + nums[ind], dp);
    return dp[ind][target + 2000] = add + sub;
  }

public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(4001, -1));
    return solve(nums, 0, target, dp);
  }
};