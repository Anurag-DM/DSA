/*
✅ Time Complexity
Step 1: Insert all nodes into min heap
for(int i=0; i<n; i++)
    pq.push(...)

Each push:O(log n)

So:O(n log n)

Step 2: Build Huffman Tree
You perform: n-1 merge operations.

Each merge:
2 pops → O(log n)
1 push → O(log n)

So each:O(log n)

Total: O(n log n)

Step 3: DFS traversal
Visits every node once.
Huffman tree has: 2n - 1 nodes.

So:O(n)
✅ Total Time:
O(n log n)

✅ Space Complexity
Heap:Stores up to:O(n)
Tree:Total nodes:2n - 1 So:O(n)
Recursion stack:Worst case: O(n) (skewed tree)
Answer vector: Stores all codes: O(n)
✅ Total Auxiliary Space: O(n)
*/
class Node
{
public:
  Node *left;
  Node *right;
  int data;
  int minIndex;

  Node(int d, int idx)
  {
    data = d;
    left = NULL;
    right = NULL;
    minIndex = idx;
  }
};

class cmp
{
public:
  bool operator()(Node *a, Node *b)
  {
    if (a->data == b->data)
      return a->minIndex > b->minIndex;
    return a->data > b->data;
  }
};

class Solution
{
  void traverse(Node *root, vector<string> &ans, string temp)
  {
    if (root == NULL)
      return;

    if (root->left == NULL && root->right == NULL)
    {
      ans.push_back(temp);
      return;
    }

    traverse(root->left, ans, temp + "0");
    traverse(root->right, ans, temp + "1");
  }

public:
  vector<string> huffmanCodes(string &s, vector<int> f)
  {

    priority_queue<Node *, vector<Node *>, cmp> pq;

    int order = 0;
    for (int i = 0; i < f.size(); i++)
    {
      Node *node = new Node(f[i], i);
      pq.push(node);
    }

    while (pq.size() > 1)
    {
      Node *node1 = pq.top();
      pq.pop();

      Node *node2 = pq.top();
      pq.pop();

      Node *node = new Node(node1->data + node2->data, min(node1->minIndex, node2->minIndex));
      node->left = node1;
      node->right = node2;
      pq.push(node);
    }

    Node *root = pq.top();

    vector<string> ans;

    // Edge case: single character
    if (root->left == NULL && root->right == NULL)
    {
      ans.push_back("0");
      return ans;
    }

    traverse(root, ans, "");

    return ans;
  }
};