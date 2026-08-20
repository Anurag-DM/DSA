// Time: O(n log n) Space: O(n)
class Solution
{
public:
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    int n = days.size();
    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
      // 1-day pass
      int day = costs[0] + dp[i + 1];

      // 7-day pass
      int next7 = lower_bound(days.begin(), days.end(), days[i] + 7) - days.begin();
      int week = costs[1] + dp[next7];

      // 30-day pass
      int next30 = lower_bound(days.begin(), days.end(), days[i] + 30) - days.begin();
      int month = costs[2] + dp[next30];

      dp[i] = min({day, week, month});
    }

    return dp[0];
  }
};