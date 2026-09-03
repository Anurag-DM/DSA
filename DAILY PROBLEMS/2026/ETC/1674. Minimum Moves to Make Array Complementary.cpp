// time O(n + limit)
class Solution
{
public:
  int minMoves(vector<int> &nums, int limit)
  {

    int n = nums.size();

    // Difference array
    vector<int> diff(2 * limit + 2, 0);

    for (int i = 0; i < n / 2; i++)
    {

      int a = nums[i];
      int b = nums[n - 1 - i];

      int low = min(a, b) + 1;
      int high = max(a, b) + limit;
      int sum = a + b;

      /*
          Initially assume:
          every target sum needs 2 moves
      */
      diff[2] += 2;

      /*
          For sums in [low, high]
          only 1 move is needed
      */
      diff[low] -= 1;
      diff[high + 1] += 1;

      /*
          Exact current sum needs 0 moves
      */
      diff[sum] -= 1;
      diff[sum + 1] += 1;
    }

    int ans = INT_MAX;
    int curr = 0;

    // Prefix sum to compute moves for every target sum
    for (int target = 2; target <= 2 * limit; target++)
    {
      curr += diff[target];
      ans = min(ans, curr);
    }

    return ans;
  }
};
/*TLE
class Solution {
    int solve(vector<int> &nums, int ind, int limit, int sum){
        if(ind == nums.size()/2)
            return 0;

        int a = nums[ind];
        int b = nums[nums.size() - 1 - ind];

        if(a+b == sum)
            return solve(nums, ind+1, limit, sum);
        else{
            int diff = sum - (a+b);
            if((a + diff>=1 && a+diff<=limit) || (b+diff>=1 && b+diff<=limit))
                return 1 + solve(nums, ind+1, limit, sum);
            else
                return 2 + solve(nums, ind+1, limit, sum);
        }

    }
public:
    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        int mini = INT_MAX;
        for(int i=2; i<=2*limit; i++){
            mini = min(mini, solve(nums, 0, limit, i));
        }

        return mini;
    }
};*/