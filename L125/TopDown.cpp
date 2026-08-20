// still tle as O(n^3)
class Solution
{
  int solve(vector<int> &nums, int ind, int d, unordered_map<int, int> *dp)
  {
    if (ind < 0)
      return 0;

    if (dp[ind].count(d))
      return dp[ind][d];

    for (int k = ind - 1; k >= 0; k--)
    {
      if (nums[ind] - nums[k] == d)
        return dp[ind][d] = 1 + solve(nums, k, d, dp);
    }
    return 0;
  }

public:
  int longestArithSeqLength(vector<int> &nums)
  {
    int n = nums.size();
    if (n <= 2)
      return n;

    unordered_map<int, int> dp[n]; // key of map represents the diff, the value represents the max length for that diff and index i which is in turn handled by dp[i].
    int ans = 2;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        ans = max(ans, 2 + solve(nums, i, nums[j] - nums[i], dp));
      }
    }
    return ans;
  }
};