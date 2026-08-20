// time O(n)   space O(n)
class Solution
{
public:
  int minSwap(vector<int> &nums1, vector<int> &nums2)
  {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    int n = nums1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 1; ind--)
    {
      for (int swapped = 0; swapped < 2; swapped++)
      {
        int prev1 = nums1[ind - 1];
        int prev2 = nums2[ind - 1];

        if (swapped)
          swap(prev2, prev1);

        int swap = 1e9, noswap = 1e9;

        // no swap
        if (nums1[ind] > prev1 && nums2[ind] > prev2)
          noswap = dp[ind + 1][0];

        // swap
        if (nums1[ind] > prev2 && nums2[ind] > prev1)
          swap = 1 + dp[ind + 1][1];

        dp[ind][swapped] = min(swap, noswap);
      }
    }

    return dp[1][0];
  }
};