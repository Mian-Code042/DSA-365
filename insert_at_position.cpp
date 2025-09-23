#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insertAtPosition(int value, int pos) {
    if (pos <= 0) return;
    Node *newNode = new Node;
    newNode->data = value;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertAtPosition(10, 1);
    insertAtPosition(20, 2);
    insertAtPosition(15, 2);
    insertAtPosition(16, 3);
    insertAtPosition(17, 5);
    display();
}
