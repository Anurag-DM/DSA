//time complexity: Current	O(n²) but if binary search	used instead of while loop O(n log n) check screenshot for this
//space complexity: O(n) + O(n) ie dp array and rec stack
class Solution
{
  int solve(vector<int> &days, vector<int> &costs, int ind, vector<int> &dp)
  {
    if (ind == days.size())
      return 0;

    if (dp[ind] != -1)
      return dp[ind];

    int day = costs[0] + solve(days, costs, ind + 1, dp);

    int temp = ind;
    while (temp < days.size() && days[temp] - 7 < days[ind])
    {
      temp++;
    }
    int week = costs[1] + solve(days, costs, temp, dp);

    temp = ind;
    while (temp < days.size() && days[temp] - 30 < days[ind])
    {
      temp++;
    }
    int month = costs[2] + solve(days, costs, temp, dp);

    return dp[ind] = min(day, min(week, month));
  }

public:
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    vector<int> dp(days.size(), -1);
    return solve(days, costs, 0, dp);
  }
};