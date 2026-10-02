// 22. Generate Parentheses
// Time : O(4^n / sqrt(n) )
// Space : O(n) because max n opening brackets can be in the stack

class Solution {
    void solve(vector<string> &ans, int openbr, int closebr, string &s, stack<char> &st){
        if(openbr == 0 && closebr == 0){
            if(st.empty())
                ans.push_back(s);
            
            return;
        }

        if(openbr > 0){
            st.push('(');
            s.push_back('(');
            solve(ans, openbr - 1, closebr, s, st);
            s.pop_back();
            st.pop();
        }

        if(closebr > 0){
            if(st.empty())
                return;
            else{
                st.pop();
                s.push_back(')');
                solve(ans, openbr, closebr - 1, s, st);
                st.push('(');
                s.pop_back();
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        stack<char> st;

        solve(ans, n, n, s, st);

        return ans;
    }
};