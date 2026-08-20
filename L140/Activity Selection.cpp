class Solution
{
public:
  int activitySelection(vector<int> &start, vector<int> &finish)
  {
    int n = start.size();
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
      v.push_back({start[i], finish[i]});
    }

    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second < b.second; });

    int prev = -1, count = 0;
    for (int i = 0; i < n; i++)
    {
      if (v[i].first > prev)
      {
        count++;
        prev = v[i].second;
      }
    }
    return count;
  }
};