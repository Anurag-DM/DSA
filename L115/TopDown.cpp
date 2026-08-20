class Solution
{
  int solve(vector<vector<char>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
  {
    if (i >= mat.size() || j >= mat[0].size())
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int right = solve(mat, i, j + 1, maxi, dp);
    int diag = solve(mat, i + 1, j + 1, maxi, dp);
    int down = solve(mat, i + 1, j, maxi, dp);

    if (mat[i][j] == '1')
    {
      int ans = 1 + min({right, diag, down});
      maxi = max(maxi, ans);
      return dp[i][j] = ans;
    }
    else
    {
      return dp[i][j] = 0;
    }
  }

public:
  int maximalSquare(vector<vector<char>> &mat)
  {
    int maxi = 0;
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    solve(mat, 0, 0, maxi, dp);
    return maxi * maxi;
  }
};