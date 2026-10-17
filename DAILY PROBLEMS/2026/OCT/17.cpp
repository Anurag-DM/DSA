// 3551. Minimum Swaps to Sort by Digit Sum
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
    static int calcsum(int x) {
        int s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        int x = calcsum(a.first), y = calcsum(b.first);
        if (x != y) return x < y;
        return a.first < b.first;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end(), cmp);

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || a[i].second == i)
                continue;

            int j = i, cnt = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = a[j].second;
                cnt++;
            }

            ans += cnt - 1;
        }

        return ans;
    }
};