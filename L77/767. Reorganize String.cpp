class Solution
{
public:
  string reorganizeString(string s)
  {
    unordered_map<char, int> mp;

    for (char c : s)
    {
      mp[c]++;
    }

    priority_queue<pair<int, char>> maxHeap;

    for (auto i : mp)
    {
      maxHeap.push({i.second, i.first});
    }

    string ans = "";
    while (maxHeap.size() > 1)
    {
      auto temp1 = maxHeap.top();
      maxHeap.pop();

      auto temp2 = maxHeap.top();
      maxHeap.pop();

      ans.push_back(temp1.second);
      ans.push_back(temp2.second);

      int freq1 = temp1.first - 1;
      int freq2 = temp2.first - 1;

      if (freq1 != 0)
        maxHeap.push({freq1, temp1.second});

      if (freq2 != 0)
        maxHeap.push({freq2, temp2.second});
    }

    if (maxHeap.size() == 1)
    {
      auto temp = maxHeap.top();
      if (temp.first > 1)
        return "";
      else
        ans.push_back(temp.second);
    }

    return ans;
  }
};