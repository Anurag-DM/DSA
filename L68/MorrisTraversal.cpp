#include <vector>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int x)
  {
    data = x;
    left = right = nullptr;
  }
};

vector<int> morrisInorder(Node *root)
{
  vector<int> inorder;
  Node *current = root;

  while (current != nullptr)
  {

    // Case 1: No left child
    if (current->left == nullptr)
    {
      inorder.push_back(current->data);
      current = current->right;
    }
    // Case 2: Left child exists
    else
    {
      Node *predecessor = current->left;

      while (predecessor->right != nullptr &&
             predecessor->right != current)
      {
        predecessor = predecessor->right;
      }

      // Create thread
      if (predecessor->right == nullptr)
      {
        predecessor->right = current;
        current = current->left;
      }
      // Remove thread
      else
      {
        predecessor->right = nullptr;
        inorder.push_back(current->data);
        current = current->right;
      }
    }
  }

  return inorder;
}