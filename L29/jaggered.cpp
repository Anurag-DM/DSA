#include<iostream>
using namespace std;
int main(){
    cout<<"Enter no of rows:";
    int r;
    cin>>r;
    int** arr=new int*[r];
    int* c=new int[r];
    for(int i=0;i<r;i++){
        cout<<"Enter no of cols:";
        cin>>c[i];
        arr[i]=new int[c[i]];
    }
    //taking input
    for(int i=0;i<r;i++){
        for(int j=0;j<c[i];j++){
            cout<<"Enter element:";
            cin>>arr[i][j];
        }
    }

    //displaying output
    for(int i=0;i<r;i++){
        for(int j=0;j<c[i];j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //freeing memory
    for(int i=0;i<r;i++){
        delete [] arr[i];
    }
    delete [] arr;
    delete [] c;

    return 0;
}