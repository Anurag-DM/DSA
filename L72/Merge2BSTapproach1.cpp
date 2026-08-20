// this is time O(m+n) and space O(m+n)
/*************************************************************

    Following is the Binary Tree node structure:

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
void inorder(TreeNode *root, vector<int> &in)
{
  if (root == NULL)
    return;
  inorder(root->left, in);
  in.push_back(root->data);
  inorder(root->right, in);
}
void mergeSortedArrays(vector<int> &bst1, vector<int> &bst2, vector<int> &bst3)
{
  int n = bst1.size(), m = bst2.size(), i = 0, j = 0, k = 0;
  while (i < n && j < m)
  {
    if (bst1[i] < bst2[j])
      bst3[k++] = bst1[i++];
    else
      bst3[k++] = bst2[j++];
  }
  while (i < n)
  {
    bst3[k++] = bst1[i++];
  }
  while (j < m)
  {
    bst3[k++] = bst2[j++];
  }
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
  // Write your code here.
  vector<int> bst1, bst2;
  inorder(root1, bst1);
  inorder(root2, bst2);
  vector<int> bst3(bst1.size() + bst2.size());
  mergeSortedArrays(bst1, bst2, bst3);
  return bst3;
}