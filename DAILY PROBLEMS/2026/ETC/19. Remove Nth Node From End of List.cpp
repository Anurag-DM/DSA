/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// take 1 pass
class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *pt1 = head, *pt2 = head;

    int count = 0;
    while (pt2 != NULL)
    {
      if (count > n)
        pt1 = pt1->next;

      pt2 = pt2->next;
      count++;
    }

    if (count <= n)
      return head->next;

    pt1->next = pt1->next->next;

    return head;
  }
};
/* takes 2 passes
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        while(temp!=NULL){
            count++;
            temp = temp -> next;
        }

        if(count - n == 0){
            return head->next;
        }

        temp = head;
        for(int i = 1; i<count - n; i++){
            temp = temp->next;
        }

        temp ->next = temp->next->next;

        return head;
    }
};*/