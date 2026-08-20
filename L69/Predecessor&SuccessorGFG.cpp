/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
  void inorderTrav(Node *root, vector<Node *> &list)
  {
    if (root == NULL)
      return;
    inorderTrav(root->left, list);
    list.push_back(root);
    inorderTrav(root->right, list);
  }

public:
  vector<Node *> findPreSuc(Node *root, int key)
  {
    // code here
    vector<Node *> list;
    inorderTrav(root, list);
    vector<Node *> ans(2, NULL);
    for (int i = list.size() - 1; i >= 0; i--)
    {
      if (list[i]->data > key)
        ans[1] = list[i];
      else if (list[i]->data < key)
      {
        ans[0] = list[i];
        break;
      }
    }
    return ans;
  }
};
//this is O(n) time and O(n) space. in l70 there is optimized one