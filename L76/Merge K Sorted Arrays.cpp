// time O(nk*logk)   where n is size of each array and k is no of arrays
// space nk for ans array and k for heap so overall O(nk)
#include <bits/stdc++.h>
class node
{
public:
  int data;
  int arr;
  int index;
};
class compare
{
public:
  bool operator()(node &a, node &b)
  {
    return a.data > b.data;
  }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
  priority_queue<node, vector<node>, compare> minHeap;

  vector<int> ans;

  for (int i = 0; i < k; i++)
  {
    node temp;
    temp.data = kArrays[i][0];
    temp.arr = i;
    temp.index = 0;
    minHeap.push(temp);
  }

  while (minHeap.size() > 0)
  {
    node mini = minHeap.top();
    minHeap.pop();
    int data = mini.data;
    int arr = mini.arr;
    int index = mini.index;

    ans.push_back(data);
    index++;

    if (index < kArrays[arr].size())
    {
      node temp;
      temp.data = kArrays[arr][index];
      temp.arr = arr;
      temp.index = index;
      minHeap.push(temp);
    }
  }
  return ans;
}
