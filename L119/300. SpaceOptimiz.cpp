//time O(n2)  space: O(n)
class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> next(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int prev = ind - 1; prev >= -1; prev--)
      {
        // include
        int inc = 0;
        if (prev == -1 || nums[ind] > nums[prev])
          inc = 1 + next[ind + 1];

        // exclude
        int exc = 0 + next[prev + 1];

        curr[prev + 1] = max(inc, exc);
      }
      next = curr;
    }
    return curr[-1 + 1];
  }
};