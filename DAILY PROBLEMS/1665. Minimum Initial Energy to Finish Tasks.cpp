class Solution
{
public:
  int minimumEffort(vector<vector<int>> &tasks)
  {
    sort(tasks.begin(), tasks.end(), [](auto &a, auto &b)
         { return (a[1] - a[0]) > (b[1] - b[0]); });

    int ans = 0;
    int temp = 0;
    for (auto &i : tasks)
    {
      if (i[1] > temp)
      {
        ans += i[1] - temp;
        temp = i[1];
        temp -= i[0];
      }
      else
      {
        temp -= i[0];
      }
    }
    return ans;
  }
};