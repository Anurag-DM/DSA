class Solution
{
  int solve(vector<int> &nums, int ind, int d)
  {
    if (ind < 0)
      return 0;

    for (int k = ind - 1; k >= 0; k--)
    {
      if (nums[ind] - nums[k] == d)
        return 1 + solve(nums, k, d);
    }
    return 0;
  }

public:
  int longestArithSeqLength(vector<int> &nums)
  {
    int n = nums.size();
    if (n <= 2)
      return n;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        ans = max(ans, 2 + solve(nums, i, nums[j] - nums[i]));
      }
    }
    return ans;
  }
};