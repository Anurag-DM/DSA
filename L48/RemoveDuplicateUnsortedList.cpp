#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    unordered_set<int> s;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(s.find(temp->data)!=s.end()){
            prev->next=temp->next;
        }
        else{
            s.insert(temp->data);
            prev=temp;
        }
        temp=temp->next;
    }
    return head;
}