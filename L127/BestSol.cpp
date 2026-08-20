// catalan number
// Time: O(n) Space: O(1)
long long numTrees(int n)
{
  long long res = 1;

  for (int i = 0; i < n; i++)
  {
    res = res * 2 * (2 * i + 1) / (i + 2);
  }

  return res;
}