class Solution
{
public:
  int findMinDiff(vector<int> &a, int m)
  {
    sort(a.begin(), a.end());
    int mini = INT_MAX;
    int n = a.size();
    for (int i = 0; i <= n - m; i++)
    {
      int diff = a[i + m - 1] - a[i];
      mini = min(mini, diff);
    }
    return mini;
  }
};