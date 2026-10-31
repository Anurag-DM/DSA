// 3665. Twisted Mirror Path Count
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

#define MOD 1000000007
class Solution {
    int solve(vector<vector<int>>& grid, int m, int n, int i, int j, bool jump, vector<vector<int>> &dp){
        if(i >= m || i < 0 || j >= n || j < 0)
            return 0;
        
        if(i == m - 1 && j == n - 1)
            return 1;
        
        if(grid[i][j] == 0 && dp[i][j] != -1)
            return dp[i][j];
        
        int right = 0, down = 0;

        if(grid[i][j] == 0 || jump)
            right = solve(grid, m, n, i, j + 1, false, dp);
        
        if(grid[i][j] == 0 || !jump)
            down = solve(grid, m, n, i + 1, j, true, dp);

        return dp[i][j] = (right + down) % MOD;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return (solve(grid, m, n, 0, 1, false, dp) + solve(grid, m, n, 1, 0, true, dp)) % MOD; // false means right and true means down
    }
};