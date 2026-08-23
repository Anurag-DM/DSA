class Solution {
    int solve(int n, vector<int> &costs, int currstep, vector<int> &dp){
        if(currstep == n)
            return 0;
        
        if(dp[currstep]!=-1)
            return dp[currstep];
        
        //jump 1 step
        int op1 = costs[currstep] + 1 + solve(n, costs, currstep+1, dp);

        //jump 2 step
        int op2 = INT_MAX;
        if(currstep + 2 <= n)
            op2 = costs[currstep+1] + 4 + solve(n, costs, currstep+2, dp);
        
        //jump 3 steps
        int op3 = INT_MAX;
        if(currstep + 3 <= n)
            op3 = costs[currstep+2] + 9 + solve(n, costs, currstep+3, dp);
        
        return dp[currstep] = min({op1, op2, op3});
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        //return solve(n, costs, 0, dp);

        dp[0] = 0;
        dp[1] = costs[0] + 1;

        if(n == 1)
            return dp[1];
            
        dp[2] = min(dp[1] + costs[1] + 1, dp[0] + costs[1] + 4);

        for(int i = 3; i<=n; i++){
            //came by 1 jump
            int op1 = dp[i-1] + costs[i-1] + 1;

            //came by 2 jump
            int op2 = dp[i-2] + costs[i-1] + 4;

            //came by 3 jump
            int op3 = dp[i-3] + costs[i-1] + 9;

            dp[i] = min({op1, op2, op3});
        }

        return dp[n];
    }
};