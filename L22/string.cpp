#include<iostream>
//#include<string>
using namespace std;
int main(){
    char c[7]={'a','b', 'c','\0','d','e','\0'};
    string s="abc\0de\0";
    cout<<"Char Array="<<c<<endl;
    cout<<"String="<<s<<endl;
    return 0;
}