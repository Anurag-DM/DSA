class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    int sum = 0;
    for (int i : nums)
      sum += i;

    if (sum % 2 == 1)
      return 0;

    int target = sum / 2;
    vector<bool> dp(target + 1, 0);
    dp[0] = true; // dp[j]=true means u can make a target of j

    for (int i : nums)
    {
      for (int j = target; j >= i; j--)
      {
        dp[j] = dp[j] || dp[j - i];
      }
    }

    return dp[target];
  }
};