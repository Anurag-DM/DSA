class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int ls = 0, rs = 0;
        int lb = 0, rb = 0;

        // Left half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                lb++;
            else
                ls += num[i] - '0';
        }

        // Right half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rb++;
            else
                rs += num[i] - '0';
        }

        // Odd number of ? -> Alice wins
        if ((lb + rb) % 2)
            return true;

        // Cancel equal number of ? from both sides
        int mini = min(lb, rb);
        lb -= mini;
        rb -= mini;

        if (lb > 0) {
            // More ? on the left
            if (ls > rs)
                return true;

            if (9 * (lb / 2) == rs - ls)
                return false;
            else
                return true;
        }
        else {
            // More ? on the right
            if (rs > ls)
                return true;

            if (9 * (rb / 2) == ls - rs)
                return false;
            else
                return true;
        }
    }
};