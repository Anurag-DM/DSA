class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int prev = ind - 1; prev >= -1; prev--)
      {
        // include
        int inc = 0;
        if (prev == -1 || nums[ind] > nums[prev])
          inc = 1 + dp[ind + 1][ind + 1];

        // exclude
        int exc = 0 + dp[ind + 1][prev + 1];

        dp[ind][prev + 1] = max(inc, exc);
      }
    }
    return dp[0][-1 + 1];
  }
};