class Solution
{
  bool solve(string &s, string &p, int ind1, int ind2, vector<vector<int>> &dp)
  {

    if (ind1 == s.length() && ind2 == p.length())
      return true;

    if (ind2 == p.length())
      return false;

    if (ind1 == s.length())
    {
      while (ind2 != p.length())
      {
        if (p[ind2] != '*')
          return false;
        ind2++;
      }
      return true;
    }

    if (dp[ind1][ind2] != -1)
      return dp[ind1][ind2];

    if (s[ind1] == p[ind2])
      return dp[ind1][ind2] = solve(s, p, ind1 + 1, ind2 + 1, dp);
    else
    {
      if (p[ind2] == '?')
        return dp[ind1][ind2] = solve(s, p, ind1 + 1, ind2 + 1, dp);
      else if (p[ind2] == '*')
      {

        // fill 0 char
        bool op1 = solve(s, p, ind1, ind2 + 1, dp);

        // fill char
        bool op2 = solve(s, p, ind1 + 1, ind2, dp);

        return dp[ind1][ind2] = op1 || op2;
      }
      else // does not match
        return dp[ind1][ind2] = false;
    }
  }

public:
  bool isMatch(string s, string p)
  {
    int n1 = s.length(), n2 = p.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    return solve(s, p, 0, 0, dp);
  }
};