#include <iostream>
using namespace std;
struct Node {
    char data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

bool isEmpty(Queue& q) {
    return q.front == nullptr;
}

void enqueue(Queue& q, char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty(q)) {
        q.front = newNode;
        q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }

    cout << "Inserted: " << data << endl;
}

void dequeue(Queue& q) {
    if (isEmpty(q)) {
        cout << "Queue is empty" << endl;
        return;
    }

    Node* temp = q.front;
    char data = temp->data;

    if (q.front == q.rear) {
        q.front = nullptr;
        q.rear = nullptr;
    } else {
        q.front = q.front->next;
    }

    delete temp;
    cout << "Dequeued element is: " << data << endl;
}

void display(Queue& q) {
    if (isEmpty(q)) {
        cout << "Queue is empty" << endl;
        return;
    }

    Node* temp = q.front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Queue q = { nullptr, nullptr };

    dequeue(q);
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');
    enqueue(q, 'E');
    enqueue(q, 'F'); // Attempting to enqueue when the queue is full
    display(q);

    dequeue(q);
    display(q);

    return 0;
}
