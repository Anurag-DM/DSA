class Solution
{
public:
  bool equalPartition(vector<int> &arr)
  {
    int sum = 0;
    for (int i : arr)
    {
      sum += i;
    }

    if (sum % 2 != 0)
      return false;
    int n = arr.size();

    // step1
    vector<bool> curr(sum / 2 + 1, 0);
    vector<bool> next(sum / 2 + 1, 0);

    // step2
    next[0] = true;

    // step3
    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int s = 0; s <= sum / 2; s++)
      {
        // include
        bool inc = false;
        if (s - arr[ind] >= 0)
          inc = next[s - arr[ind]];

        // exclude
        bool exc = next[s];

        curr[s] = inc || exc;
      }
      next = curr;
    }

    return curr[sum / 2];
  }
};