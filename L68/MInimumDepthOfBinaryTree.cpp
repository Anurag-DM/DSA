/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
  void solve(TreeNode *root, int &ans, int c)
  {
    if (root == NULL)
      return;
    c++;
    if (root->left == NULL && root->right == NULL)
    {
      if (c < ans)
        ans = c;
      return;
    }
    solve(root->left, ans, c);
    solve(root->right, ans, c);
  }

public:
  int minDepth(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    int ans = INT_MAX;
    solve(root, ans, 0);
    return ans;
  }
};
/*
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int depth=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                if(!node->left && !node->right){
                    return depth;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            depth++;
        }
        return depth;
    }
};*/