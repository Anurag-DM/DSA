// 921. Minimum Add to Make Parentheses Valid
// Time : O(n)
// Space : O(1)

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, add = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    add++;
                }
            }
        }
        return add + open;
    }
};


// Time: O(n)
// Space : O(n) where n is the length of the string
// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         stack<char> st;
//         int ans = 0;

//         for(char c: s){
//             if(c == '(')
//                 st.push(c);
//             else{
//                 if(st.empty())
//                     ans++;
//                 else
//                     st.pop();
//             }
//         }

//         while(!st.empty()){
//             ans++;
//             st.pop();
//         }

//         return ans;
//     }
// };
