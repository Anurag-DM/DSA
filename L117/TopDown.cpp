class Solution
{
  int solve(vector<int> &obs, int pos, int lane, vector<vector<int>> &dp)
  {
    if (pos == obs.size() - 1)
    {
      return 0;
    }

    if (dp[pos][lane] != -1)
      return dp[pos][lane];

    if (obs[pos + 1] != lane)
    {
      return dp[pos][lane] = solve(obs, pos + 1, lane, dp);
    }
    else
    {
      int mini = INT_MAX;
      for (int i = 1; i <= 3; i++)
      {
        if (i != lane && obs[pos] != i)
        {
          mini = min(mini, 1 + solve(obs, pos, i, dp));
        }
      }
      return dp[pos][lane] = mini;
    }
  }

public:
  int minSideJumps(vector<int> &obstacles)
  {
    vector<vector<int>> dp(obstacles.size(), vector<int>(4, -1));
    return solve(obstacles, 0, 2, dp);
  }
};