class Solution
{
  int solve(vector<int> &v, int ind, int n, vector<vector<int>> &dp)
  {
    if (ind >= v.size() || n == 0)
      return 0;

    if (dp[ind][n] != -1)
      return dp[ind][n];

    // include
    int inc = v[ind] + solve(v, ind + 2, n - 1, dp);

    // exclude
    int exc = solve(v, ind + 1, n, dp);

    return dp[ind][n] = max(inc, exc);
  }

public:
  int maxSizeSlices(vector<int> &slices)
  {
    vector<int> v1(slices.begin(), slices.end() - 1);
    vector<int> v2(slices.begin() + 1, slices.end());
    int s = slices.size();
    int n = s / 3;
    vector<vector<int>> dp1(s - 1, vector<int>(n + 1, -1));
    vector<vector<int>> dp2(s - 1, vector<int>(n + 1, -1));
    return max(solve(v1, 0, n, dp1), solve(v2, 0, n, dp2));
  }
};