#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class CircularDoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularDoublyLinkedList() {
        head = tail = nullptr;
    }

    // Utility: connect head and tail to make it circular
    void makeCircular() {
        if (head && tail) {
            head->prev = tail;
            tail->next = head;
        }
    }

    // 1. Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        makeCircular();
    }

    // 2. Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        makeCircular();
    }

    // 3. Insert at position (0-based)
    void insertAtPosition(int val, int pos) {
        if (pos == 0) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        if (temp == tail) {
            insertAtEnd(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        makeCircular();
    }

    // 4. Delete from beginning
    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        delete temp;
    }

    // 5. Delete from end
    void deleteAtEnd() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }
        delete temp;
    }

    // 6. Delete at position
    void deleteAtPosition(int pos) {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        if (pos == 0) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos && temp->next != head; i++)
            temp = temp->next;

        if (temp == tail) {
            deleteAtEnd();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // 7. Display forward
    void displayForward() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Forward: ";
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD\n";
    }

    // Display backward
    void displayBackward() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        cout << "Backward: ";
        do {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        } while (temp != tail);
        cout << "TAIL\n";
    }
};
//Write main function by yourself