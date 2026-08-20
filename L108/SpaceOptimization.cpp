#include <vector>
#define MOD 1000000007
long long int countDerangements(int n)
{
  vector<long long int> dp(n + 1, -1);
  long long int prev2 = 0;
  long long int prev1 = 1;
  for (int i = 3; i <= n; i++)
  {
    long long int curr = ((i - 1) * (prev1 % MOD + prev2 % MOD)) % MOD;
    prev2 = prev1;
    prev1 = curr;
  }
  return prev1;
}