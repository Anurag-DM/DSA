class Solution {
    void solve(vector<vector<bool>> &vis, vector<vector<int>>& grid, bool &cond, int i, int j, int m, int n){
        if( i < 0 || i >= m || j < 0 || j >= n){
            cond = false;
            return;
        }

        if(grid[i][j] == 1 || vis[i][j])
            return;
        
        vis[i][j] = true;

        //left call
        solve(vis, grid, cond, i, j-1, m, n);

        //right call
        solve(vis, grid, cond, i, j+1, m, n);

        //up
        solve(vis, grid, cond, i-1, j, m, n);

        //down
        solve(vis, grid, cond, i+1, j, m, n);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int ans = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    bool cond = true;

                    solve(vis, grid, cond, i, j, m, n);

                    if(cond)
                        ans++;
                }
            }
        }

        return ans;
    }
};