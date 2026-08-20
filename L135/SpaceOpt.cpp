class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int n1 = text1.length();
    int n2 = text2.length();

    vector<int> curr(n2 + 1, 0);
    vector<int> next(n2 + 1, 0);

    for (int i = n1 - 1; i >= 0; i--)
    {
      for (int j = n2 - 1; j >= 0; j--)
      {
        if (text1[i] == text2[j])
        {
          curr[j] = 1 + next[j + 1];
        }
        else
        {
          int op1 = next[j];
          int op2 = curr[j + 1];
          curr[j] = max(op1, op2);
        }
      }
      next = curr;
    }
    return curr[0];
  }
};