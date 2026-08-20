#include <vector>
#define MOD 1000000007
long long int countDerangements(int n)
{
  vector<long long int> dp(n + 1, -1);
  dp[1] = 0;
  dp[2] = 1;
  for (int i = 3; i <= n; i++)
  {
    dp[i] = (((i - 1) % MOD) * (dp[i - 1] % MOD + dp[i - 2] % MOD)) % MOD;
  }
  return dp[n];
}