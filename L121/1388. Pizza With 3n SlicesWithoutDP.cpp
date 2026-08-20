class Solution
{
  int solve(vector<int> &slices, int ind, int n)
  {
    if (ind >= slices.size() || n == 0)
      return 0;

    // include
    int inc = slices[ind] + solve(slices, ind + 2, n - 1);

    // exclude
    int exc = solve(slices, ind + 1, n);

    return max(inc, exc);
  }

public:
  int maxSizeSlices(vector<int> &slices)
  {
    vector<int> v1(slices.begin(), slices.end() - 1);
    vector<int> v2(slices.begin() + 1, slices.end());
    int s = slices.size();
    int n = s / 3;
    return max(solve(v1, 0, n), solve(v2, 0, n));
  }
};