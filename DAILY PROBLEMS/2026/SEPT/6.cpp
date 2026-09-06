// 115. Distinct Subsequences
class Solution {
    int solve(string &s, string &t, int index1, int index2, vector<vector<int>> &dp){
        if(index2 == t.length())
            return 1;

        if(index1 == s.length())
            return 0;
        
        if(dp[index1][index2] != -1)
            return dp[index1][index2];
        
        //include
        int include = 0;
        if(s[index1] == t[index2])
            include = solve(s, t, index1+1, index2+1, dp);
        
        //exclude
        int exclude = solve(s, t, index1+1, index2, dp);

        return dp[index1][index2] = include + exclude;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return solve(s, t, 0, 0, dp);
    }
};