class Solution
{
public:
  int longestArithSeqLength(vector<int> &nums)
  {
    int n = nums.size();
    if (n <= 2)
      return n;

    vector<unordered_map<int, int>> dp(n);

    int ans = 2;
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        int d = nums[i] - nums[j];

        // If there’s already an AP ending at j with diff d we extend it Else start a new AP of length 2
        int len = 1;

        if (dp[j].count(d))
          len = dp[j][d];

        dp[i][d] = 1 + len;
        ans = max(ans, dp[i][d]);
      }
    }
    return ans;
  }
};