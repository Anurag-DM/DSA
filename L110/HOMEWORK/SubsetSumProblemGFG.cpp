class Solution
{
public:
  bool isSubsetSum(vector<int> &nums, int sum)
  {
    // code here
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i : nums)
    {
      for (int j = sum; j >= i; j--)
      {
        dp[j] = dp[j] || dp[j - i];
      }
    }
    return dp[sum];
  }
};

// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1