// 3550. Smallest Index With Digit Sum Equal to Index
// Time : O(n) where n is size of array; length of a no can be at max 4 so linear time complexity
// Space : O(1)
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i< nums.size(); i++){
            int no = nums[i];
            int sum = 0;

            while(no > 0){
                sum += no % 10;
                no /= 10;
            }

            if(sum == i)
                return i;
        }

        return -1;
    }
};