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
  struct Info
  {
    long long sum;
    bool cond;
    int maxVal;
    int minVal;
  };
  Info solve(TreeNode *root, long long &ans)
  {
    if (root == NULL)
    {
      return {0, true, INT_MIN, INT_MAX};
    }
    Info left = solve(root->left, ans);
    Info right = solve(root->right, ans);
    bool bst = root->val > left.maxVal && root->val < right.minVal;
    Info curr;
    curr.cond = left.cond && right.cond && bst;
    curr.sum = left.sum + right.sum + root->val;
    if (curr.cond == true && ans < curr.sum)
      ans = curr.sum;
    curr.minVal = min(root->val, left.minVal);
    curr.maxVal = max(root->val, right.maxVal);
    return curr;
  }

public:
  int maxSumBST(TreeNode *root)
  {
    long long ans = 0;
    solve(root, ans);
    return ans;
  }
};