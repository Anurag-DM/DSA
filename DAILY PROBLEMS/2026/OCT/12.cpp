#define MOD 1000000007
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> b(30, 0);
        int ans = 0;

        for(int i : nums){
            for(int j = 0; j < 30; j++){
                if(i & (1 << j))
                    b[j]++;
            }
        }

        while(k-- > 0){
            long long x = 0;
            for(int i = 0; i<30; i++){
                if(b[i]){
                    x |= 1LL << i;
                    b[i]--;
                }
            }

            ans = (ans + x*x) % MOD; 
        }

        return ans;
    }
};