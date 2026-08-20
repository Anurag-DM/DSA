// User function Template for C++

class Solution
{
public:
  void flatten(Node *root)
  {
    // code here
    while (root != NULL)
    {
      if (root->left == NULL)
      {
        root = root->right;
      }
      else
      {
        Node *pred = root->left;
        while (pred->right != NULL)
          pred = pred->right;
        pred->right = root->right;
        root->right = root->left;
        root->left = NULL;
        root = root->right;
      }
    }
  }
};