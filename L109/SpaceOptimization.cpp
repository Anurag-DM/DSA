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
  int prev2 = k;
  int prev1 = add(mul(k, k - 1), k);
  for (int i = 3; i <= n; i++)
  {
    int curr = add(mul(prev1, k - 1), mul(prev2, k - 1));
    prev2 = prev1;
    prev1 = curr;
  }
  return prev1;
}
