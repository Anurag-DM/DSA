// Time	O(n) Space	O(n)
class Solution
{
public:
  int longestSubsequence(vector<int> &arr, int difference)
  {
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i : arr)
    {
      mp[i] = mp[i - difference] + 1;
      ans = max(ans, mp[i]);
    }
    return ans;
  }
};