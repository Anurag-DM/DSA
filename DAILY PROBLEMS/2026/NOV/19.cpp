// 2567. Minimum Score by Changing Two Elements
// Time : O(n)
// Space : O(1)


class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int sm1 = INT_MAX, sm2 = INT_MAX, sm3 = INT_MAX;
        int maxi1 = INT_MIN, maxi2 = INT_MIN, maxi3 = INT_MIN;

        for(int i : nums){
            if(i >= maxi1){
                maxi3 = maxi2;
                maxi2 = maxi1;
                maxi1 = i;
            }
            else if(i >= maxi2){
                maxi3 = maxi2;
                maxi2 = i;
            }
            else if(i >= maxi3)
                maxi3 = i;
            
            if(i <= sm1){
                sm3 = sm2;
                sm2 = sm1;
                sm1 = i;
            }
            else if(i <= sm2){
                sm3 = sm2;
                sm2 = i;
            }
            else if(i <= sm3)
                sm3 = i;
        }

        return min({maxi1 - sm3, maxi3 - sm1, maxi2 - sm2});
    }
};