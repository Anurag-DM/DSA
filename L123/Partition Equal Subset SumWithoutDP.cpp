class Solution
{
  bool solve(vector<int> &arr, int ind, int sum)
  {
    if (sum == 0)
      return true;

    if (ind == arr.size() || sum < 0)
      return false;

    // include
    bool inc = solve(arr, ind + 1, sum - arr[ind]);

    // exclude
    bool exc = solve(arr, ind + 1, sum);

    return inc || exc;
  }

public:
  bool equalPartition(vector<int> &arr)
  {
    int sum = 0;
    for (int i : arr)
    {
      sum += i;
    }

    if (sum % 2 != 0)
      return false;

    return solve(arr, 0, sum / 2);
  }
};