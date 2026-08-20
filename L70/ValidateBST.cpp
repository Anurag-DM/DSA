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
  bool solve(TreeNode *root, long min, long max)
  {
    if (root == NULL)
      return true;
    if (root->val >= min && root->val <= max)
    {
      bool left = solve(root->left, min, (long)root->val - 1);
      bool right = solve(root->right, (long)root->val + 1, max);
      return left && right;
    }
    else
      return false;
  }

public:
  bool isValidBST(TreeNode *root)
  {
    return solve(root, INT_MIN, INT_MAX);
  }
};