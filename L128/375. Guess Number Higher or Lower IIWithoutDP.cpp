class Solution
{
  int solve(int start, int end)
  {
    if (start >= end)
      return 0;

    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
      int left = solve(start, i - 1);
      int right = solve(i + 1, end);

      ans = min(ans, i + max(left, right));
    }
    return ans;
  }

public:
  int getMoneyAmount(int n)
  {
    return solve(1, n);
  }
};