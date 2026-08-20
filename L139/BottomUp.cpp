class Solution
{
public:
  bool isMatch(string s, string p)
  {
    int n1 = s.length(), n2 = p.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    dp[n1][n2] = 1;

    for (int i = n2 - 1; i >= 0; i--)
    {
      if (p[i] == '*')
        dp[n1][i] = 1;
      else
        break;
    }

    for (int ind1 = n1 - 1; ind1 >= 0; ind1--)
    {
      for (int ind2 = n2 - 1; ind2 >= 0; ind2--)
      {
        if (s[ind1] == p[ind2] || p[ind2] == '?')
          dp[ind1][ind2] = dp[ind1 + 1][ind2 + 1];
        else
        {
          if (p[ind2] == '*')
          {

            // fill 0 char
            bool op1 = dp[ind1][ind2 + 1];

            // fill char
            bool op2 = dp[ind1 + 1][ind2];

            dp[ind1][ind2] = op1 || op2;
          }
          else // does not match
            dp[ind1][ind2] = false;
        }
      }
    }
    return dp[0][0];
  }
};