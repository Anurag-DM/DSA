//time and space O(m*n)
class Solution
{
public:
  int maximalSquare(vector<vector<char>> &mat)
  {
    int maxi = 0;
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = m - 1; i >= 0; i--)
    {
      for (int j = n - 1; j >= 0; j--)
      {
        int right = dp[i][j + 1];
        int diag = dp[i + 1][j + 1];
        int down = dp[i + 1][j];

        if (mat[i][j] == '1')
        {
          dp[i][j] = 1 + min({right, diag, down});
          maxi = max(maxi, dp[i][j]);
        }
        else
        {
          dp[i][j] = 0;
        }
      }
    }

    return maxi * maxi;
  }
};