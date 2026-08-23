class Solution {
    int solve(int n, int egg, vector<int> &dp){
        if(n<=1)
            return n;

        if(egg == 1)
            return n;
        
        if(dp[n] != -1)
            return dp[n];

        int mini = INT_MAX;
        for(int i = 1; i<=n; i++){ //we check by dropping the egg from all floor poss
            //the egg breaks
            int eggbreak = solve(i-1, egg-1, dp);
            int eggnotbreak = solve(n-i, egg, dp);
            mini = min(mini, max(eggbreak, eggnotbreak) + 1);
        }

        return dp[n] = mini;
    }
public:
    int twoEggDrop(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, 2, dp);
    }
};