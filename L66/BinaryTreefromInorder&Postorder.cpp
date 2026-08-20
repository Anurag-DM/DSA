/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution
{
  Node *solve(vector<int> &inorder, vector<int> &postorder, int &index, int instart, int inend, int &n, unordered_map<int, int> &nodetoIndex)
  {
    if (index < 0 || instart > inend)
    {
      return NULL;
    }
    int element = postorder[index--];
    int position = nodetoIndex[element];
    Node *root = new Node(element);
    root->right = solve(inorder, postorder, index, position + 1, inend, n, nodetoIndex);
    root->left = solve(inorder, postorder, index, instart, position - 1, n, nodetoIndex);

    return root;
  }

public:
  Node *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    // code here
    int n = inorder.size(), postOrderIndex = n - 1;
    unordered_map<int, int> nodetoIndex;
    for (int i = 0; i < n; i++)
    {
      nodetoIndex[inorder[i]] = i;
    }
    Node *head = solve(inorder, postorder, postOrderIndex, 0, n - 1, n, nodetoIndex);
    return head;
  }
};