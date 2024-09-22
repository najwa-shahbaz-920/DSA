#include<iostream>
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
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void addAtEnd(int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
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
            cout << "error";
            return;
        }
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* tail = head->prev;
    Node* temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    delete temp;
}

void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* tail = head->prev;
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        tail->prev->next = head;
        head->prev = tail->prev;
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
            cout << "ERROR";
            return;
        }
    }
    Node* del = temp->next;
    temp->next = del->next;
    del->next->prev = temp;
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
            cout << "found at position " << p << "\n";
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
            cout << "Position out of bound\n";
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
        cout << temp->data << " <-> ";
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
    addAtBeginning(40);
    display();
    addAtEnd(50);
    display();
    
    searchNode(70);

    deleteAtBeginning();
    display();
    deleteAtEnd();
    display();
    deleteAtMiddle(1);
    display();

    updateNode(2, 100);
    display();

    return 0;
}