// 3360. Stone Removal Game
// Time : O(1)
// Space : O(1)
class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        bool ans = false;

        while(n - remove >= 0){
            ans = !ans;
            n -= remove;
            remove--;
        }

        return ans;
    }
};