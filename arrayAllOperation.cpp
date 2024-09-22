#include<iostream>
using namespace std;

int arr[10] = {10, 20, 30, 40, 50};  // Initialize the array with some elements
int size = 5;  // Current size of the array

void addAtBeginning(int value) {
    if(size == 10) {
        cout << "Array is full, cannot add element." << endl;
        return;
    }
    for(int i = size; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = value;
    size++;
}

void addAtMiddle(int value, int position) {
    if(size == 10 || position < 1 || position >= size) {
        cout << "Invalid position or array is full." << endl;
        return;
    }
    for(int i = size; i > position; i--) {
        arr[i] = arr[i-1];
    }
    arr[position] = value;
    size++;
}

void addAtEnd(int value) {
    if(size == 10) {
        cout << "Array is full, cannot add element." << endl;
        return;
    }
    arr[size] = value;
    size++;
}

void deleteAtBeginning() {
    if(size == 0) {
        cout << "Array is empty, cannot delete element." << endl;
        return;
    }
    for(int i = 0; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    size--;
}

void deleteAtMiddle(int position) {
    if(size == 0 || position < 1 || position >= size) {
        cout << "Invalid position or array is empty." << endl;
        return;
    }
    for(int i = position; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    size--;
}

void deleteAtEnd() {
    if(size == 0) {
        cout << "Array is empty, cannot delete element." << endl;
        return;
    }
    size--;
}

void update(int index, int value) {
    if(index < 0 || index >= size) {
        cout << "Invalid index." << endl;
        return;
    }
    arr[index] = value;
}

void search(int value) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == value) {
            cout << "Element found at position: " << i << endl;
            return;
        }
    }
    cout << "Element not found." << endl;
}

void display() {
    if(size == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array elements: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value, position;

    while(1) {
        cout << "\n1. Add at Beginning\n2. Add at Middle\n3. Add at End\n";
        cout << "4. Delete at Beginning\n5. Delete at Middle\n6. Delete at End\n";
        cout << "7. Update an Element\n8. Search for an Element\n9. Display Array\n10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to add at beginning: ";
                cin >> value;
                addAtBeginning(value);
                break;

            case 2:
                cout << "Enter value to add and position (1 to " << size - 1 << "): ";
                cin >> value >> position;
                addAtMiddle(value, position);
                break;

            case 3:
                cout << "Enter value to add at end: ";
                cin >> value;
                addAtEnd(value);
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                cout << "Enter position (1 to " << size - 1 << "): ";
                cin >> position;
                deleteAtMiddle(position);
                break;

            case 6:
                deleteAtEnd();
                break;

            case 7:
                cout << "Enter index to update (0 to " << size - 1 << ") and new value: ";
                cin >> position >> value;
                update(position, value);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;

            case 9:
                display();
                break;

            case 10:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

