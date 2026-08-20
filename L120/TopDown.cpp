class Solution
{
  int solve(vector<vector<int>> &cuboids, int ind, int prev, vector<vector<int>> &dp)
  {
    if (ind == cuboids.size())
      return 0;

    if (dp[ind][prev + 1] != -1)
      return dp[ind][prev + 1];

    vector<int> curr;
    curr = cuboids[ind];

    vector<int> p;
    if (prev != -1)
      p = cuboids[prev];

    // include
    int inc = 0;
    if (prev == -1 || curr[0] >= p[0] && curr[1] >= p[1] && curr[2] >= p[2])
    {
      inc = curr[2] + solve(cuboids, ind + 1, ind, dp);
    }

    // exclude
    int exc = solve(cuboids, ind + 1, prev, dp);

    return dp[ind][prev + 1] = max(inc, exc);
  }

public:
  int maxHeight(vector<vector<int>> &cuboids)
  {
    // step1: sort the cuboids in ascending order
    for (auto &i : cuboids)
    {
      sort(i.begin(), i.end());
    }

    // step2: sort the arrangement of cuboids by their width
    sort(cuboids.begin(), cuboids.end());

    // step3: apply longest increasing subsequence logic
    int n = cuboids.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(cuboids, 0, -1, dp);
  }
};