//Time:O(n+m)
//Space:O(n+m)
#include <bits/stdc++.h>
void heapify(vector<int> &ans, int i, int size)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < size && ans[left] > ans[largest])
    largest = left;
  if (right < size && ans[right] > ans[largest])
    largest = right;

  if (largest != i)
  {
    swap(ans[i], ans[largest]);
    heapify(ans, largest, size);
  }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
  vector<int> ans;

  // step1: merge 2 arrays
  for (int i : arr1)
    ans.push_back(i);
  for (int i : arr2)
    ans.push_back(i);

  // step2: build heap and heapify
  int size = ans.size();
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(ans, i, size);
  }

  return ans;
}