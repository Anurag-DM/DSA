// 835. Image Overlap
// Time complexity : O(n^4)
// Space Complexity : O(n^2)
class Solution {
    void solve(vector<vector<int>> &img2, vector<pair<int, int>> &v, int &ans, int &n, int left, int right, int up, int down, int tracki, int trackj, vector<vector<bool>> &vis ){
        if(left == n || right == n || up == n || down == n || vis[tracki][trackj])
            return;
        
        vis[tracki][trackj] = true;
        
        int count = 0;
        for(auto &p: v){
            int i = p.first - left + right;
            int j = p.second - up + down;

            if(i>=0 && i<n && j<n && j>=0 && img2[i][j] == 1)
                count++;
        }

        ans = max(ans, count);

        //left
        solve(img2, v, ans, n, left + 1, right, up, down, tracki, trackj - 1, vis);

        //right
        solve(img2, v, ans, n, left, right + 1, up, down, tracki, trackj + 1, vis);

        //up
        solve(img2, v, ans, n, left, right, up + 1, down, tracki - 1, trackj, vis);

        //down
        solve(img2, v, ans, n, left, right, up, down + 1, tracki + 1, trackj, vis);
        

    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        int ans = 0;

        vector<pair<int, int>> v;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(img1[i][j] == 1)
                    v.push_back({i, j});
            }
        }

        vector<vector<bool>> vis(2*n - 1, vector<bool>(2*n - 1, false));

        solve(img2, v, ans, n, 0, 0, 0, 0, n-1, n-1, vis);

        return ans;
    }
};