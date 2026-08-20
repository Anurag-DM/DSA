class Solution
{
  int solve(string &word1, string &word2, int ind1, int ind2)
  {
    if (ind1 == word1.length() && ind2 == word2.length())
      return 0;

    if (ind1 == word1.length() && ind2 != word2.length())
      return word2.length() - ind2;

    if (ind1 != word1.length() && ind2 == word2.length())
      return word1.length() - ind1;

    if (word1[ind1] == word2[ind2])
      return solve(word1, word2, ind1 + 1, ind2 + 1);
    else
    {
      int replace = 1 + solve(word1, word2, ind1 + 1, ind2 + 1);
      int add = 1 + solve(word1, word2, ind1, ind2 + 1);
      int del = 1 + solve(word1, word2, ind1 + 1, ind2);
      return min({replace, add, del});
    }
  }

public:
  int minDistance(string word1, string word2)
  {
    return solve(word1, word2, 0, 0);
  }
};