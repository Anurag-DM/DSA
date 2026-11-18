// 2914. Minimum Number of Changes to Make Binary String Beautiful
// Time : O(n)
// Space : O(1)
class Solution {
public:
    int minChanges(string s) {
        int count = 1;
        int ans = 0;

        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i - 1])
                count++;
            else{
                if(count % 2 == 1){
                    count = 0;
                    ans++;
                }
                else
                    count = 1;
            }
        }

        return ans;
    }
};