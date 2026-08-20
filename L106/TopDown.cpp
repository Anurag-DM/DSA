class Solution
{
public:
    long long int solve(vector<int> &valueInHouse, int index, int size, vector<long long int> &dp)
    {
        if (index >= size)
            return 0;
        if (dp[index] != -1)
            return dp[index];

        int inc = valueInHouse[index] + solve(valueInHouse, index + 2, size, dp);
        int exc = 0 + solve(valueInHouse, index + 1, size, dp);

        return dp[index] = max(inc, exc);
    }
    int rob(vector<int> &valueInHouse)
    {
        // Write your code here.
        int n = valueInHouse.size();
        if (n == 1)
            return valueInHouse[0];

        vector<long long int> dp1(n, -1);
        vector<long long int> dp2(n, -1);

        return max(solve(valueInHouse, 0, n - 1, dp1), solve(valueInHouse, 1, n, dp2));
    }
};