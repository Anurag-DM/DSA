// Time Complexity = O(n³)
// Recursion Stack Maximum depth = n (worst case skewed calls)👉 O(n)
// Total Space O(n2)+O(n)≈O(n2)

class Solution
{
  int solve(int start, int end, vector<vector<int>> &dp)
  {
    if (start >= end)
      return 0;

    if (dp[start][end] != -1)
      return dp[start][end];

    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
      int left = solve(start, i - 1, dp);
      int right = solve(i + 1, end, dp);

      ans = min(ans, i + max(left, right));
    }
    return dp[start][end] = ans;
  }

public:
  int getMoneyAmount(int n)
  {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(1, n, dp);
  }
};