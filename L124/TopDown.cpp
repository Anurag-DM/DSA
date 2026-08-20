class Solution
{
  int solve(vector<int> &nums1, vector<int> &nums2, int ind, bool swapped, vector<vector<int>> &dp)
  {
    if (ind == nums1.size())
      return 0;

    if (dp[ind][swapped] != -1)
      return dp[ind][swapped];

    int prev1 = nums1[ind - 1];
    int prev2 = nums2[ind - 1];

    if (swapped)
      swap(prev2, prev1);

    int swap = 1e9, noswap = 1e9;

    // no swap
    if (nums1[ind] > prev1 && nums2[ind] > prev2)
      noswap = solve(nums1, nums2, ind + 1, false, dp);

    // swap
    if (nums1[ind] > prev2 && nums2[ind] > prev1)
      swap = 1 + solve(nums1, nums2, ind + 1, true, dp);

    return dp[ind][swapped] = min(swap, noswap);
  }

public:
  int minSwap(vector<int> &nums1, vector<int> &nums2)
  {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return solve(nums1, nums2, 1, false, dp);
  }
};