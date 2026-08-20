class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> v;
        int arr[51]={0};
        int count=0,index;
        deque<int> d;
        for(int i=0;i<k;i++){
            if(nums[i]<0){
                d.push_back(i);
                arr[-nums[i]]++;
            }
        }
        if(d.size()<x)
            v.push_back(0);
        else{
            count=0;
            for(index=50;index>0;index--){
                if(arr[index]>0)
                    count+=arr[index];
                if(count>=x)
                    break;
            }
            v.push_back(-index);
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i]<0){
                d.push_back(i);
                arr[-nums[i]]++;
            }
            if(!d.empty() && i-d.front()==k){
                index=nums[d.front()];
                d.pop_front();
                arr[-index]--;
            }
            if(d.size()<x)
                v.push_back(0);
            else{
                count=0;
               for(index=50;index>0;index--){
                if(arr[index]>0)
                    count+=arr[index];
                if(count>=x)
                    break;
               }
                v.push_back(-index);
            }
        }
        return v;
    }
};