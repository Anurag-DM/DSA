// 835. Image Overlap
// Time complexity : O(n^4)
// Space Complexity : O(n^2)
class Solution {
    void solve(vector<vector<int>> &img2, vector<pair<int, int>> &v, int &ans, int &n, int tracki, int trackj, vector<vector<bool>> &vis ){
        if(tracki < 0 || tracki == 2*n - 1 || trackj < 0 || trackj == 2*n - 1 || vis[tracki][trackj])
            return;
        
        vis[tracki][trackj] = true;
        
        int count = 0;
        for(auto &p: v){
            int sideways = tracki - (n - 1); // because n - 1 is the starting index, this will show left or right movement

            int updown = trackj - (n-1); // similarly this will show up or down


            int i = p.first + sideways;
            int j = p.second + updown;

            if(i>=0 && i<n && j<n && j>=0 && img2[i][j] == 1)
                count++;
        }

        ans = max(ans, count);

        //left
        solve(img2, v, ans, n, tracki, trackj - 1, vis);

        //right
        solve(img2, v, ans, n, tracki, trackj + 1, vis);

        //up
        solve(img2, v, ans, n, tracki - 1, trackj, vis);

        //down
        solve(img2, v, ans, n, tracki + 1, trackj, vis);
        
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

        solve(img2, v, ans, n, n-1, n-1, vis); // to make the left side indices as non negative I have considered the original 0,0 index as n-1, n-1 index

        return ans;
    }
};