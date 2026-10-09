// 1541. Minimum Insertions to Balance a Parentheses String
// Time : O(n) where n is length of string
// Space : O(1)

class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;
        int n = s.length();

        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                open++;
            else{
                if(open == 0)
                    ans++;
                
                if(i + 1 == n || s[i + 1] != ')')
                    ans++;
                else
                    i++;
                
                if(open != 0)
                    open--;
            }
        }

        if(open > 0)
            ans += 2*open;

        return ans;
    }
};