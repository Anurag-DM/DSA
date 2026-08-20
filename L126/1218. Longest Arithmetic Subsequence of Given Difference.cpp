//Time: O(n²) Space: O(n)
class Solution
{
public:
  int longestSubsequence(vector<int> &arr, int difference)
  {
    int n = arr.size();
    if (n <= 1)
      return n;

    vector<int> dp(n, 1); // every element itself = length 1
    int ans = 1;

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (arr[i] - arr[j] == difference)
        {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};