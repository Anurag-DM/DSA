// Time	O(nk log k)
// Space	O(k)
#include <bits/stdc++.h>
class node
{
public:
  int data;
  int arr;
  int index;

  node(int d, int a, int i)
  {
    data = d;
    arr = a;
    index = i;
  }
};

class cmp
{
public:
  bool operator()(node *&a, node *&b)
  {
    return a->data > b->data;
  }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
  priority_queue<node *, vector<node *>, cmp> minHeap;
  int maxi = INT_MIN;

  for (int i = 0; i < k; i++)
  {
    node *temp = new node(a[i][0], i, 0);
    minHeap.push(temp);
    maxi = max(maxi, a[i][0]);
  }

  int ans = INT_MAX;

  while (minHeap.size() > 0)
  {
    node *temp = minHeap.top();
    minHeap.pop();

    int data = temp->data;
    int arr = temp->arr;
    int ind = temp->index;

    int diff = maxi - data;
    ans = min(diff, ans);

    if (ind + 1 < n)
    {
      node *next = new node(a[arr][ind + 1], arr, ind + 1);
      minHeap.push(next);
      maxi = max(maxi, a[arr][ind + 1]);
    }
    else
    {
      break;
    }
  }
  return ans + 1;
}