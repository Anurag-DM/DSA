class Solution
{
  int solve(vector<int> &arr, int index, int sumcalc, int sumtot, vector<vector<int>> &dp)
  {
    if (index < 0)
    {
      return abs(sumcalc - (sumtot - sumcalc));
    }

    if (dp[index][sumcalc] != -1)
      return dp[index][sumcalc];

    int include = solve(arr, index - 1, sumcalc + arr[index], sumtot, dp);
    int exclude = solve(arr, index - 1, sumcalc, sumtot, dp);
    dp[index][sumcalc] = min(include, exclude);
    return dp[index][sumcalc];
  }

public:
  int minDifference(vector<int> &arr)
  {
    // code here
    int n = arr.size(), sum = 0;
    for (int i : arr)
    {
      sum += i;
    }

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return solve(arr, n - 1, 0, sum, dp);
  }
};
