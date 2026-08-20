//Time	O(n²) , Space	O(n) , Optimized time O(n log n) using binary search
class Solution
{
public:
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    int n = days.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      int day = costs[0] + dp[i + 1];

      int temp = i;
      while (temp < days.size() && days[temp] - 7 < days[i])
      {
        temp++;
      }
      int week = costs[1] + dp[temp];

      temp = i;
      while (temp < days.size() && days[temp] - 30 < days[i])
      {
        temp++;
      }
      int month = costs[2] + dp[temp];

      dp[i] = min(day, min(week, month));
    }
    return dp[0];
  }
};