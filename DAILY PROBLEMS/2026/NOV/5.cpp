// 1385. Find the Distance Value Between Two Arrays
// Time Complexity: O(N log N + M log M + N log M)
// Space Complexity: O(log N + log M) sort() uses O(log N) auxiliary space in the worst case
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        int n = arr2.size();

        for(int i : arr1){
            auto it = upper_bound(arr2.begin(), arr2.end(), i);
            int upperindex = it - arr2.begin();

            int lowerindex = upperindex - 1;

            bool flag1 = true;
            bool flag2 = true;

            if(lowerindex >= 0 && lowerindex < n && abs(i - arr2[lowerindex]) <= d)
                flag1 = false;

            if(upperindex >=0 && upperindex < n && abs(i - arr2[upperindex]) <= d)
                flag2 = false;
            
            if(flag1 && flag2)
                ans++;  
        }

        return ans;
        
    }
};