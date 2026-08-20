class Solution
{
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
    int n = arr.size();

    // step1
    vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, 0));

    // step2
    for (int i = 0; i <= n; i++)
      dp[i][0] = true;

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int s = 0; s <= sum / 2; s++)
      {
        // include
        bool inc = false;
        if (s - arr[ind] >= 0)
          inc = dp[ind + 1][s - arr[ind]];

        // exclude
        bool exc = dp[ind + 1][s];

        dp[ind][s] = inc || exc;
      }
    }

    return dp[0][sum / 2];
  }
};