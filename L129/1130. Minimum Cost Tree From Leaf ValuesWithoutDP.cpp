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
  int solve(vector<int> &arr, int start, int end)
  {
    if (start == end)
      return 0;

    int mini = INT_MAX;
    for (int i = start; i < end; i++)
    {
      int left = maxi(arr, start, i);
      int right = maxi(arr, i + 1, end);

      mini = min(mini, left * right + solve(arr, start, i) + solve(arr, i + 1, end));
    }
    return mini;
  }

public:
  int mctFromLeafValues(vector<int> &arr)
  {
    int n = arr.size();
    return solve(arr, 0, n - 1);
  }
};