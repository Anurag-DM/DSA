class Solution
{
  int solve(vector<int> &sat, int ind, int time)
  {
    if (ind == sat.size())
      return 0;

    // include
    int include = sat[ind] * time + solve(sat, ind + 1, time + 1);

    // exclude
    int exclude = solve(sat, ind + 1, time);

    return max(include, exclude);
  }

public:
  int maxSatisfaction(vector<int> &satisfaction)
  {
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, 0, 1);
  }
};