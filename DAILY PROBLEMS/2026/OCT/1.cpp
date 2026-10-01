// 20. Valid Parentheses
// Time : O(n) where n is length of the string
// Space : O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c: s){
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else if(c == ')'){
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
            }
            else if(c == '}'){
                if(!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return false;
            }
            else if(c == ']'){
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty() ? true : false;
    }
};