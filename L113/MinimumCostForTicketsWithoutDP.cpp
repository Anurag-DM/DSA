// n = days.size()
//  time complexity: O(n * 3^n)
//  space complexity: O(n) due to recursion stack
class Solution
{
  int solve(vector<int> &days, vector<int> &costs, int ind)
  {
    if (ind == days.size())
      return 0;

    int day = costs[0] + solve(days, costs, ind + 1);

    int temp = ind;
    while (temp < days.size() && days[temp] - 7 < days[ind])
    {
      temp++;
    }
    int week = costs[1] + solve(days, costs, temp);

    temp = ind;
    while (temp < days.size() && days[temp] - 30 < days[ind])
    {
      temp++;
    }
    int month = costs[2] + solve(days, costs, temp);

    return min(day, min(week, month));
  }

public:
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    return solve(days, costs, 0);
  }
};