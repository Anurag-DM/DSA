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

Node* sortList(Node *head){
    // Write your code here.
    int n0=0,n1=0,n2=0;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0)
            n0++;
        else if(temp->data==1)
            n1++;
        else    
            n2++;
        temp=temp->next;
    }
    temp=head;
    while(n0>0){
        temp->data=0;
        n0--;
        temp=temp->next;
    }
    while(n1>0){
        temp->data=1;
        n1--;
        temp=temp->next;
    }
    while(n2>0){
        temp->data=2;
        n2--;
        temp=temp->next;
    }
    return head;
}