#include <bits/stdc++.h>
#define MOD 1000000007
int solve(int nStairs, vector<int> &dp)
{
  if (nStairs <= 1)
    return 1;

  if (dp[nStairs] != -1)
    return dp[nStairs];

  dp[nStairs] = ((solve(nStairs - 1, dp) % MOD) + (solve(nStairs - 2, dp) % MOD)) % MOD;
  return dp[nStairs];
}
int countDistinctWays(int nStairs)
{
  vector<int> dp(nStairs + 1, -1);
  return solve(nStairs, dp);
}