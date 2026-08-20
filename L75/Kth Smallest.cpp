//Time	O(n log k) Space	O(k)
class Solution
{
public:
  int kthSmallest(vector<int> &arr, int k)
  {
    priority_queue<int> pq;

    int i;
    for (i = 0; i < k; i++)
    {
      pq.push(arr[i]);
    }

    while (i < arr.size())
    {
      if (arr[i] < pq.top())
      {
        pq.pop();
        pq.push(arr[i]);
      }
      i++;
    }

    return pq.top();
  }
};