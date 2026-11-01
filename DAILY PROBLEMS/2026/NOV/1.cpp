// 453. Minimum Moves to Equal Array Elements
// Time complexity : O(n)
// Space complexity : O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        int ans = 0;

        for(int i : nums)
            mini = min(i,mini);
        
        for(int i : nums)
            ans += i - mini;
        
        return ans;
    }
};