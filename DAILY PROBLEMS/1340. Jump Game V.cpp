/* TLE
class Solution
{
  int solve(vector<int> &arr, int d, int ind)
  {

    int ans = 1; // count current index

    for (int i = 1; i <= d; i++)
    {

      if (ind - i < 0 || arr[ind - i] >= arr[ind])
        break;

      ans = max(ans, 1 + solve(arr, d, ind - i));
    }

    for (int i = 1; i <= d; i++)
    {

      if (ind + i >= arr.size() || arr[ind + i] >= arr[ind])
        break;

      ans = max(ans, 1 + solve(arr, d, ind + i));
    }

    return ans;
  }

public:
  int maxJumps(vector<int> &arr, int d)
  {

    int ans = 1;

    for (int i = 0; i < arr.size(); i++)
    {
      ans = max(ans, solve(arr, d, i));
    }

    return ans;
  }
};*/

class Solution
{
  int solve(vector<int> &arr, int d, int ind, vector<int> &dp)
  {
    if (dp[ind] != -1)
      return dp[ind];

    int op1 = 1, op2 = 1;
    for (int i = 1; i <= d; i++)
    {
      if (ind - i < 0 || arr[ind - i] >= arr[ind])
        break;

      op1 = max(op1, 1 + solve(arr, d, ind - i, dp));
    }
    for (int i = 1; i <= d; i++)
    {
      if (ind + i >= arr.size() || arr[ind + i] >= arr[ind])
        break;
      op2 = max(op2, 1 + solve(arr, d, ind + i, dp));
    }

    return dp[ind] = max(op1, op2);
  }

public:
  int maxJumps(vector<int> &arr, int d)
  {
    int n = arr.size();
    int ans = 0;
    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++)
    {
      ans = max(ans, solve(arr, d, i, dp));
    }

    return ans;
  }
};