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
class Solution {
    ListNode* rev(ListNode* &curr, int k){
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        int count = 0;
        bool flag = false;
        
        // Check if there are at least k nodes to reverse
        ListNode* t2 = curr;
        while(t2 !=NULL){
            count++;
            t2 = t2->next;

            if(count >=k){
                flag = true;
                break;
            }
        }

        // If there are fewer than k nodes, return the current node without reversing
        if(flag == false)
            return curr;
        
        count = 0;

        // Reverse k nodes
        while(curr != NULL && count < k){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }

        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* thead = new ListNode(-1);
        ListNode* temp = thead;
        ListNode* curr = head;

        // Reverse nodes in groups of k
        while(curr != NULL){
            ListNode* t = curr;
            temp->next = rev(curr, k);
            temp = t;

            if(t == curr)
                break;
        }

        return thead->next;
        
    }
};