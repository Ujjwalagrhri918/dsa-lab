#include <iostream>
using namespace std;

// Define a structure for a doubly linked list node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to insert a new node at the front of the list
void insertAtFront(struct node** head, int value) {
    struct node* newNode = new node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = (*head);
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to insert a new node after a specified node
void insertAfterNode(struct node* prev_node, int value) {
    if (prev_node == NULL) {
        cout << "previous node cannot be null";
        return;
    }
    struct node* newNode = new node();
    newNode->data = value;
    newNode->prev = prev_node;
    newNode->next = prev_node->next;
    if (prev_node->next != NULL) {
        newNode->next->prev = newNode;
    }
    prev_node->next = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct node** head, int value) {
    struct node* newNode = new node();
    newNode->data = value;
    newNode->next = NULL;
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the elements of the list
void display(struct node* head) {
    struct node* temp = head;
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to delete a specified node from the list
void deleteNode(struct node** head, struct node* del_node) {
    if (*head == NULL || del_node == NULL) {
        return;
    }
    if (*head == del_node) {
        *head = del_node->next;
    }
    if (del_node->next != NULL) {
        del_node->next->prev = del_node->prev;
    }
    if (del_node->prev != NULL) {
        del_node->prev->next = del_node->next;
    }
    free(del_node);
}

int main() {
    struct node* head = NULL;
    
    // Insert nodes and demonstrate functionality
    insertAtFront(&head, 34);
    display(head);
    insertAtFront(&head, 45);
    display(head);
    insertAtEnd(&head, 69);
    display(head);
    insertAfterNode(head->next, 55);
    display(head);  
    deleteNode(&head, head->next);
    display(head);
    deleteNode(&head, head);
    display(head);
    
    return 0;
}
