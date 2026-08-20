/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
  // Write your code here.
  int pred = -1;
  int succ = -1;
  while (root != NULL && root->data != key)
  {
    if (root->data < key)
    {
      pred = root->data;
      root = root->right;
    }
    else
    {
      succ = root->data;
      root = root->left;
    }
  }
  if (root == NULL)
    return {pred, succ};
  TreeNode *leftTree = root->left, *rightTree = root->right;
  while (leftTree != NULL)
  {
    pred = leftTree->data;
    leftTree = leftTree->right;
  }
  while (rightTree != NULL)
  {
    succ = rightTree->data;
    rightTree = rightTree->left;
  }
  return {pred, succ};
}