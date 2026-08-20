#include<iostream>
using namespace std;

class kQueue {

    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freeSpot;
        int *next;

    public:
        kQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freeSpot = 0;
        }    

        void enqueue(int data, int qn) {

            //overflow
            if( freeSpot == -1) {
                cout << "No Empty space is present" << endl;
                return;
            }

            //find first free index
            int index = freeSpot;

            //update freespot
            freeSpot = next[index];

            //check whther first element
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                //link new element to the prev element
                next[rear[qn-1]] = index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn-1] = index;

            //push element
            arr[index] = data;
        }

        int dequeue(int qn) {
            //underflow 
            if(front[qn-1] == -1)
            {
                cout << "Queue UnderFlow " << endl;
                return -1;
            }

            //find index to pop
            int index = front[qn-1];

            //front ko aage badhao
            front[qn-1] = next[index];

            //freeSlots ko manage karo
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }

};

int main() {

    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

    return 0;
}
/*
My code 
class kQueues {
    int *arr;
    int *front;
    int *rear;
    int *next;
    int n,k;
    int freespot;
    
  public:
    kQueues(int n, int k) {
        // Initialize your data members
        this->n=n;
        this->k=k;
        arr=new int[n];
        front=new int[k];
        rear=new int[k];
        next=new int[n];
        freespot=0;
        for(int i=0;i<k;i++){
            rear[i]=front[i]=-1;
        }
        for(int i=0;i<n;i++)
            next[i]=i+1;
        next[n-1]=-1;
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        if(isFull())
            return;
        int index=freespot;
        freespot=next[index];
        if(front[i]==-1)
            front[i]=index;
        else
            next[rear[i]]=index;
        next[index]=-1;
        rear[i]=index;
        arr[index]=x;
    }

    int dequeue(int i) {
        // dequeue element from queue i
        if(isEmpty(i))
            return -1;
        int index=front[i];
        front[i]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return front[i]==-1;
    }

    bool isFull() {
        // check if array is full
        return freespot==-1;
    }
};

*/