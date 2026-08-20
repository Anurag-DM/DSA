#include<iostream>
#include<queue>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this->data=data;
    this->left=this->right=nullptr;
  }
};

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

Node* insertIntoBST(Node* root, int d){
  if(root==NULL){
    root= new Node(d);
    return root;
  }
  if(d>root->data)
    root->right=insertIntoBST(root->right, d);
  else  
    root->left=insertIntoBST(root->left, d);
  return root;

}
void takeInput(Node* &root){
  int data;
  cin>>data;
  while(data!=-1){
    root=insertIntoBST(root, data);
    cin>>data;
  }
}
Node* minValue(Node* root){
  while(root->left !=NULL)
    root=root->left;
  return root;
}
Node* maxValue(Node* root){
  while(root->right !=NULL)
    root=root->right;
  return root;
}
int main(){
  Node* root=NULL;
  cout<< "Enter data to create BST" <<endl;
  takeInput(root);

  cout<<"Printing the BST"<<endl;
  levelOrderTraversal(root);
  
  return 0;
}