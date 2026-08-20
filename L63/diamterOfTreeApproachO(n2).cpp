/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    int height(Node* root){
        if(root==NULL)
            return 0;
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
  public:
    int diameter(Node* root) {
        if(root==NULL)
            return 0;
        int op1=diameter(root->left);
        int op2=diameter(root->right);
        int op3=height(root->left)+height(root->right);
        int ans=max(op1,max(op2,op3));
        return ans;
    }
};
/*This is O(n) approach
class Solution {
  private:
    pair<int,int> diameterFast(Node* root){
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int> left=diameterFast(root->left);
        pair<int,int> right=diameterFast(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second;
        
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
        
    }
  public:
    int diameter(Node* root) {
        // code here
        return diameterFast(root).first;
    }
};
*/