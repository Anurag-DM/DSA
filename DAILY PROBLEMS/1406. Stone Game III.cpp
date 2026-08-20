/*Top Down Approach
class Solution {
    int solve(vector<int> &stoneValue, int start, int end, vector<int> &dp){
        if(start == end)
            return 0;
        
        if(dp[start]!=INT_MIN)
            return dp[start];

        //choose 1 no
        int op1 = stoneValue[start] - solve(stoneValue, start+1, end, dp);

        int op2 = INT_MIN, op3 = INT_MIN;
        //choose 2 no
        if(start+1<end)
            op2 = stoneValue[start] + stoneValue[start+1] - solve(stoneValue, start+2, end, dp);
        
        if(start+2<end)
            op3 = stoneValue[start] + stoneValue[start+1] + stoneValue[start+2] - solve(stoneValue, start+3, end, dp);
        
        return dp[start] = max({op1, op2, op3});
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);

        int ans = solve(stoneValue, 0, n, dp);

        if( ans >0)
            return "Alice";
        else if(ans == 0)
            return "Tie";
        else
            return "Bob";
    }
};
*/

//Bottom Up
