// 3727. Maximum Alternating Sum of Squares
// Time : O(n log n)
// Space : O(1)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i< n; i++){
            if(nums[i] < 0)
                nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());

        int small = n / 2;
        int large = n / 2;

        if(n % 2 == 1)
            large++;
        
        long long ans = 0;

        for(int i = 0; i<large; i++)
            ans += nums[n-1-i] * nums[n-1-i];

        for(int i = 0; i<small; i++)
            ans -= nums[i] * nums[i];

        return ans;
    }
};