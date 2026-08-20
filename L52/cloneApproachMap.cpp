/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node* nn=new Node(head->val);
        Node* chead=nn;
        Node* ctemp=nn;
        Node* temp=head;
        unordered_map<Node*,Node*> m;
        m[temp]=ctemp;
        while(temp->next!=NULL){
            temp=temp->next;
            Node* nn=new Node(temp->val);
            ctemp->next=nn;
            ctemp=nn;
            m[temp]=ctemp;
        }
        //now assign random ptr
        ctemp=chead;
        temp=head;
        while(temp!=NULL){
            ctemp->random=m[temp->random];
            temp=temp->next;
            ctemp=ctemp->next;
        }
        return chead;

        

    }
};