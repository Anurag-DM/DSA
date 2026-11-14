// 3364. Minimum Positive Sum Subarray 
// Time : O(n2)
// Space : O(n)
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefixsum(n);

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            prefixsum[i] = sum;
        }

        int ans = INT_MAX;
        sum = 0;

        for(int i = l-1; i < r; i++){
            sum = prefixsum[i];
            if(sum > 0)
                ans = min(sum, ans);

            for(int j = i+1; j < n; j++){
                sum = prefixsum[j] - prefixsum[j - i - 1];
                if(sum > 0)
                    ans = min(ans, sum);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};