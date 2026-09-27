#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){
    
    if(head == NULL)
        return true;

    unordered_map<Node*, bool> mp;
    mp[head] = true;

    Node* curr = head->next;

    while(curr != NULL){
        if(curr == head)
            return true;
        
        if(mp[curr])
            return false;
        
        mp[curr] = true;
        
        curr = curr -> next;
    }

    return false;
}
