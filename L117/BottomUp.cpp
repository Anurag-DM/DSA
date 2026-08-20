class Solution
{
public:
  int minSideJumps(vector<int> &obstacles)
  {
    // step1
    vector<vector<int>> dp(obstacles.size(), vector<int>(4, 1e9));
    int n = obstacles.size() - 1;

    // step2
    dp[n][1] = 0;
    dp[n][2] = 0;
    dp[n][3] = 0;

    // step3
    for (int pos = n - 1; pos >= 0; pos--)
    {
      for (int lane = 1; lane <= 3; lane++)
      {
        if (obstacles[pos + 1] != lane)
        {
          dp[pos][lane] = dp[pos + 1][lane];
        }
        else
        {
          int mini = 1e9;
          for (int i = 1; i <= 3; i++)
          {
            if (i != lane && obstacles[pos] != i)
            {
              mini = min(mini, 1 + dp[pos + 1][i]);
            }
          }
          dp[pos][lane] = mini;
        }
      }
    }

    return min({dp[0][1] + 1, dp[0][2], dp[0][3] + 1});
    // we do +1 for dp[0][1] and dp[0][3] because starting position is [0][2] so we need a sideward jump

    // in bottom up approach we try to reach from any lane of nth pos to (0,2)
    // in top down approach we try to reach from (0,2) to any lane of nth pos
  }
};