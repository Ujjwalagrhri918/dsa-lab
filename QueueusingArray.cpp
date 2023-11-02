#include<iostream>
using namespace std;
#define SIZE 5

struct queue {
    char arr[SIZE];
    int front;
    int rear;
};

bool isFull(struct queue &q) {
    return (q.rear == SIZE - 1);
}

bool isEmpty(struct queue &q) {
    return (q.front == -1 && q.rear == -1);
}

void enqueue(struct queue &q, char c) {
    if (isFull(q)) {
        cout << "Queue is Full" << endl;
    } else {
        if (q.front == -1)
            q.front = 0;
        q.rear++;
        q.arr[q.rear] = c;
        cout << "Inserted: " << c << endl;
    }
}

void dequeue(struct queue &q) {
    if (isEmpty(q)) {
        cout << "Queue is Empty" << endl;
    } else {
        char element = q.arr[q.front];
        if (q.front >= q.rear) {
            q.front = -1;
            q.rear = -1;
        } else
            q.front++;
        cout << "Dequeued element is: " << element << endl;
    }
}

void display(struct queue &q) {
    if (isEmpty(q)) {
        cout << "Queue is Empty" << endl;
        return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.arr[i] << " ";
    }
    cout << endl;
}
void peek(struct queue q){
    char element = q.arr[q.front];
    cout<<"Element at the front is: "<< element<<endl;
}

int main() {
    queue q;
    q.front = -1;
    q.rear = -1;
    dequeue(q);
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    peek(q);
    enqueue(q, 'D');
    enqueue(q, 'E');
    enqueue(q, 'F'); // Attempting to enqueue when the queue is full
    display(q);
    dequeue(q);
    display(q);
    return 0;
}
