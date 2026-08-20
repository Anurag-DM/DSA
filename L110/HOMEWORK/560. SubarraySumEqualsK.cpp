//this will TLE
class Solution
{
  int solve(vector<int> &nums, int sum, int k, int ind)
  {
    if (ind == nums.size())
      return 0;

    sum += nums[ind];
    if (sum == k)
      return 1 + solve(nums, sum, k, ind + 1);
    else
      return 0 + solve(nums, sum, k, ind + 1);
  }

public:
  int subarraySum(vector<int> &nums, int k)
  {
    int n = nums.size();
    int c = 0;
    for (int i = 0; i < n; i++)
    {

      c += solve(nums, 0, k, i);
    }
    return c;
  }
};