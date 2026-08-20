class Solution
{
  int solve(int n)
  {
    if (n == 0)
      return 0;

    int c = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
      c = min(c, solve(n - i * i) + 1);
    }
    return c;
  }

public:
  int minSquares(int n)
  {
    // Code here

    return solve(n);
  }
};