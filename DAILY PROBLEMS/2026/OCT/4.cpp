// 678. Valid Parenthesis String
// Time  : O(n)
// Space : O(n) where n is length of string

class Solution {
public:
    bool checkValidString(string s) {
        deque<int> st;
        int n = s.length();

        for(int i= 0; i<n ; i++){
            if(s[i] == '*')
                st.push_back(i);
        }

        stack<int> stk;
        for(int i = 0; i<n; i++){
            if(s[i] == '(')
                stk.push(i);
            else if(s[i] == ')'){
                if(!stk.empty())
                    stk.pop();
                else{
                    if(st.empty())
                        return false;

                    int starindex = st.front();
                    if(starindex > i)
                        return false;
                    else
                        st.pop_front(); 
                }
            }
        }

        while(!stk.empty()){
            if(st.empty())
                return false;
            
            int starindex = st.back();
            if(starindex > stk.top())
                stk.pop();
            else
                return false;
            
            st.pop_back();
        }

        return true;
    }
};