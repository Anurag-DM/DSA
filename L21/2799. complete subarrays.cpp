class Solution
{
  void solve(vector<int> &nums, int index, int c, int distinct, vector<int> &freq, int &ans)
  {
    if (index == nums.size() || c > distinct)
      return;

    int ele = nums[index];
    freq[ele]++;
    if (freq[ele] == 1)
      c++;
    if (c == distinct)
      ans++;
    solve(nums, index + 1, c, distinct, freq, ans);
  }

public:
  int countCompleteSubarrays(vector<int> &nums)
  {
    vector<int> temp(2001, 0);
    int distinct = 0;
    for (int i : nums)
    {
      temp[i]++;
      if (temp[i] == 1)
        distinct++;
    }

    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      vector<int> freq(2001, 0);
      solve(nums, i, 0, distinct, freq, ans);
    }
    return ans;
  }
};