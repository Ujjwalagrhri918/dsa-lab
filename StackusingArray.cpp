#include <iostream>
using namespace std;
#define MAX 100
struct Stack {
    int a[MAX]; // Maximum size of Stack
    int top;
    Stack() { top = -1; }
};
bool push(Stack &s, int x) {
    if (s.top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    } else {
        s.a[++s.top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}
int pop(Stack &s) {
    if (s.top < 0) {
        cout << "Stack Underflow";
        return 0;
    } else {
        int x = s.a[s.top--];
        return x;
    }
}
int peek(const Stack &s) {
    if (s.top < 0) {
        cout << "Stack is Empty";
        return 0;
    } else {
        int x = s.a[s.top];
        return x;
    }
}
bool isEmpty(const Stack &s) {
    return (s.top < 0);
}
int main() {
    Stack s;
    push(s, 10);
    push(s, 20);
    push(s, 30);
    cout << pop(s) << " Popped from stack\n";
    // Print top element of stack after popping
    cout << "Top element is : " << peek(s) << endl;
    // Print all elements in stack:
    cout << "Elements present in stack : ";
    while (!isEmpty(s)) {
        // Print top element in stack
        cout << peek(s) << " ";
        // Remove top element in stack
        pop(s);
    }
    return 0;
}