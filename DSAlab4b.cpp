#include <iostream>
using namespace std;
const int length = 100;
// Function to create the array list
void create(int arr[], int size) {
    cout << "Enter the elements of the List" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}
// Function to insert an element at a specific position
void insertElement(int arr[], int element, int pos, int &size) {
    if (size >= length) {
        cout << "Array overflow" << endl;
        return;
    }
    if (pos < 0 || pos > size) {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    size++;
}
// Function to delete an element from a specific position
void deleteElement(int arr[], int pos, int &size) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position" << endl;
        return;
    }

    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;  // Element found at index i
        }
    }
    return -1;  // Element not found
}

// Function to sort the array using bubble sort
void sortArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                // Swap arr[j] and arr[i]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to display the elements of the array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int *arr = new int[length];
    int size;
    cout << "Enter the number of elements you want to add: ";
    cin >> size;

    create(arr, size);
    cout << "The list is: ";
    display(arr, size);

    int element, pos;
    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the position to insert at: ";
    cin >> pos;
    insertElement(arr, element, pos, size);
    cout << "The list after insertion is: ";
    display(arr, size);

    int searchElementValue;
    cout << "Enter the element to search for: ";
    cin >> searchElementValue;
    int searchResult = searchElement(arr, size, searchElementValue);
    if (searchResult != -1) {
        cout << "Element found at index: " << searchResult << endl;
    } else {
        cout << "Element not found" << endl;
    }

    deleteElement(arr, 2, size);
    cout << "The list after deleting the element is: ";
    display(arr, size);

    sortArray(arr, size);
    cout << "The sorted list is: ";
    display(arr, size);

    delete[] arr;  // Free memory allocated with new
    return 0;
}
