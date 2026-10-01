// 1807. Evaluate the Bracket Pairs of a String
// Time Complexity: O(N + K) average
// Space Complexity: O(N + K)

// N = length of string s
// K = number of entries in knowledge

// unordered_map operations are O(1) average.

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for(auto &i : knowledge) {
            mp[i[0]] = i[1];
        }

        string ans;
        string temp;
        bool bracket = false;

        for(char c : s) {
            if(c == '(') {
                temp.clear();
                bracket = true;
            }
            else if(c == ')') {
                bracket = false;

                auto it = mp.find(temp);

                if(it != mp.end())
                    ans += mp[temp];
                else
                    ans.push_back('?');
            }
            else if(bracket) {
                temp.push_back(c);
            }
            else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};