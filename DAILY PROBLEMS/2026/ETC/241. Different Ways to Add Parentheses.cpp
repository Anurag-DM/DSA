class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {

        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {

            if (expression[i] == '+' ||
                expression[i] == '-' ||
                expression[i] == '*') {

                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> l = diffWaysToCompute(left);
                vector<int> r = diffWaysToCompute(right);

                for (int x : l) {
                    for (int y : r) {

                        if (expression[i] == '+')
                            ans.push_back(x + y);

                        else if (expression[i] == '-')
                            ans.push_back(x - y);

                        else
                            ans.push_back(x * y);
                    }
                }
            }
        }

        // No operator means the whole expression is one number
        if (ans.empty())
            ans.push_back(stoi(expression));

        return ans;
    }
};