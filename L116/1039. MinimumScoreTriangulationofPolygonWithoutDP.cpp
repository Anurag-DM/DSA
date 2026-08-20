class Solution
{
  int solve(vector<int> &values, int i, int j)
  {
    if (i + 1 == j)
      return 0;

    int mini = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
      mini = min(mini, values[i] * values[j] * values[k] + solve(values, i, k) + solve(values, k, j));
    }
    return mini;
  }

public:
  int minScoreTriangulation(vector<int> &values)
  {
    int n = values.size();
    return solve(values, 0, n - 1);
  }
};