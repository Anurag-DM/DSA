// 3789. Minimum Cost to Acquire Required Items
// Time : O(1)
// Space : O(1)
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        int lessNeededItem = min(need1, need2);

        if(cost1 + cost2 > costBoth){
            need1 -= lessNeededItem;
            need2 -= lessNeededItem;

            ans += 1LL * costBoth * lessNeededItem;
        }

        if(need1 > 0){
            if(cost1 > costBoth)
                ans += 1LL * need1 * costBoth;
            else
                ans += 1LL * need1 * cost1;
        }

        if(need2 > 0){
            if(cost2 > costBoth)
                ans += 1LL * need2 * costBoth;
            else
                ans += 1LL * need2 * cost2;
        }

        return ans;
    }
};