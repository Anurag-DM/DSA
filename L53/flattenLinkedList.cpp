/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  private:
    Node* merge(Node* left,Node* right){
        Node* ans=new Node(-1);
        Node* thead=ans;
        while(left!=NULL && right!=NULL){
            if(left->data<right->data){
                ans->bottom=left;
                ans=left;
                left=left->bottom;
            }else{
                ans->bottom=right;
                ans=right;
                right=right->bottom;
            }
        }
        if(left!=NULL){
            ans->bottom=left;
        }
        if(right!=NULL){
            ans->bottom=right;
        }
        return thead->bottom;
    }
  public:
    Node *flatten(Node *head) {
        // code here
        if(head->next==NULL)
            return head;
        Node* left=head;
        Node* right=flatten(head->next);
        left->next=NULL;
        return merge(left,right);
        
    }
};