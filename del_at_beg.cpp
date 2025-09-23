#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insertAtEnd(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) return;
    Node *temp = head;
    head = head->next;
    delete temp;
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
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();
    deleteAtBeginning();
    display();
}