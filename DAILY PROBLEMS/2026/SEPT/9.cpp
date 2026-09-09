// 3871. Count Commas in Range II
class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long zero = 0;
        if(n == pow(10, 15))
            ans = 1;

        return ans + max(zero, n - 999) + max(zero, n - 999999) + max(zero, n - 999999999) + max(zero, n - 999999999999);
    }
};