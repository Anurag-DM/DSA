// 1021. Remove Outermost Parentheses
// Time : O(n) where n is length of string
// Space : O(1)

class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string ans = "";

        for(char c : s){
            if(c == '('){
                if(open != 0)
                    ans.push_back(c);
                
                open++;
            }
            else{
                open--;
                if(open != 0)
                    ans.push_back(c);
            }
        }

        return ans;
    }
};