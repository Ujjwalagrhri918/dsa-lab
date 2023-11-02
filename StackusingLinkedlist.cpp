#include <iostream>
using namespace std;
// A structure to represent a stack
struct StackNode {
    int data;
    StackNode* next;
};
void pushNode(struct StackNode** root, int data) {
    StackNode* newNode = new StackNode();
    newNode->data = data;
    newNode->next = *root;
    (*root)= newNode;
    cout << data << " pushed to stack\n";
}
int isEmpty(StackNode* root) {
    return !root;
}
int pop(StackNode** root) {
    if (isEmpty(*root)){
        cout<<"Empty stack ";
        return -1 ;}
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    delete temp;
    return popped;
}

int peek(StackNode* root) {
    if (isEmpty(root)){
        cout<<"Empty stack ";
        return -1;}
    return root->data;
}

// Driver code
int main() {
    StackNode* root = NULL;
    cout<<peek(root)<<endl;
    pushNode(&root, 10);
    pushNode(&root, 20);
    pushNode(&root, 30);
    cout << pop(&root) << " popped from stack\n";
    cout << "Top element is " << peek(root) << endl;
    cout << "Elements present in stack : ";
    // Print all elements in stack:
    while (!isEmpty(root)) {
        // Print top element in stack
        cout << peek(root) << " ";
        // Remove top element in stack
        pop(&root);
    }
    return 0;
}

