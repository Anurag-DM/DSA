// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
// Time : O(n)
// Space : O(1)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1;

        // find max size of strictly increasing subarray
        int count = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                count++;
                inc = max(inc, count);
            }
            else
                count = 1;
        }

        // find max size of strictly decreasing subarray
        count = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]){
                count++;
                dec = max(dec, count);
            }
            else
                count = 1;
        }

        return max(inc,dec);
    }
};