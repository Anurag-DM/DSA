// 3963. Create Grid With Exactly One Path
// Time : O(n * m) 
// Space : O(n)
// here time and space can be O(1) as n and m are max 25
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;

        string row = ".";
        string last = ".";

        for(int i = 1; i<n; i++){
            row.push_back('#');
            last.push_back('.');
        }

        for(int i = 0; i < m-1; i++){
            ans.push_back(row);
        }

        ans.push_back(last);

        return ans;
    }
};