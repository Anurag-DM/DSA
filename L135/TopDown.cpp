//Time Complexity = O(m * n)
/* Space:
1. DP table: O(m * n)
2. Recursive stack: In worst case: O(m + n)
Total Space Complexity: O(m * n) + O(m + n)
Simplified: O(m * n)
*/
class Solution
{
  int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
  {
    if (i == text1.length() || j == text2.length())
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    if (text1[i] == text2[j])
    {
      return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1, dp);
    }
    else
    {
      int op1 = solve(text1, text2, i + 1, j, dp);
      int op2 = solve(text1, text2, i, j + 1, dp);
      return dp[i][j] = max(op1, op2);
    }
  }

public:
  int longestCommonSubsequence(string text1, string text2)
  {
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    return solve(text1, text2, 0, 0, dp);
  }
};