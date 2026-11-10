// 3693. Climbing Stairs II
// Time : O(n)
// Space : O(1)
class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        int prev3 = 0;
        int prev2 = cost[0] + 1;
        if(n == 1)
            return prev2;
        
        int prev1 = min(cost[1] + 4, prev2 + cost[1] + 1);

        for(int i = 3; i<=n; i++){
            int one = prev1 + cost[i - 1] + 1;
            int two = prev2 + cost[i - 1] + 4;
            int three = prev3 + cost[i - 1] + 9;

            prev3 = prev2;
            prev2 = prev1;
            prev1 = min({one, two, three});
        }

        return prev1;
    }
};