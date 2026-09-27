#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    // Compare elements from both halves
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Remaining elements of left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Remaining elements of right half
    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back
    for (int k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    // Sort left half
    mergeSort(arr, low, mid);

    // Sort right half
    mergeSort(arr, mid + 1, high);

    // Merge both halves
    merge(arr, low, mid, high);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";

    return 0;
}