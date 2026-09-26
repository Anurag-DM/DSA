bool isPossible(vector<int> &stalls, int k, int mid){
    int cows = 1;
    int s = stalls[0];
    for(int i = 1; i<stalls.size(); i++){
        int diff = stalls[i] - s;

        if(diff >= mid){
            cows++;
            s = stalls[i];
        }

        if(cows >= k)
            return true;
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int s = 0, e = stalls[n - 1] - stalls[0];

    int ans = -1;

    while(s <= e){
        int mid = s + (e-s) / 2;

        if(isPossible(stalls, k, mid)){
            ans = mid;
            s = mid +1;
        }
        else{
            e = mid - 1;
        }
    }

    return ans;
}