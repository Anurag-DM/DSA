class Solution
{
public:
  long long countMajoritySubarrays(vector<int> &nums, int target)
  {
    int n = nums.size();

    // update the array with each target element as +1 and rest as -1
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == target)
        nums[i] = 1;
      else
        nums[i] = -1;
    }

    vector<int> pref(n);

    // pref[i] denotes sum upto index i include the ith index
    pref[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
      pref[i] = pref[i - 1] + nums[i];
    }

    // create frequency array for prefix sums
    // prefix sum can go from -n to n
    vector<int> freq(2 * n + 1, 0);

    // for index 0 there is no elements behind it so prefix sum is 0 and freq of sum 0 ie freq[0+n] = 1
    // to avoid negative index we do +n to prefix sum
    freq[n] = 1;

    int lastsum = 0;
    int valid = 0;

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
      if (pref[i] > lastsum)
        valid += freq[lastsum + n];
      else
        valid -= freq[pref[i] + n];

      ans += valid;
      freq[pref[i] + n]++;
      lastsum = pref[i];
    }

    return ans;
  }
};