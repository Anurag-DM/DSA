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
  Node *createMapping(Node *root, int target, unordered_map<Node *, Node *> &nodetoParent)
  {
    queue<Node *> q;
    nodetoParent[root] = NULL;
    q.push(root);
    Node *res = NULL;
    while (!q.empty())
    {
      Node *front = q.front();
      q.pop();
      if (front->data == target)
      {
        res = front;
      }
      if (front->left)
      {
        nodetoParent[front->left] = front;
        q.push(front->left);
      }
      if (front->right)
      {
        nodetoParent[front->right] = front;
        q.push(front->right);
      }
    }
    return res;
  }

  int burn(Node *root, unordered_map<Node *, Node *> &nodetoParent)
  {
    int ans = 0;
    queue<Node *> q;
    q.push(root);
    unordered_map<Node *, bool> visited;
    visited[root] = 1;
    while (!q.empty())
    {
      int size = q.size();
      bool flag = 0;
      for (int i = 0; i < size; i++)
      {
        Node *temp = q.front();
        Node *parent = nodetoParent[temp];
        q.pop();
        if (temp->left && visited[temp->left] == 0)
        {
          flag = 1;
          q.push(temp->left);
          visited[temp->left] = 1;
        }
        if (temp->right && visited[temp->right] == 0)
        {
          flag = 1;
          q.push(temp->right);
          visited[temp->right] = 1;
        }
        if (parent && visited[parent] == 0)
        {
          flag = 1;
          q.push(parent);
          visited[parent] = 1;
        }
      }
      if (flag == 1)
        ans++;
    }
    return ans;
  }

public:
  int minTime(Node *root, int target)
  {
    // code here
    // step1: create nodeToParent mapping
    // step2: find target node
    // step3: burn the tree in min time

    unordered_map<Node *, Node *> nodetoParent;
    Node *start = createMapping(root, target, nodetoParent);
    return burn(start, nodetoParent);
  }
};