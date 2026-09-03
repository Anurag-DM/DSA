class Solution
{
  bool solve(vector<int> &arr, int start, vector<bool> &vis)
  {
    if (start < 0 || start >= arr.size())
      return false;

    if (arr[start] == 0)
      return true;

    if (vis[start])
      return false;

    vis[start] = true;

    bool left = solve(arr, start - arr[start], vis);
    bool right = solve(arr, start + arr[start], vis);

    return left || right;
  }

public:
  bool canReach(vector<int> &arr, int start)
  {
    vector<bool> visited(arr.size(), false);
    return solve(arr, start, visited);
  }
};