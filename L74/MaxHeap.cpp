#include<iostream>
#include<queue>
using namespace std;

class heap{
  public:
  int arr[100];
  int size;

  heap(){
    arr[0] = -1;
    size = 0;
  }

  void insert(int val){
    size++;
    int index = size;
    arr[index] = val;

    while(index>1){
      int parent = index/2;

      if(arr[index]>arr[parent]){
        swap(arr[index], arr[parent]);
        index = parent;
      }
      else
        return;
    }
  }

  void deleteroot(){
    if(size == 0){
      cout<<"Nothing to delete"<<endl;
      return;
    }

    //step1: make the root equal to last node
    arr[1] = arr[size];

    //step2: decrease the size by 1
    size--;

    //step3: move the root to the correct place
    int i = 1;
    while(i<size){ // we could write while(i <= size/2) here because Nodes after size/2 are leaf nodes, so no need to check further.
      int idx = i;
      int left = 2*i;
      int right = 2*i + 1;

      if(left<=size && arr[left]>arr[idx])
        idx = left;

      if(right<=size && arr[right]>arr[idx])
        idx = right;
      
      if(idx==i)
        break; //already in correct position so no need to check anymore
      
      swap(arr[i], arr[idx]);
      i=idx;
    }
  }

  void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left<=n && arr[left]>arr[largest])
      largest = left;
    
    if(right<=n && arr[right]>arr[largest] )
      largest = right;
    
    if(largest!=i){
      swap(arr[largest], arr[i]);
      heapify(arr, n, largest);
    }
  }

  void print(){
    for(int i = 1; i<=size; i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
};

int main(){
  heap h;
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(54);
  h.print();

  int arr[6] = {-1, 54, 53, 55, 52, 50};
  int n=5;
  for(int i=n/2; i>0; i--){
    h.heapify(arr, n, i);
  }

  cout<<"printing the array"<<endl;
  for(int i = 1; i<=n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;



  //max heap
  priority_queue<int> pq;

  pq.push(4);
  pq.push(2);
  pq.push(5);
  pq.push(3);

  cout<<"element at top "<<pq.top()<<endl;
  pq.pop();
  cout<<"element at top "<<pq.top()<<endl;

  cout<<"Size is "<<pq.size()<<endl;

  if(pq.empty()){
    cout<<"pq is empty"<<endl;
  }
  else{
    cout<<"pq is not empty "<<endl;
  }


  //min heap
  priority_queue<int, vector<int>, greater<int>> minheap;

  minheap.push(4);
  minheap.push(2);
  minheap.push(5);
  minheap.push(3);

  cout<<"element at top "<<minheap.top()<<endl;
  minheap.pop();
  cout<<"element at top "<<minheap.top()<<endl;

  cout<<"Size is "<<minheap.size()<<endl;

  if(minheap.empty()){
    cout<<"minheap is empty"<<endl;
  }
  else{
    cout<<"minheap is not empty "<<endl;
  }

  return 0;
}