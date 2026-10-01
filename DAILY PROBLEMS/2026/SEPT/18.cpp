class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        // store first and last occurence of the chars
        int n = s.length();
        vector<int> first(26, n);
        vector<int> last(26, -1);

        for(int i = 0; i<n; i++){
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        for(int i = 0; i<26; i++){

            if(last[i] == -1)
                continue;

            int l = first[i];
            int r = last[i];
            bool ok = true;

            for(int j = l; j<=r; j++){
                int c = s[j] - 'a';
                
                if(l > first[c]){
                    ok = false;
                    break;
                }
                
                r = max(r, last[c]);
            }

            if(ok)
                intervals.push_back({r, l});
        }

        sort(intervals.begin(), intervals.end());

        int prevEnd = -1;
        vector<string> ans;
        for(auto [r, l] : intervals){
            if(l > prevEnd){
                ans.push_back(s.substr(l, r-l+1));
                prevEnd = r;
            }
        }

        return ans;
    }
};
