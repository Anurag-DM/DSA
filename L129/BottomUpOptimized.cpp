//Time: O(n3) because max values are precomputed
class Solution
{
public:
  int mctFromLeafValues(vector<int> &arr)
  {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    vector<vector<int>> maxVal(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
      maxVal[i][i] = arr[i];
      for (int j = i + 1; j < n; j++)
      {
        maxVal[i][j] = max(maxVal[i][j - 1], arr[j]);
      }
    }

    for (int start = n - 1; start >= 0; start--)
    {
      for (int end = start + 1; end < n; end++)
      {
        int mini = INT_MAX;
        for (int i = start; i < end; i++)
        {
          int left = maxVal[start][i];
          int right = maxVal[i + 1][end];

          mini = min(mini, left * right + dp[start][i] + dp[i + 1][end]);
        }
        dp[start][end] = mini;
      }
    }
    return dp[0][n - 1];
  }
};