#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insertBefore(Node*& tail, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (!tail) {  
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    cout << value << " added at the beginning.\n";
}


void insertAfter(Node*& tail, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    cout << value << " added at the end.\n";
}

void deleteNode(Node*& tail, int value) {
    if (!tail) {
        cout << "List is empty.\n";
        return;
    }

    Node* current = tail->next;
    Node* prev = tail;
    do {
        if (current->data == value) {
            if (current == tail && current->next == tail) { 
                delete current;
                tail = nullptr;
            } else {
                prev->next = current->next;
                if (current == tail) tail = prev;
                delete current;
            }
            cout << value << " deleted successfully.\n";
            return;
        }
        prev = current;
        current = current->next;
    } while (current != tail->next);

    cout << value << " not found.\n";
}


void display(Node* tail) {
    if (!tail) return;
    Node* temp = tail->next;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "(head)\n";
}

int main() {
    Node* tail = nullptr;
    insertBefore(tail, 10);
    insertBefore(tail, 20);
    insertAfter(tail, 30);
    insertAfter(tail, 40);
    display(tail);
    deleteNode(tail, 20);
    deleteNode(tail, 50);
    display(tail);
    return 0;
}
