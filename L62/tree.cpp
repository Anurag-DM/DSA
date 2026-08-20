#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
        node(int data){
            this->data=data;
            left=right=nullptr;
        }
};

node* BuildTree(node* root){
    cout<<"Enter data:";
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)
        return nullptr;
    cout<<"Enter data for left child of data "<<data<<":"<<endl;
    root->left=BuildTree(root->left);
    cout<<"Enter data for right child of data "<<data<<":"<<endl;
    root->right=BuildTree(root->right);
    return root;
}
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}
void reverseLevelOrderTraversal(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        s.push(temp);
        if(temp==NULL){
            if(!q.empty())
                q.push(NULL);
        }
        else{
            if(temp->right)
                q.push(temp->right);
            if(temp->left)  
                q.push(temp->left);
        }
    }
    s.pop();
    while(!s.empty()){
        if(s.top()==NULL)
            cout<<endl;
        else    
            cout<<s.top()->data<<" ";
        s.pop();
    }
}
int main(){
    node* root=NULL;
    root=BuildTree(root);
    cout<<endl;
    levelOrderTraversal(root);
    reverseLevelOrderTraversal(root);
    return 0;
}
//1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 -1