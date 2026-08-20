class Solution
{
  int solve(vector<int> &v, int n)
  {
    int size = v.size();
    vector<vector<int>> dp(size + 2, vector<int>(n + 1, 0));

    for (int ind = size - 1; ind >= 0; ind--)
    {
      for (int no = 1; no <= n; no++)
      {
        // include
        int inc = v[ind] + dp[ind + 2][no - 1];

        // exclude
        int exc = dp[ind + 1][no];

        dp[ind][no] = max(inc, exc);
      }
    }

    return dp[0][n];
  }

public:
  int maxSizeSlices(vector<int> &slices)
  {
    vector<int> v1(slices.begin(), slices.end() - 1);
    vector<int> v2(slices.begin() + 1, slices.end());
    int s = slices.size();
    int n = s / 3;

    vector<vector<int>> dp2(s - 1, vector<int>(n + 1, -1));
    return max(solve(v1, n), solve(v2, n));
  }
};