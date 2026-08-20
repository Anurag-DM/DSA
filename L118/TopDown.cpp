class Solution
{
  int solve(vector<int> &sat, int ind, int time, vector<vector<int>> &dp)
  {
    if (ind == sat.size())
      return 0;

    if (dp[ind][time] != -1)
      return dp[ind][time];

    // include
    int include = sat[ind] * time + solve(sat, ind + 1, time + 1, dp);

    // exclude
    int exclude = solve(sat, ind + 1, time, dp);

    return dp[ind][time] = max(include, exclude);
  }

public:
  int maxSatisfaction(vector<int> &satisfaction)
  {
    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(satisfaction, 0, 1, dp);
  }
};