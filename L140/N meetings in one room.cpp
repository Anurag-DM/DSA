class Solution
{
public:
  // Function to find the maximum number of meetings that can
  // be performed in a meeting room.
  int maxMeetings(vector<int> &start, vector<int> &end)
  {
    vector<pair<int, int>> v;

    for (int i = 0; i < start.size(); i++)
    {
      v.push_back({start[i], end[i]});
    }

    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second < b.second; });

    int prevEnd = -1, count = 0;
    for (auto &i : v)
    {
      if (i.first > prevEnd)
      {
        count++;
        prevEnd = i.second;
      }
    }
    return count;
  }
};