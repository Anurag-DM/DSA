/*
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
  void inorder(Node *root, vector<Node *> &v)
  {
    if (root == NULL)
      return;
    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
  }

public:
  Node *flattenBST(Node *root)
  {
    // code here
    vector<Node *> v;
    inorder(root, v);
    int i;
    for (i = 0; i < v.size() - 1; i++)
    {
      v[i]->right = v[i + 1];
      v[i]->left = NULL;
    }
    v[i]->left = v[i]->right = NULL;
    return v[0];
  }
};