class Solution
{
public:
  int rob(vector<int> &valueInHouse)
  {
    int prev2 = valueInHouse[0];
    int n = valueInHouse.size();
    if (n == 1)
      return prev2;
    int prev1 = max(valueInHouse[1], valueInHouse[0]);
    if (n == 2)
      return prev1;

    for (int i = 2; i < n - 1; i++)
    {
      int incl = prev2 + valueInHouse[i];
      int excl = prev1;
      int curr = max(incl, excl);
      prev2 = prev1;
      prev1 = curr;
    }

    int ans1 = prev1;

    prev2 = valueInHouse[1];
    prev1 = max(valueInHouse[1], valueInHouse[2]);
    for (int i = 3; i < n; i++)
    {
      int incl = prev2 + valueInHouse[i];
      int excl = prev1;
      int curr = max(incl, excl);
      prev2 = prev1;
      prev1 = curr;
    }
    int ans2 = prev1;

    return max(ans1, ans2);
  }
};