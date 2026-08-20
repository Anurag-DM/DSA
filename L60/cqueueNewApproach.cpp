class MyCircularQueue {
private:
    int *queue;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        queue = new int[capacity];
        rear = -1;
        front = 0;
        size = 0;
    }
    
    bool enQueue(int value) {
        if(size==capacity){
            return false;
        }
        rear = (rear+1) % capacity;
        queue[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size==0){
            return false;
        }
        front = (front+1) % capacity;
        size--;
        return true;
    }
    
    int Front() {
        if(size==0){
            return -1;
        }
        return queue[front];
    }
    
    int Rear() {
        if(size==0){
            return -1;
        }
        return queue[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};