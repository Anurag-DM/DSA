class Solution
{
  int solve(vector<int> &obs, int pos, int lane)
  {
    if (pos == obs.size() - 1)
    {
      return 0;
    }

    if (obs[pos + 1] != lane)
    {
      return solve(obs, pos + 1, lane);
    }
    else
    {
      int mini = INT_MAX;
      for (int i = 1; i <= 3; i++)
      {
        if (i != lane && obs[pos] != i)
        {
          mini = min(mini, 1 + solve(obs, pos, i));
        }
      }
      return mini;
    }
  }

public:
  int minSideJumps(vector<int> &obstacles)
  {
    return solve(obstacles, 0, 2);
  }
};