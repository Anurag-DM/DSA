#include <stdio.h>
#define SIZE 5   // maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Check if queue is full
int isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

// Check if queue is empty
int isEmpty() {
    return front == -1;
}

// Insert element
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL!\n");
        return;
    }
    if (front == -1)  // First insertion
        front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// Delete element
int dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {  // Only one element left
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return data;
}

// Display elements
void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    printf("Deleted: %d\n", dequeue());
    printf("Deleted: %d\n", dequeue());

    display();

    enqueue(60);
    enqueue(70);
    display();

    return 0;
}
