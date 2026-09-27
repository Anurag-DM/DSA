#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL)
        return second;
    if(second==NULL)
        return first;

    Node<int>* t1=NULL;
    Node<int>* t2=first;
    Node<int>* t3=second;

    if(first->data<second->data){
        t1=first;
        t2=t2->next;
    }
    else{
        t1=second;
        t3=t3->next;
    }
    
    Node<int>* head=t1;

    while(t2!=NULL && t3!=NULL){
        if(t2->data<t3->data){
            t1->next=t2;
            t2=t2->next;
        }
        else{
            t1->next=t3;
            t3=t3->next;
        }
        t1=t1->next;
    }
    while(t2!=NULL){
        t1->next=t2;
        t2=t2->next;
        t1=t1->next;
    }
    while(t3!=NULL){
        t1->next=t3;
        t3=t3->next;
        t1=t1->next;
    }
    return head;
}
