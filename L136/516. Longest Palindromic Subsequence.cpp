// here we just pass the string and the reverse of the string to the longest common subsequence func to get the ans. so refer to space optimized code of L135.

class Solution
{
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

public:
  int longestPalindromeSubseq(string s)
  {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return longestCommonSubsequence(s, rev);
  }
};