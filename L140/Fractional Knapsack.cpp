// Time	O(n log n)
//  Space	O(n)
class Solution
{
public:
  static bool cmp(pair<double, pair<int, int>> &a, pair<double, pair<int, int>> &b)
  {
    return a.first > b.first;
  }
  double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
  {
    vector<pair<double, pair<int, int>>> v;

    for (int i = 0; i < wt.size(); i++)
    {
      double perunitVal = 1.0 * val[i] / wt[i];
      v.push_back({perunitVal, {wt[i], val[i]}});
    }

    sort(v.begin(), v.end(), cmp);

    double totalval = 0;
    for (int i = 0; i < wt.size(); i++)
    {
      int weight = v[i].second.first;
      int value = v[i].second.second;
      double perVal = v[i].first;

      if (weight <= capacity)
      {
        totalval += value;
        capacity -= weight;
      }
      else
      {
        totalval += perVal * capacity;
        break;
      }
    }

    return totalval;
  }
};
