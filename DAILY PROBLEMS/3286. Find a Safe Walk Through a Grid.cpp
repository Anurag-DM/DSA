class Solution
{
    bool solve(vector<vector<int>> &grid, int health, int i, int j, int m, int n, vector<vector<bool>> &vis, vector<vector<vector<int>>> &dp)
    {

        if (i < 0 || j < 0 || i == m || j == n || vis[i][j])
            return false;

        if (grid[i][j] == 1)
            health--;

        if (health == 0)
            return false;

        if (dp[i][j][health] != -1)
            return dp[i][j][health];

        vis[i][j] = true;

        if (i == m - 1 && j == n - 1 && health > 0)
            return true;

        bool up = solve(grid, health, i - 1, j, m, n, vis, dp);
        bool down = solve(grid, health, i + 1, j, m, n, vis, dp);
        bool left = solve(grid, health, i, j - 1, m, n, vis, dp);
        bool right = solve(grid, health, i, j + 1, m, n, vis, dp);

        vis[i][j] = false;

        return dp[i][j][health] = up || down || left || right;
    }

public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));

        return solve(grid, health, 0, 0, m, n, vis, dp);
    }
};