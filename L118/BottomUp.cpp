class Solution
{
public:
  int maxSatisfaction(vector<int> &satisfaction)
  {

    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();

    // step1
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int time = 1; time <= n; time++)
      {
        int include = satisfaction[ind] * time + dp[ind + 1][time + 1];
        int exclude = dp[ind + 1][time];

        dp[ind][time] = max(include, exclude);
      }
    }

    return dp[0][1];
  }
};