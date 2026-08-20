/*MY COMMENTED CODE IS MORE OPTIMIZED
#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Write your code here.
	deque<int> maxi(k);
	deque<int> mini(k);
	for(int i=0;i<k;i++){
		while(!maxi.empty() && nums[i]>=nums[maxi.back()])
			maxi.pop_back();
		maxi.push_back(i);

		while(!mini.empty() && nums[i]<=nums[mini.back()])
			mini.pop_back();
		mini.push_back(i);
	}
	long long sum=(long long)nums[maxi.front()]+nums[mini.front()];
	for(int i=k;i<n;i++){
		if(i-maxi.front()==k)
			maxi.pop_front();
		if(i-mini.front()==k)
			mini.pop_front();
		while(!maxi.empty() && nums[i]>=nums[maxi.back()])
			maxi.pop_back();
		maxi.push_back(i);
		while(!mini.empty() && nums[i]<=nums[mini.back()])
			mini.pop_back();
		mini.push_back(i);
		sum+=(long long)nums[maxi.front()]+nums[mini.front()];
	}
	return sum;
}

*/
#include<iostream>
#include<queue>
using namespace std;

int solve(int *arr, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    //Addition of first k size window

    for(int i=0; i<k; i++) {

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {

        

        //next window

        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);    

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main() {


    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;


    return 0;
}