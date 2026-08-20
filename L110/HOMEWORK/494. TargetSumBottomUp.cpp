class Solution
{
public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    int n = nums.size();
    int offset = 1000;
    vector<vector<int>> dp(n + 1, vector<int>(2001, 0));
    dp[0][offset] = 1; // dp[i][j] means i no of elements are required to get target j+offset

    for (int i = 1; i <= n; i++)
    {
      int element = nums[i - 1];
      for (int t = -1000; t <= 1000; t++)
      {
        if (dp[i - 1][t + offset] != 0)
        {
          int count = dp[i - 1][t + offset];
          if (t + element <= 1000)
            dp[i][t + element + offset] += count;
          if (t - element >= -1000)
            dp[i][t - element + offset] += count;
        }
      }
    }
    return dp[n][target + offset];
  }
};