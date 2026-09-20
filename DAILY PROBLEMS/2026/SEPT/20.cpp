// 3498. Reverse Degree of a String
// Time: O(n) where n is the length of the string
// Space: O(1)
class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for(int i = 0; i<s.length(); i++){
            ans += (i+1) * ( 'z' - s[i] + 1);
        }

        return ans;
    }
};
