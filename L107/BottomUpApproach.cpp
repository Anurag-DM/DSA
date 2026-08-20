#include <limits.h>
int cutSegments(int n, int x, int y, int z)
{
  // Write your code here.
  vector<int> dp(n + 1, INT_MIN);
  dp[0] = 0;

  for (int i = 1; i < n + 1; i++)
  {
    int a = 0, b = 0, c = 0;
    if (i - x >= 0 && dp[i - x] != INT_MIN)
      a = dp[i - x] + 1;
    if (i - y >= 0 && dp[i - y] != INT_MIN)
      b = dp[i - y] + 1;
    if (i - z >= 0 && dp[i - z] != INT_MIN)
      c = dp[i - z] + 1;
    if (!(a == 0 && b == 0 && c == 0))
      dp[i] = max(a, max(b, c));
  }
  if (dp[n] == INT_MIN)
    return 0;
  return dp[n];
}