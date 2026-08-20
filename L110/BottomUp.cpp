#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  // step1: create dp array
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

  // step2: analyse base case, here we initialise first row
  for (int w = weight[0]; w <= maxWeight; w++)
  {
    dp[0][w] = value[0];
  }

  // step3:
  for (int index = 1; index < n; index++)
  {
    for (int w = 0; w <= maxWeight; w++)
    {
      int include = 0;
      if (weight[index] <= w)
      {
        include = value[index] + dp[index - 1][w - weight[index]];
      }

      int exclude = dp[index - 1][w];

      dp[index][w] = max(include, exclude);
    }
  }

  return dp[n - 1][maxWeight];
}