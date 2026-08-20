/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    void solve(Node* root,map<int,vector<int>> &m,int hd){
        if(root==NULL)
            return;
        m[hd].push_back(root->data);
        solve(root->left,m,hd+1);
        solve(root->right,m,hd);
    }
  public:
    vector<int> diagonal(Node *root) {
        // code here
        vector<int> v;
        
        map<int,vector<int>> m;
        if(root==NULL)
            return v;
        solve(root,m,0);
        for(auto i:m){
            for(int j:i.second){
                v.push_back(j);
            }
        }
        return v;
    }
};