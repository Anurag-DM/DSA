class Solution
{
public:
  bool isMatch(string s, string p)
  {
    int n1 = s.length(), n2 = p.length();

    vector<int> curr(n2 + 1, 0);
    vector<int> next(n2 + 1, 0);

    next[n2] = 1;

    for (int i = n2 - 1; i >= 0; i--)
    {
      if (p[i] == '*')
        next[i] = 1;
      else
        break;
    }

    for (int ind1 = n1 - 1; ind1 >= 0; ind1--)
    {
      for (int ind2 = n2 - 1; ind2 >= 0; ind2--)
      {
        if (s[ind1] == p[ind2] || p[ind2] == '?')
          curr[ind2] = next[ind2 + 1];
        else
        {
          if (p[ind2] == '*')
          {

            // fill 0 char
            bool op1 = curr[ind2 + 1];

            // fill char
            bool op2 = next[ind2];

            curr[ind2] = op1 || op2;
          }
          else // does not match
            curr[ind2] = false;
        }
      }
      next = curr;
    }
    return next[0]; // curr[0] will give wrong ans in edge case  for eg where s="" and p="*"
  }
};