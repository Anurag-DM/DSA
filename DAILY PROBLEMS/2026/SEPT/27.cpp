// 1190. Reverse Substrings Between Each Pair of Parentheses
// Time : O(N2)
// Space : O(N)

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string temp;

        for(char c : s){
            if( c != ')')
                st.push(c);
            else{
                temp.clear();
                while(!st.empty()){
                    char c = st.top();
                    st.pop();

                    if(c == '(')
                        break;

                    temp.push_back(c);
                }

                for(char ch : temp)
                    st.push(ch);
            }
        }

        string ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};