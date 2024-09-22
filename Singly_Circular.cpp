#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* head = NULL;

void addAtBeginning(int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        head->next = head; 
    } else {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

void addAtEnd(int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        head->next = head; 
    } else {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
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
        if (temp == head) {
            cout << "Error: Position out of bounds\n";
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        head = head->next;
        tail->next = head; 
        delete temp;
    }
}

void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* tail = head;
    Node* prev = NULL;
    while (tail->next != head) {
        prev = tail;
        tail = tail->next;
    }
    if (tail == head) {
        delete head;
        head = NULL;
    } else {
        prev->next = head; 
        delete tail;
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
        if (temp->next == head) {
            cout << "Error: Position out of bounds\n";
            return;
        }
    }
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void searchNode(int data) {
    Node* temp = head;
    int p = 0;
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    do {
        if (temp->data == data) {
            cout << "Found at position " << p << "\n";
            return;
        }
        temp = temp->next;
        p++;
    } while (temp != head);
    cout << "Not found\n";
}

void updateNode(int p, int newData) {
    Node* temp = head;
    for (int i = 0; i < p; i++) {
        temp = temp->next;
        if (temp == head) {
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
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD\n";
}

int main() {
    display();
    addAtBeginning(10);
    display();
    addAtBeginning(20);
    display();
    addAtBeginning(30);
    display();
    addAtEnd(40);
    display();
    addAtEnd(50);
    display();
    
    searchNode(30);
    searchNode(60);

    deleteAtBeginning();
    display();
    deleteAtEnd();
    display();
    deleteAtMiddle(1);
    display();

    updateNode(1, 100);
    display();

    return 0;
}
