class Solution
{
public:
  vector<int> maxMeetings(vector<int> &s, vector<int> &f)
  {
    // code here
    vector<pair<int, pair<int, int>>> v;

    for (int i = 0; i < s.size(); i++)
    {
      v.push_back({i + 1, {s[i], f[i]}});
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b)
         { return a.second.second < b.second.second; });

    int prevEnd = -1;
    vector<int> ans;
    for (auto &i : v)
    {
      if (i.second.first > prevEnd)
      {
        ans.push_back(i.first);
        prevEnd = i.second.second;
      }
    }

    sort(ans.begin(), ans.end());
    return ans;
  }
};