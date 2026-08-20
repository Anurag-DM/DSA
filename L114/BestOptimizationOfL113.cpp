// Time: O(n) Space: O(1)
class Solution
{
public:
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    queue<pair<int, int>> week, month;
    // the pair (a,b) : a represents the day of expiry, b represent the cost till the day of expiry

    int cost = 0;
    for (int d : days)
    {
      // remove expired days from week
      while (!week.empty() && week.front().first < d)
        week.pop();

      // remove expired days from month
      while (!month.empty() && month.front().first < d)
        month.pop();

      // add the new passes
      week.push({d + 6, cost + costs[1]});
      month.push({d + 29, cost + costs[2]});

      // update the answer
      cost = min({cost + costs[0],
                  week.front().second,
                  month.front().second});
    }
    return cost;
  }
};