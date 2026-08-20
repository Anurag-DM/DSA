#include <bits/stdc++.h>
static int count = 0;
int countDistinctWays(int n)
{
  //  Write your code here.
  if (n == 0)
    return 1;
  if (n < 0)
    return 0;
  return ((long long)countDistinctWays(n - 1) +
          countDistinctWays(n - 2)) %
         1000000007;
}
// this will give tle