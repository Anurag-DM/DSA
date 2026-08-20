/*class Solution {
    void check(vector<string> &nums,string &ans,int n,string str){
        if(str.length()==n){
            if(find(nums.begin(),nums.end(),str)==nums.end()){
                ans=str;
            }
            return;
        }
        check(nums,ans,n,str+"0");
        check(nums,ans,n,str+"1");
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        int n=nums.size();
        string str="";
        check(nums,ans,n,str);
        return ans;
    }
};*/
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            // Flip the diagonal bit
            ans += (nums[i][i] == '0') ? '1' : '0';
        }

        return ans;
    }
};
