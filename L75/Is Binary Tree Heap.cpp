/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
  int noOfNodes(Node *tree)
  {
    if (tree == NULL)
      return 0;
    return 1 + noOfNodes(tree->left) + noOfNodes(tree->right);
  }

  bool isComplete(Node *root, int ind, int n)
  {
    if (root == NULL)
      return true;

    if (ind >= n)
      return false;

    bool left = isComplete(root->left, 2 * ind + 1, n);
    bool right = isComplete(root->right, 2 * ind + 2, n);

    return left && right;
  }

  bool maxHeapProp(Node *root)
  {
    // case 1: leaf
    if (root->left == NULL && root->right == NULL)
      return true;

    // case 2: only left child exist
    if (root->right == NULL)
      return root->data > root->left->data;

    // case 3: both child exist
    return root->data > root->left->data &&
           root->data > root->right->data &&
           maxHeapProp(root->left) &&
           maxHeapProp(root->right);
  }

public:
  bool isHeap(Node *tree)
  {

    int n = noOfNodes(tree);

    if (isComplete(tree, 0, n) && maxHeapProp(tree))
      return true;

    return false;
  }
};