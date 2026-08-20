/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

// time : O(nklogk)  where k is no of linked lists and n is no of nodes in  linked list
// space: O(k)  for heap
class cmp
{
public:
  bool operator()(Node *&a, Node *&b)
  {
    return a->data > b->data;
  }
};

Node *mergeKLists(vector<Node *> &listArray)
{
  Node *head = new Node(-1);
  Node *trav = head;

  priority_queue<Node *, vector<Node *>, cmp> minHeap;

  int k = listArray.size();
  for (int i = 0; i < k; i++)
  {
    if (listArray[i] != NULL)
      minHeap.push(listArray[i]);
  }

  while (minHeap.size() > 0)
  {
    Node *temp = minHeap.top();
    minHeap.pop();

    trav->next = temp;
    trav = temp;

    if (temp->next)
    {
      minHeap.push(temp->next);
    }
  }

  return head->next;
}
