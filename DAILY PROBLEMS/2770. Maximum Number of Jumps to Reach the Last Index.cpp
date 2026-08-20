// DP
class Solution
{
  int solve(vector<int> &nums, int target, int ind, vector<int> &dp)
  {

    if (ind == nums.size() - 1)
      return 0;

    if (dp[ind] != -2)
      return dp[ind];

    int maxi = -1;
    for (int i = ind + 1; i < nums.size(); i++)
    {
      if (abs(nums[ind] - nums[i]) <= target)
      {
        int jump = solve(nums, target, i, dp);

        if (jump != -1)
          maxi = max(maxi, 1 + jump);
      }
    }
    return dp[ind] = maxi;
  }

public:
  int maximumJumps(vector<int> &nums, int target)
  {
    vector<int> dp(nums.size(), -2);
    return solve(nums, target, 0, dp);
  }
};

/* Without DP
class Solution
{
  int solve(vector<int> &nums, int target, int ind)
  {

    if (ind == nums.size() - 1)
      return 0;

    int maxi = -1;
    for (int i = ind + 1; i < nums.size(); i++)
    {
      if (abs(nums[ind] - nums[i]) <= target)
      {
        int jump = solve(nums, target, i);

        if (jump != -1)
          maxi = max(maxi, 1 + jump);
      }
    }
    return maxi;
  }

public:
  int maximumJumps(vector<int> &nums, int target)
  {
    return solve(nums, target, 0);
  }
};*/