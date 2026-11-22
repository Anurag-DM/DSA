// 2124. Check if All A's Appears Before All B's
// Time : O(n)
// Space : O(1)
class Solution {
public:
    bool checkString(string s) {
        int lasta = -1, firstb = -1;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a')
                lasta = i;
            else if(s[i] == 'b' && firstb == -1)
                firstb = i;
        }

        if(lasta == -1 || firstb == -1)
            return true;
        
        if(lasta > firstb)
            return false;
        
        return true;
    }
};