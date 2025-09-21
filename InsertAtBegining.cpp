#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insertAtBeginning(int n) {
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = head;
    head = newNode;
}

void printList() {
    cout << "List after inserting at beginning: ";
    Node *nodePtr = head;
    while (nodePtr != NULL) {
        cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);
    insertAtBeginning(40);

    printList();
    return 0;
}
