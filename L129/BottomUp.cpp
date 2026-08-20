//Time: O(n3) (DP) × O(n) (max)=O(n4)
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

public:
  int mctFromLeafValues(vector<int> &arr)
  {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int start = n - 1; start >= 0; start--)
    {
      for (int end = start + 1; end < n; end++)
      {
        int mini = INT_MAX;
        for (int i = start; i < end; i++)
        {
          int left = maxi(arr, start, i);
          int right = maxi(arr, i + 1, end);

          mini = min(mini, left * right + dp[start][i] + dp[i + 1][end]);
        }
        dp[start][end] = mini;
      }
    }
    return dp[0][n - 1];
  }
};