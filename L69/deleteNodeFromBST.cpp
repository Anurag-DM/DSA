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
  TreeNode *minValue(TreeNode *root)
  {
    while (root->left != NULL)
      root = root->left;
    return root;
  }

public:
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == NULL)
      return root;
    if (root->val == key)
    {
      // 0 child
      if (root->left == NULL && root->right == NULL)
      {
        delete root;
        return NULL;
      }
      // 1 child
      else if (root->left == NULL && root->right != NULL)
      {
        TreeNode *temp = root->right;
        delete root;
        return temp;
      }
      else if (root->left != NULL && root->right == NULL)
      {
        TreeNode *temp = root->left;
        delete root;
        return temp;
      }
      // 2 child: here I am replacing the node with min node of right subtree
      else
      {
        TreeNode *mini = minValue(root->right);
        root->val = mini->val;
        root->right = deleteNode(root->right, mini->val);
      }
    }
    else if (root->val < key)
    {
      root->right = deleteNode(root->right, key);
    }
    else
    {
      root->left = deleteNode(root->left, key);
    }
    return root;
  }
};