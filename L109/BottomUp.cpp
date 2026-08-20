#include <bits/stdc++.h>
#define MOD 1000000007

int add(int a, int b)
{
  return (a % MOD + b % MOD) % MOD;
}

int mul(int a, int b)
{
  return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

int numberOfWays(int n, int k)
{
  // Write your code here.
  vector<int> dp(n + 1, -1);
  dp[1] = k;
  dp[2] = k * (k - 1) + k;
  for (int i = 3; i <= n; i++)
  {
    dp[i] = add(mul(dp[i - 1], k - 1), mul(dp[i - 2], k - 1));
  }
  return dp[n];
}
