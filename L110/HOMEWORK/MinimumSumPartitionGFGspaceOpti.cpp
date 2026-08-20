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
    vector<bool> dp(sum + 1, false);
    // dp[i][j] represents using indicies from 0 to i can we achieve a sum of j

    // step2:
    dp[0] = true;
    for (int i = 1; i <= sum; i++)
    {
      dp[i] = false;
    }
    dp[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
      for (int j = sum; j >= 0; j--)
      {
        // exclude case
        bool exclude = dp[j];

        // include case
        bool include = 0;
        if (arr[i] <= j)
        {
          include = dp[j - arr[i]];
        }

        dp[j] = include || exclude;
      }
    }

    int mini = INT_MAX;
    for (int i = 0; i <= sum; i++)
    {
      if (dp[i])
      {
        int diff = abs(i - (sum - i));
        if (diff < mini)
          mini = diff;
      }
    }

    return mini;
  }
};