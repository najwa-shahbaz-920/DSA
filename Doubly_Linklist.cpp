#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node* head = NULL;

void addAtBeginning(int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addAtEnd(int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void addAtMiddle(int data, int p) {
    if (p == 0) {
        addAtBeginning(data);
        return;
    }
    Node* newNode = new Node(data);
    Node* temp = head;
    for (int i = 0; i < p - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            cout << "Error: Position out of bounds\n";
            return;
        }
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}

void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
}

void deleteAtMiddle(int p) {
    if (p == 0) {
        deleteAtBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 0; i < p - 1; i++) {
        temp = temp->next;
        if (temp == NULL || temp->next == NULL) {
            cout << "Error: Position out of bounds\n";
            return;
        }
    }
    Node* del = temp->next;
    temp->next = del->next;
    if (del->next != NULL) {
        del->next->prev = temp;
    }
    delete del;
}

void searchNode(int data) {
    Node* temp = head;
    int p = 0;
    while (temp != NULL) {
        if (temp->data == data) {
            cout << "Found at position " << p << "\n";
            return;
        }
        temp = temp->next;
        p++;
    }
    cout << "Not found\n";
}

void updateNode(int p, int newData) {
    Node* temp = head;
    for (int i = 0; i < p; i++) {
        temp = temp->next;
        if (temp == NULL) {
            cout << "Position out of bounds\n";
            return;
        }
    }
    temp->data = newData;
}

void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    display();
    addAtBeginning(10);
    display();
    addAtBeginning(20);
    display();
    addAtEnd(30);
    display();
    addAtEnd(40);
    display();
    
    searchNode(20);
    searchNode(50);

    deleteAtBeginning();
    display();
    deleteAtEnd();
    display();
    deleteAtMiddle(1);
    display();

    updateNode(0, 100);
    display();

    return 0;
}
