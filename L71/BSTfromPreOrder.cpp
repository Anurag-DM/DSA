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
  TreeNode *create(vector<int> &pre, int &index, int min, int max, int &n)
  {
    if (index >= n || pre[index] < min || pre[index] > max)
      return NULL;
    int element = pre[index++];
    TreeNode *root = new TreeNode(element);
    root->left = create(pre, index, min, element, n);
    root->right = create(pre, index, element, max, n);
    return root;
  }

public:
  TreeNode *bstFromPreorder(vector<int> &preorder)
  {
    int index = 0, n = preorder.size();
    return create(preorder, index, 0, 1001, n);
  }
};