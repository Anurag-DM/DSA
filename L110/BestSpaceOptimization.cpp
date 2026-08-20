// USING ONLY 1 1D ARRAY
#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  // step1:
  vector<int> curr(maxWeight + 1, 0);

  // step2:
  for (int w = weight[0]; w <= maxWeight; w++)
  {
    curr[w] = value[0];
  }

  // step3:
  for (int index = 1; index < n; index++)
  {
    // here we traverse right to left because in the inner loop because as can be seen from the currious space optimiz approach that the curr at a given position depends on the curr of that position for exclude case and on any of the positions before it depending on w-weight[index] so if we traverse left to right then we may modify a value which may be later used. but if we do it from right to left then no problem because any position of the curr does not depend on the position to its right of the curr or itself.
    for (int w = maxWeight; w >= 0; w--)
    {
      int include = 0;
      if (weight[index] <= w)
      {
        include = value[index] + curr[w - weight[index]];
      }

      int exclude = curr[w];
      curr[w] = max(include, exclude);
    }
  }
  return curr[maxWeight];
}