class Solution
{
  bool solve(string &s, string &p, int ind1, int ind2)
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

    if (s[ind1] == p[ind2])
      return solve(s, p, ind1 + 1, ind2 + 1);
    else
    {
      if (p[ind2] == '?')
        return solve(s, p, ind1 + 1, ind2 + 1);
      else if (p[ind2] == '*')
      {
        // fill 0 char
        bool op1 = solve(s, p, ind1, ind2 + 1);

        // fill char
        bool op2 = solve(s, p, ind1 + 1, ind2);

        return (op1 || op2);
      }
      else // does not match
        return  false;
    }
  }

public:
  bool isMatch(string s, string p)
  {
    return solve(s, p, 0, 0);
  }
};