class Solution
{
public:
  int minDifference(vector<int> &arr)
  {
    // code here
    int n = arr.size();
    int sum = 0;
    for (int i : arr)
    {
      sum += i;
    }

    // step1:
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    // dp[i][j] represents using indicies from 0 to i can we achieve a sum of j

    // step2:
    for (int i = 0; i < n; i++)
    {
      dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
      for (int j = sum; j >= 0; j--)
      {
        // exclude case
        bool exclude = dp[i - 1][j];

        // include case
        bool include = 0;
        if (arr[i] <= j)
        {
          include = dp[i - 1][j - arr[i]];
        }

        dp[i][j] = include || exclude;
      }
    }

    int mini = INT_MAX;
    for (int i = 0; i <= sum; i++)
    {
      if (dp[n - 1][i])
      {
        int diff = abs(i - (sum - i));
        if (diff < mini)
          mini = diff;
      }
    }

    return mini;
  }
};