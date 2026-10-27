// 3619. Count Islands With Total Value Divisible by K
// Time : O(m * n)
// Space : O(m * n)
class Solution {
    void solve(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j, int m, int n, long long &sum){
        if(i < 0 || i >= m || j<0 || j>=n || grid[i][j] == 0 || vis[i][j])
            return;
        
        sum += grid[i][j];
        vis[i][j] = true;

        //left
        solve(grid, vis, i, j-1, m, n, sum);

        // right
        solve(grid, vis, i, j+1, m, n, sum);

        //up
        solve(grid, vis, i-1, j, m, n, sum);

        // down
        solve(grid, vis, i+1, j, m, n, sum);
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ans = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    long long sum = 0;
                    solve(grid, vis, i, j, m, n, sum);
                    if(sum % k == 0)
                        ans++;
                }
            }
        }

        return ans;

    }
};