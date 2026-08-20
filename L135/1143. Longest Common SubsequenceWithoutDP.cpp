class Solution
{
  int solve(string &text1, string &text2, int i, int j)
  {
    if (i == text1.length() || j == text2.length())
      return 0;

    if (text1[i] == text2[j])
    {
      return 1 + solve(text1, text2, i + 1, j + 1);
    }
    else
    {
      int op1 = solve(text1, text2, i + 1, j);
      int op2 = solve(text1, text2, i, j + 1);
      return max(op1, op2);
    }
  }

public:
  int longestCommonSubsequence(string text1, string text2)
  {
    return solve(text1, text2, 0, 0);
  }
};