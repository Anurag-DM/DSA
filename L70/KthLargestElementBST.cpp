/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
  void inorder(Node *root, int &n)
  {
    if (root == NULL)
      return;
    inorder(root->left, n);
    n++;
    inorder(root->right, n);
  }
  void solve(Node *root, int &i, int &k, int &ans)
  {
    if (root == NULL)
      return;
    solve(root->left, i, k, ans);
    i++;
    if (i == k)
    {
      ans = root->data;
      return;
    }
    solve(root->right, i, k, ans);
  }

public:
  int kthLargest(Node *root, int k)
  {
    // Your code here
    int ans = 0, i = 0, n = 0;
    inorder(root, n);
    k = n - k + 1;
    solve(root, i, k, ans);
    return ans;
  }
};