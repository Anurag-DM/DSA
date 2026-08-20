class Solution
{
  int solve(int dices, int faces, int target)
  {
    // base cases
    if (target < 0)
      return 0;
    if (dices == 0 && target != 0)
      return 0;
    if (dices != 0 && target == 0)
      return 0;
    if (dices == 0 && target == 0)
      return 1;

    int ans = 0;
    for (int i = 1; i <= faces; i++)
    {
      ans += solve(dices - 1, faces, target - i);
    }
    return ans;
  }

public:
  int noOfWays(int m, int n, int x)
  {
    // code here
    return solve(n, m, x);
  }
};