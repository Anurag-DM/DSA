// 1658. Minimum Operations to Reduce X to Zero
// Time : O(n)
// Space : O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = 0;
        int n = nums.size();

        for(int i : nums){
            sum += i;
        }

        long long target = sum - x;

        if(target == 0)
            return n;

        long long curr = 0;
        int longest = 0;
        int left = 0;

        for(int right = 0; right < n; right++){
            curr += nums[right];

            while(curr > target && left <= right){
                curr -= nums[left++];
            }

            if(curr == target)
                longest = max(longest, right - left + 1);

        }

        if(longest == 0)
            return -1;

        return n - longest;
    }
};

// Time : O(n2) 
// Space : O(n2)
// class Solution {
//     int solve(vector<int> &nums, int left, int right, int x, vector<vector<int>> &dp){
//         if(x == 0)
//             return 0;

//         if(left > right || x<0)
//             return INT_MAX;
        
//         if(dp[left][right] != -1)
//             return dp[left][right];
        
//         int leftRemove = solve(nums, left + 1, right, x - nums[left], dp);
//         int rightRemove = solve(nums, left, right - 1, x - nums[right], dp);

//         int mini = min(leftRemove, rightRemove);

//         return dp[left][right] = mini == INT_MAX ? INT_MAX : mini + 1;
//     }
// public:
//     int minOperations(vector<int>& nums, int x) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));

//         int ans = solve(nums, 0, n - 1, x, dp);

//         if(ans == INT_MAX)
//             return -1;
        
//         return ans;
//     }
// };