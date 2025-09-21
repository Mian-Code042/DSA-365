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

void deleteNode(int value) {
    if (head == NULL) return;

    if (head->data == value) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *nodePtr = head;
    while (nodePtr->next != NULL && nodePtr->next->data != value) {
        nodePtr = nodePtr->next;
    }

    if (nodePtr->next != NULL) {
        Node *temp = nodePtr->next;
        nodePtr->next = temp->next;
        delete temp;
    }
}

void printList() {
    cout << "List: ";
    Node *nodePtr = head;
    while (nodePtr != NULL) {
        cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

int main() {
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);

    printList();

    deleteNode(3);
    cout << "After deleting 3: ";
    printList();

    deleteNode(1);
    cout << "After deleting 1: ";
    printList();

    return 0;
}
