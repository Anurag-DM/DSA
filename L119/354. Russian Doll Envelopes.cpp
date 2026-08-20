class Solution
{
public:
  int maxEnvelopes(vector<vector<int>> &env)
  {
    sort(env.begin(), env.end(), [](vector<int> &a, vector<int> &b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0]; 
    });

    vector<int> ans;
    ans.push_back(env[0][1]);
    for (auto v : env)
    {
      if (v[1] > ans.back())
        ans.push_back(v[1]);
      else
      {
        int index = lower_bound(ans.begin(), ans.end(), v[1]) - ans.begin();
        ans[index] = v[1];
      }
    }
    return ans.size();
  }
};