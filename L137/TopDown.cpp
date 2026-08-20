class Solution
{
  int solve(string &word1, string &word2, int ind1, int ind2, vector<vector<int>> &dp)
  {
    if (ind1 == word1.length() && ind2 == word2.length())
      return 0;

    if (ind1 == word1.length() && ind2 != word2.length())
      return word2.length() - ind2;

    if (ind1 != word1.length() && ind2 == word2.length())
      return word1.length() - ind1;

    if (dp[ind1][ind2] != -1)
      return dp[ind1][ind2];

    if (word1[ind1] == word2[ind2])
      return dp[ind1][ind2] = solve(word1, word2, ind1 + 1, ind2 + 1, dp);
    else
    {
      int replace = 1 + solve(word1, word2, ind1 + 1, ind2 + 1, dp);
      int add = 1 + solve(word1, word2, ind1, ind2 + 1, dp);
      int del = 1 + solve(word1, word2, ind1 + 1, ind2, dp);
      return dp[ind1][ind2] = min({replace, add, del});
    }
  }

public:
  int minDistance(string word1, string word2)
  {
    int n1 = word1.length(), n2 = word2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return solve(word1, word2, 0, 0, dp);
  }
};