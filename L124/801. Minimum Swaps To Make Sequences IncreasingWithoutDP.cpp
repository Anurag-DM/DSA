class Solution
{
  int solve(vector<int> &nums1, vector<int> &nums2, int ind, bool swapped)
  {
    if (ind == nums1.size())
      return 0;

    int prev1 = nums1[ind - 1];
    int prev2 = nums2[ind - 1];

    if (swapped)
      swap(prev2, prev1);

    int swap = 1e9, noswap = 1e9;

    // no swap
    if (nums1[ind] > prev1 && nums2[ind] > prev2)
      noswap = solve(nums1, nums2, ind + 1, false);

    // swap
    if (nums1[ind] > prev2 && nums2[ind] > prev1)
      swap = 1 + solve(nums1, nums2, ind + 1, true);

    return min(swap, noswap);
  }

public:
  int minSwap(vector<int> &nums1, vector<int> &nums2)
  {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    return solve(nums1, nums2, 1, false);
  }
};