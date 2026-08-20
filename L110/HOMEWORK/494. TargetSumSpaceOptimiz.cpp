class Solution
{
public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    int n = nums.size();
    int offset = 1000;

    vector<int> dp(2001, 0);
    dp[offset] = 1;

    for (int i = 0; i < n; i++)
    {
      int element = nums[i];
      vector<int> next(2001, 0); // ✅ new array

      for (int t = -1000; t <= 1000; t++)
      {
        if (dp[t + offset] != 0)
        {
          int count = dp[t + offset];

          if (t + element <= 1000)
            next[t + element + offset] += count;

          if (t - element >= -1000)
            next[t - element + offset] += count;
        }
      }

      dp = next; // move to next state
    }

    return dp[target + offset];
  }
};