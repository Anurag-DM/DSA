// 3904. Smallest Stable Index II
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n+1, INT_MAX);

        for(int i = n-1; i>=0 ; i--){
            mini[i] = min(nums[i], mini[i+1]);
        }

        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            maxi = max(maxi, nums[i]);
            if(maxi - mini[i] <= k)
                return i;
        }

        return -1;
    }
};