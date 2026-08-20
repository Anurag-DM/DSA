// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution
{
  void heapify(vector<int> &arr, int n, int i)
  {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest])
      largest = left;

    if (right <= n && arr[right] > arr[largest])
      largest = right;

    if (largest != i)
    {
      swap(arr[largest], arr[i]);
      heapify(arr, n, largest);
    }
  }

public:
  // Function to sort an array using Heap Sort.
  void heapSort(vector<int> &arr)
  {
    // code here
    int n = arr.size();
    arr.insert(arr.begin(), -1);

    // build max heap
    for (int i = n / 2; i > 0; i--)
    {
      heapify(arr, n, i);
    }

    // heapsort
    while (n > 1)
    {
      // step1: swap
      swap(arr[n], arr[1]);

      // step2: reduce size
      n--;

      // step3: move root to correct position
      heapify(arr, n, 1);
    }

    arr.erase(arr.begin());
  }
};