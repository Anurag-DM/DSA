// 1524. Number of Sub-arrays With Odd Sum
// Time : O(n)
// Space : O(n)
class Solution {
    int mod = 1000000007;
public:
    int numOfSubarrays(vector<int>& arr) {
        int evensums = 1;
        int oddsums = 0;
        int n = arr.size();

        vector<int> prefixsum;

        int s = 0;

        for(int i : arr){
            s += i;
            prefixsum.push_back(s);
        }

        int ans = 0;
        for(int i : prefixsum){
            if(i % 2 == 1){
                ans = (ans + evensums) % mod;
                oddsums++;
            }
            else{
                ans = (ans + oddsums) % mod;
                evensums++;
            }
        }

        return ans;
    }
};