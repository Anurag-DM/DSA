class Solution
{
  int solve(vector<vector<int>> &cuboids, int ind, int prev)
  {
    if (ind == cuboids.size())
      return 0;

    vector<int> curr;
    curr = cuboids[ind];

    vector<int> p;
    if (prev != -1)
      p = cuboids[prev];

    // include
    int inc = 0;
    if (prev == -1 || curr[0] >= p[0] && curr[1] >= p[1] && curr[2] >= p[2])
    {
      inc = curr[2] + solve(cuboids, ind + 1, ind);
    }

    // exclude
    int exc = solve(cuboids, ind + 1, prev);

    return max(inc, exc);
  }

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
    return solve(cuboids, 0, -1);
  }
};