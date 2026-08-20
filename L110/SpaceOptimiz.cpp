//USING 2 1D ARRAYS
#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  // step1:
  // since current row depends only on the previous row so instead of taking a 2d array we take 2 1d array
  vector<int> prev(maxWeight + 1, 0);
  vector<int> curr(maxWeight + 1, 0);

  // step2:
  for (int w = weight[0]; w <= maxWeight; w++)
  {
    prev[w] = value[0];
  }

  // step3:
  for (int index = 1; index < n; index++)
  {
    for (int w = 0; w <= maxWeight; w++)
    {
      int include = 0;
      if (weight[index] <= w)
      {
        include = value[index] + prev[w - weight[index]];
      }

      int exclude = prev[w];
      curr[w] = max(include, exclude);
    }
    prev = curr;
  }
  return prev[maxWeight];
}