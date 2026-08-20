// space O(n) using 2 vectors
class Solution
{
public:
  int maxSatisfaction(vector<int> &satisfaction)
  {

    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();

    // step1
    vector<int> next(n + 2, 0);
    vector<int> curr(n + 2, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int time = 1; time <= n; time++)
      {
        int include = satisfaction[ind] * time + next[time + 1];
        int exclude = next[time];

        curr[time] = max(include, exclude);
      }
      next = curr;
    }

    return curr[1];
  }
};