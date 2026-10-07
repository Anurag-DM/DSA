// 856. Score of Parentheses
// Time : O(n)
// Space : O(1)

class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> brack(27, 0);

        int lvl = 0, temp = 0, ans = 0;
        stack<int> st;

        for(char c : s){
            if(c == '('){
                st.push(++lvl);
            }
            else{
                int level = st.top();
                st.pop();

                brack[level] += max(2 * brack[level + 1], 1);
                brack[level + 1] = 0;

                lvl--;
            }
        }

        return brack[1];
    }
};