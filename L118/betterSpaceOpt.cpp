// time: O(n^2)   space: O(n)
//  using single vector
class Solution
{
public:
  int maxSatisfaction(vector<int> &satisfaction)
  {

    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();

    // step1
    vector<int> curr(n + 2, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int time = 1; time <= n; time++)
      {
        int include = satisfaction[ind] * time + curr[time + 1];
        int exclude = curr[time];

        curr[time] = max(include, exclude);
      }
    }

    return curr[1];
  }
};