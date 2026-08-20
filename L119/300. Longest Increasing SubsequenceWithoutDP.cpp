class Solution
{
  int solve(vector<int> &arr, int ind, int prev)
  {
    if (ind == arr.size())
      return 0;

    // include
    int inc = 0;
    if (prev == -1 || arr[ind] > arr[prev])
      inc = 1 + solve(arr, ind + 1, ind);

    // exclude
    int exc = solve(arr, ind + 1, prev);

    return max(inc, exc);
  }

public:
  int lis(vector<int> &arr)
  {
    // code here
    return solve(arr, 0, -1);
  }
};