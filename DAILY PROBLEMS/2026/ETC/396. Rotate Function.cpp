// O(n) approach
class Solution
{
public:
  int maxRotateFunction(vector<int> &nums)
  {
    int n = nums.size();

    int sum = 0;
    int f0 = 0;

    for (int j = 0; j < n; j++)
    {
      f0 += j * nums[j];
      sum += nums[j];
    }

    int maxi = f0;
    int prev = f0;
    int curr = 0;

    for (int i = 1; i < n; i++)
    {
      curr = prev + sum - n * nums[n - i];
      maxi = max(maxi, curr);
      prev = curr;
    }

    return maxi;
  }
};

/* Brute force O(n2)
class Solution
{
public:
  int maxRotateFunction(vector<int> &nums)
  {
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      for (int j = 0; j < n; j++)
      {
        sum += j * nums[(j + i) % n];
      }
      maxi = max(maxi, sum);
    }
    return maxi;
  }
};*/
