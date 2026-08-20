class Solution
{
  int solve(vector<int> &values, int i, int j, vector<vector<int>> &dp)
  {
    if (i + 1 == j)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int mini = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
      mini = min(mini, values[i] * values[j] * values[k] + solve(values, i, k, dp) + solve(values, k, j, dp));
    }
    return dp[i][j] = mini;
  }

public:
  int minScoreTriangulation(vector<int> &values)
  {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(values, 0, n - 1, dp);
  }
};