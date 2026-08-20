//time O(nlogn)
//space O(n)
class Solution
{
public:
  int minCost(vector<int> &arr)
  {
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i : arr)
    {
      pq.push(i);
    }

    int ans = 0;
    while (pq.size() > 1)
    {
      int rope1 = pq.top();
      pq.pop();

      int rope2 = pq.top();
      pq.pop();

      int mergeCost = rope1 + rope2;
      ans += mergeCost;

      pq.push(mergeCost);
    }
    return ans;
  }
};