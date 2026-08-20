#include<iostream>
using namespace std;

/*int getSum(int *arr, int size) {

    //base case
    if(size == 0) {
        return 0;
    }
    if(size == 1 )
    {
        return arr[0];
    }

    int remainingPart = getSum(arr+1, size-1);
    int sum = arr[0] + remainingPart;
    return sum;
}*/
int getSum(int *arr,int size,int ans){
    if(size==0)
        return ans;
    ans+=arr[0];
    return getSum(arr+1,size-1,ans);
}

int main() {

    int arr[5] = {2,4,9,9,9};
    int size = 5;

    int sum = getSum(arr, size,0);

    cout << "Sum is " << sum << endl;

    return 0;
}