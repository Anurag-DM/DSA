class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, pair<int,bool>> mp;

        for(int i:nums){
            mp[i].first++;
        }

        for(int i:nums){
            long long sq = 1LL*i*i;
            if(mp.find(sq)!=mp.end())
                mp[i].second = true;
        }

        int ans = 1;

        for(int i:nums){
            int count = 0;
            long long temp = i;

            while(temp!=1 && mp.find(temp)!=mp.end() && mp[temp].first>=2 && mp[temp].second){
                count +=2;
                temp = temp * temp;
            }

            if(mp.find(temp)!=mp.end())
                count += 1;
            else
                count -= 1;
            
            ans = max(ans, count);
        }

        if(mp.find(1)!= mp.end()){
            int freq = mp[1].first;
            
            if(freq % 2==0)
                ans = max(ans, freq-1);
            else
                ans = max(ans, freq);
        }
        
        return ans;
    }
};