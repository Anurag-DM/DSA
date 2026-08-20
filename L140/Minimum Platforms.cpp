//time O(nlogn)  space O(1)
class Solution
{
public:
  int minPlatform(vector<int> &arr, vector<int> &dep)
  {

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platform = 0, ans = 0;
    int i = 0, j = 0, n = arr.size();

    while (i < n && j < n)
    {
      if (arr[i] <= dep[j])
      {
        platform++;
        ans = max(ans, platform);
        i++;
      }
      else
      {
        platform--;
        j++;
      }
    }
    return ans;
  }
};
