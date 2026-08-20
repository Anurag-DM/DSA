class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int n1 = word1.length(), n2 = word2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = n2 - 1; i >= 0; i--)
    {
      dp[n1][i] = n2 - i;
    }

    for (int i = n1 - 1; i >= 0; i--)
    {
      dp[i][n2] = n1 - i;
    }

    for (int ind1 = n1 - 1; ind1 >= 0; ind1--)
    {
      for (int ind2 = n2 - 1; ind2 >= 0; ind2--)
      {
        if (word1[ind1] == word2[ind2])
          dp[ind1][ind2] = dp[ind1 + 1][ind2 + 1];
        else
        {
          int replace = 1 + dp[ind1 + 1][ind2 + 1];
          int add = 1 + dp[ind1][ind2 + 1];
          int del = 1 + dp[ind1 + 1][ind2];
          dp[ind1][ind2] = min({replace, add, del});
        }
      }
    }
    return dp[0][0];
  }
};