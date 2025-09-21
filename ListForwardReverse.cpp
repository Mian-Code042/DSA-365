#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void append(int n) {
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *nodePtr = head;
        while (nodePtr->next != NULL) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void printForward() {
    cout << "List in Forward Order: ";
    Node *nodePtr = head;
    while (nodePtr != NULL) {
        cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

void printReverse(Node* nodePtr) {
    if (nodePtr == NULL) return;
    printReverse(nodePtr->next);
    cout << nodePtr->data << " ";
}

int main() {
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);
    append(6);

    printForward();

    cout << "List in Reverse Order: ";
    printReverse(head);
    cout << endl;

    return 0;
}
