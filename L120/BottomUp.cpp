class Solution
{
public:
  int maxHeight(vector<vector<int>> &cuboids)
  {
    // step1: sort the cuboids in ascending order
    for (auto &i : cuboids)
    {
      sort(i.begin(), i.end());
    }

    // step2: sort the arrangement of cuboids by their width
    sort(cuboids.begin(), cuboids.end());

    // step3: apply longest increasing subsequence logic
    int n = cuboids.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
      vector<int> curr;
      curr = cuboids[i];

      for (int prev = i - 1; prev >= -1; prev--)
      {
        vector<int> p;
        if (prev != -1)
          p = cuboids[prev];

        // include
        int inc = 0;
        if (prev == -1 || curr[0] >= p[0] && curr[1] >= p[1] && curr[2] >= p[2])
        {
          inc = curr[2] + dp[i + 1][i + 1];
        }

        // exclude
        int exc = dp[i + 1][prev + 1];

        dp[i][prev + 1] = max(inc, exc);
      }
    }
    return dp[0][0];
  }
};