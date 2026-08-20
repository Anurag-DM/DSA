#include<iostream>
using namespace std;
/*void fun(int arr[]){
    cout<<arr[0]<<" ";
}
int main(){
    int arr[]={11,12,13,14};
    fun(arr+1);
    cout<<arr[0]<<endl;
}

//eg2
void update(int *p){
    int a=70;
    p=&a;
    *p=(*p)*(*p);
}
int main(){
    int a=70;
    update(&a);
    cout<<a<<endl;

}
    */
//eg3
int main(){
    int first=10;
    int *p=&first;
    int **q=&p;
    int second=20;
    *q=&second;
    (*p)++;
    cout<<first<<" "<<second<<endl;

}