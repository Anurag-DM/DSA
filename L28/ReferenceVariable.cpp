#include<iostream>
using namespace std;

int& func(int a) {
    int num = a;
    int& ans = num;
    return ans;
}//this is bad practice because the reference variable is referring to local variable which dies after the function execution is over

int* fun(int n) {
    int* ptr = &n;
    return ptr;
}

void update2(int& n) {
    n++;
}

void update1(int n) {
    n++;
}

int main() {

    /*
    int i = 5;

    //create a ref variable 

    int& j = i;

    cout << i << endl; 
    i++;
    cout << i << endl; 
    j++;
    cout << i << endl; 
    cout << j << endl;
    */
    

   int n = 5;
   
   cout << "Before " << n << endl;
   update2(n);
   cout << "After " << n << endl;

    
    int b=func(n);
    cout<<"b="<<b<<endl;
    
    
    int *y=fun(n);
    cout<<"y="<<*y<<endl;

    return 0;
}