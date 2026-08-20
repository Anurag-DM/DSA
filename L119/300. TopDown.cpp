// time O(n2)  space O(n2)
class Solution
{
  int solve(vector<int> &arr, int ind, int prev, vector<vector<int>> &dp)
  {
    if (ind == arr.size())
      return 0;

    if (dp[ind][prev + 1] != -1)
      return dp[ind][prev + 1];

    // include
    int inc = 0;
    if (prev == -1 || arr[ind] > arr[prev])
      inc = 1 + solve(arr, ind + 1, ind, dp);

    // exclude
    int exc = solve(arr, ind + 1, prev, dp);

    return dp[ind][prev + 1] = max(inc, exc);
  }

public:
  int lis(vector<int> &arr)
  {
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(arr, 0, -1, dp);
  }
};