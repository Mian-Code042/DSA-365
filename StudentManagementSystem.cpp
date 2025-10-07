#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Single {
private:
    Node* head;
    Node* tail;

public:
    Single() {
        head = NULL;
        tail = NULL;
    }

    void insertAtFront(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        cout << "Student " << value << " added at the front of the list.\n";
    }
   
    void removeFromFront() {
        if (head == NULL) {
            cout << "No student to remove. List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Student " << head->data << " removed from the front.\n";
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Students in the system: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Single studentList;
    studentList.insertAtFront(101);
    studentList.insertAtFront(102);
    studentList.insertAtFront(103);

    studentList.display();

    studentList.removeFromFront();
    studentList.display();

    studentList.removeFromFront();
    studentList.display();

    studentList.removeFromFront();
    studentList.display();

    studentList.removeFromFront();

    return 0;
}
