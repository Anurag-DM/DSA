// 3723. Maximize Sum of Squares of Digits
// Time : O(num)
// Space : O(1)

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        for(int i = 1; i<= num; i++){
            if(sum > 9){
                sum -= 9;
                ans.push_back('9');
            }
            else{
                char c = sum + 48;
                ans.push_back(c);
                sum = 0;
            }
        }

        if(sum > 0)
            return "";

        return ans;
    }
};