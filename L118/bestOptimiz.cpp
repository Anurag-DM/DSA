// this is greedy approach not dp
// time : O(nlogn)   space: O(1)
class Solution
{
public:
  int maxSatisfaction(vector<int> &satisfaction)
  {
    sort(satisfaction.begin(), satisfaction.end());

    int suffixSum = 0;
    int total = 0;

    for (int i = satisfaction.size() - 1; i >= 0; i--)
    {
      suffixSum += satisfaction[i];

      if (suffixSum < 0)
        break;

      total += suffixSum;
    }

    return total;
  }
};