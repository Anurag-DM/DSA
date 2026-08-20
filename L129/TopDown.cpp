class Solution
{
  int maxi(vector<int> &arr, int start, int end)
  {
    int m = INT_MIN;
    for (int i = start; i <= end; i++)
    {
      if (arr[i] > m)
        m = arr[i];
    }
    return m;
  }
  int solve(vector<int> &arr, int start, int end, vector<vector<int>> &dp)
  {
    if (start == end)
      return 0;

    if (dp[start][end] != -1)
      return dp[start][end];

    int mini = INT_MAX;
    for (int i = start; i < end; i++)
    {
      int left = maxi(arr, start, i);
      int right = maxi(arr, i + 1, end);

      mini = min(mini, left * right + solve(arr, start, i, dp) + solve(arr, i + 1, end, dp));
    }
    return dp[start][end] = mini;
  }

public:
  int mctFromLeafValues(vector<int> &arr)
  {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(arr, 0, n - 1, dp);
  }
};