class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int n1 = text1.length();
    int n2 = text2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = n1 - 1; i >= 0; i--)
    {
      for (int j = n2 - 1; j >= 0; j--)
      {
        if (text1[i] == text2[j])
        {
          dp[i][j] = 1 + dp[i + 1][j + 1];
        }
        else
        {
          int op1 = dp[i + 1][j];
          int op2 = dp[i][j + 1];
          dp[i][j] = max(op1, op2);
        }
      }
    }
    return dp[0][0];
  }
};