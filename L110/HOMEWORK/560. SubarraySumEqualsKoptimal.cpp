// this is not a dp problem, this is hashmap + prefix sum prob
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, count = 0;
        for (int i : nums)
        {
            sum += i;
            if (mp.find(sum - k) != mp.end())
                count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};