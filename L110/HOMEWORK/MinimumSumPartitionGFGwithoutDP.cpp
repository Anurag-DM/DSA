class Solution
{
  int solve(vector<int> &arr, int index, int sumcalc, int sumtot)
  {
    if (index < 0)
    {
      return abs(sumcalc - (sumtot - sumcalc));
    }

    int include = solve(arr, index - 1, sumcalc + arr[index], sumtot);
    int exclude = solve(arr, index - 1, sumcalc, sumtot);
    return min(include, exclude);
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
    return solve(arr, n - 1, 0, sum);
  }
};
