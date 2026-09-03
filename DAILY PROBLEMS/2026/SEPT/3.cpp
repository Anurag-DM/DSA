// 3876. Construct Uniform Parity Array II

//Time: O(n) where n is the size of the input array nums1
//Space: O(1) as we are using constant space

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX, noOfOdd = 0;

        for(int i: nums1){
            if(i < mini)
                mini = i;
            
            if(i%2 == 1)
                noOfOdd++;
        }

        if(mini % 2 == 1 || noOfOdd == 0)
            return true;
        
        return false;
    }
};