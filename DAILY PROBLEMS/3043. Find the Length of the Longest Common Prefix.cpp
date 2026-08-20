/*TLE
class Solution {
    int prefix(int a, int b){
        int c = 0;
        string s1 = to_string(a);
        string s2 = to_string(b);

        int n1 = s1.length();
        int n2 = s2.length();

        int i = 0;

        while(i<n1 && i<n2){
            if(s1[i] == s2[i])
                c++;
            else
                break;
            i++;
        }
        return c;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxi = 0;
        for(int i:arr1){
            for(int j:arr2){
                maxi = max(maxi, prefix(i,j));
            }
        }
        return maxi;
    }
};
*/

class Solution
{
public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
  {
    unordered_set<int> st;

    // store all prefixes of arr1 in the set
    for (int x : arr1)
    {
      while (x > 0)
      {
        st.insert(x);
        x /= 10;
      }
    }

    // compare these prefixes with arr2 to find largest

    int ans = 0;

    for (int x : arr2)
    {
      while (x > 0)
      {
        if (st.count(x))
        {
          ans = max(ans, (int)log10(x) + 1);
          break;
        }

        x /= 10;
      }
    }

    return ans;
  }
};