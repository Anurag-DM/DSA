#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        uint32_t x = 0;
        for (int v : nums) x ^= (uint32_t)v;      // XOR all -> a ^ b (unsigned)

        uint32_t mask = x & (~x + 1);             // rightmost set bit (unsigned-safe)

        int a = 0, b = 0;
        for (int v : nums) {
            if (((uint32_t)v) & mask) a ^= v;     // group 1
            else                     b ^= v;      // group 2
        }
        return {a, b};                            // order doesn't matter
    }
};
