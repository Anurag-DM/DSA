



/*O(n2)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans = 1;
        for(int i = 1;i<n; i++){
            if(i<n-1 && nums[i] == nums[i+1])
                continue;
            
            int freq = 1;
            int count = k;

            for(int j = i-1; j>=0; j--){
                if(nums[i] - nums[j] <= count){
                    freq++;
                    count -= nums[i] - nums[j];
                }
                else
                    break;
            }

            ans = max(ans, freq);
        }

        return ans;
    }
};/