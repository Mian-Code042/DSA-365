#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert_at_Beg(int d) {
        Node* ptr = new Node(d);
        if (head == NULL) {
            head = tail = ptr;
        } else {
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
    }

    void insert_at_End(int d) {
        Node* ptr = new Node(d);
        if (head == NULL) {
            head = tail = ptr;
        } else {
            tail->next = ptr;
            ptr->prev = tail;
            tail = ptr;
        }
    }

    void insert_at_Loc(int d, int loc) {
        if (head == NULL && loc >= 2) {
            cout << "Not Possible (List is empty)" << endl;
            return;
        }

        if (loc == 1) {
            insert_at_Beg(d);
            return;
        }

        Node* temp = head;
        int count = 1;

        // Traverse till one node before desired location
        while (count < loc - 1 && temp != NULL) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "Not Possible (Location out of range)" << endl;
            return;
        }

        // Insert in between or at the end
        Node* ptr = new Node(d);
        ptr->next = temp->next;
        ptr->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = ptr;
        else
            tail = ptr; // update tail if inserted at end

        temp->next = ptr;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dl;

    dl.insert_at_Beg(10);
    dl.insert_at_End(20);
    dl.insert_at_End(30);
    dl.insert_at_Loc(25, 2); // ✅ valid
    dl.insert_at_Loc(40, 10); // ❌ invalid, will print Not Possible

    dl.display();

    return 0;
}
