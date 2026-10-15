// 2913. Subarrays Distinct Element Sum of Squares I
// Time : O(n^2)
// Space : O(1)

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            vector<int> freq(101, 0);
            int distinct = 0;

            for(int j = i; j < n; j++){
                int no = nums[j];
                if(freq[no] == 0){
                    distinct++;
                    freq[no]++;
                }

                ans += distinct * distinct;
            }
        }

        return ans;
    }
};