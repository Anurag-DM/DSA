/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
  Node *solve(vector<int> &inorder, vector<int> &preorder, int &index, int instart, int inend, int n, unordered_map<int, int> nodetoIndex)
  {
    if (index >= n || instart > inend)
    {
      return NULL;
    }
    int element = preorder[index++];
    int position = nodetoIndex[element];
    Node *root = new Node(element);
    root->left = solve(inorder, preorder, index, instart, position - 1, n, nodetoIndex);
    root->right = solve(inorder, preorder, index, position + 1, inend, n, nodetoIndex);
    return root;
  }

public:
  Node *buildTree(vector<int> &inorder, vector<int> &preorder)
  {
    // code here
    int preOrderIndex = 0, n = inorder.size();
    unordered_map<int, int> nodetoIndex;
    for (int i = 0; i < n; i++)
    {
      nodetoIndex[inorder[i]] = i;
    }
    Node *head = solve(inorder, preorder, preOrderIndex, 0, n - 1, n, nodetoIndex);
    return head;
  }
};