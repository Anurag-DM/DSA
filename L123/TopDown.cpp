class Solution
{
  bool solve(vector<int> &arr, int ind, int sum, vector<vector<int>> &dp)
  {
    if (sum == 0)
      return true;

    if (ind == arr.size() || sum < 0)
      return false;

    if (dp[ind][sum] != -1)
      return dp[ind][sum];

    // include
    bool inc = solve(arr, ind + 1, sum - arr[ind], dp);

    // exclude
    bool exc = solve(arr, ind + 1, sum, dp);

    return dp[ind][sum] = inc || exc;
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

    vector<vector<int>> dp(arr.size(), vector<int>(sum / 2 + 1, -1));
    return solve(arr, 0, sum / 2, dp);
  }
};