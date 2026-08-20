/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
class Info
{
public:
  int count;
  bool cond;
  int maxVal;
  int minVal;
};
Info solve(TreeNode *root, int &ans)
{
  if (root == NULL)
  {
    return {0, true, INT_MIN, INT_MAX};
  }
  Info left = solve(root->left, ans);
  Info right = solve(root->right, ans);
  bool bst = root->data > left.maxVal && root->data < right.minVal;
  Info curr;
  curr.cond = left.cond && right.cond && bst;
  curr.count = left.count + right.count + 1;
  if (curr.cond == true && ans < curr.count)
    ans = curr.count;
  curr.minVal = min(root->data, left.minVal);
  curr.maxVal = max(root->data, right.maxVal);
  return curr;
}
int largestBST(TreeNode *root)
{
  // Write your code here.
  int ans = 0;
  solve(root, ans);
  return ans;
}