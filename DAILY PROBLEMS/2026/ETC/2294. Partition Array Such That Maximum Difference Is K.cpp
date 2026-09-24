// 2294. Partition Array Such That Maximum Difference Is K
// Time : O(nlogn) where n is size of array
// Space : O(1)

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = 1;
        int left = 0;
        for(int right = 1; right < nums.size(); right++){
            if(nums[right] - nums[left] > k){
                left = right;
                ans++;
            }
        }

        return ans;
    }
};