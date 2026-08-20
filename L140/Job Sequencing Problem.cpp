/*Approach 1  TLE  time: O(n2) space: O(n)
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int, pair<int, int>>> v;

        for(int i=0; i<deadline.size(); i++){
            v.push_back({i, {deadline[i], profit[i]}});
        }

        //sort based on profit
        sort(v.begin(), v.end(), [](pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
            return a.second.second>b.second.second;
        });

        vector<int> schedule(deadline.size()+1, -1);

        int maxProfit = 0, jobs= 0;
        for(int i=0; i<deadline.size(); i++){
            int dl = v[i].second.first;
            int prof = v[i].second.second;
            int jid = v[i].first;

            while(dl>0 && schedule[dl]!=-1)
                dl--;

            if(dl>0){
                jobs++;
                maxProfit+= prof;
                schedule[dl] = jid;
            }
        }

        vector<int> ans = {jobs, maxProfit};

        return ans;
    }
};
*/

// approach 2 using DSU
/*
✅ Time Complexity
Step 1: Build jobs vector
for(int i = 0; i < n; i++)
Cost:O(n)
Step 2: Sort jobs by profit
sort(jobs.begin(), jobs.end(), greater<>());
Cost:O(n log n)
Step 3: Initialize DSU parent array
for(int i = 0; i <= maxDeadline; i++)
Cost:O(D)
Step 4: Process each job
For each job: find() → almost O(1)  union update → almost O(1)
DSU complexity:O(α(D))

Where:
α = inverse Ackermann function (practically constant)

Total:O(n α(D)) ≈ O(n)
✅ Total Overall:
O(n log n + D)
If D ≈ n:
O(n log n)

✅ Space Complexity
Jobs vector:O(n)
Parent array:O(D)
Total:O(n + D)
If D ≈ n:  O(n)
*/

class Solution
{
  int find(vector<int> &parent, int dl)
  {
    if (parent[dl] == dl)
      return dl;
    return parent[dl] = find(parent, parent[dl]);
  }

public:
  vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
  {
    // code here
    int n = profit.size();
    vector<pair<int, int>> v;

    int maxdead = 0;
    for (int i = 0; i < deadline.size(); i++)
    {
      v.push_back({deadline[i], profit[i]});
      maxdead = max(maxdead, deadline[i]);
    }

    // sort based on profit
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second > b.second; });

    vector<int> parent(maxdead + 1);

    for (int i = 1; i <= maxdead; i++)
    {
      parent[i] = i;
    }

    int maxProfit = 0, jobs = 0;
    for (int i = 0; i < n; i++)
    {
      int dl = v[i].first;
      int prof = v[i].second;

      int availableSlot = find(parent, dl);

      if (availableSlot > 0)
      {
        maxProfit += prof;
        jobs++;
        parent[availableSlot] = find(parent, availableSlot - 1);
      }
    }

    vector<int> ans = {jobs, maxProfit};

    return ans;
  }
};