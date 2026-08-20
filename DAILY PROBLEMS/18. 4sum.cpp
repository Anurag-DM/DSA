class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int k = j + 1;
        int l = n - 1;

        while (k < l)
        {
          long long temp = (long long)nums[i] + nums[j] + nums[k] + nums[l];
          if (temp == target)
          {
            ans.insert({nums[i], nums[j], nums[k], nums[l]});
            k++;
            l--;
          }
          else if (temp > target)
            l--;
          else
            k++;
        }
      }
    }

    vector<vector<int>> res;
    for (auto &i : ans)
    {
      res.push_back(i);
    }

    return res;
  }
};