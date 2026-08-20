/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        Node* temp=head;
        vector<int> v;
        int i=0;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp=temp->next;
            i++;
        }
        for(int j=0;j<i/2;j++){
            if(v[j]!=v[i-1-j])
                return 0;
        }
        return 1;
    }
};