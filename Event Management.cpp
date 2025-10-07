// event_system.cpp

#include <bits/stdc++.h>
using namespace std;


// =========================
// Participant ka structure (Node of Linked List)
// Har participant ka ID, Name, Email store hota hai
// =========================


struct Participant {
    int regID;
    string name;
    string email;
    Participant* next;

    Participant(int id, const string& n, const string& e)
        : regID(id), name(n), email(e), next(NULL) {}
};


// =========================
// Singly Linked List class
// Yeh class participant list manage karti hai (Registered aur Waiting dono ke liye use hogi)
// =========================


class SinglyList {
private:
    Participant* head;   // pehla node
    Participant* tail;   // akhri node
    int size;            // kitne participants hain list me
public:
    SinglyList(): head(NULL), tail(NULL), size(0) {}
    ~SinglyList() { clear(); }

    int getSize() const { return size; }

    // List ke end me participant add karna
    
    
    void pushBack(int id, const string& name, const string& email) {
        Participant* node = new Participant(id, name, email);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
        ++size;
    }

    // Kisi ID se participant delete karna
    
    
    bool removeByID(int id) {
        Participant* cur = head;
        Participant* prev = NULL;
        while (cur) {
            if (cur->regID == id) {
                if (prev) prev->next = cur->next;
                else head = cur->next;
                if (cur == tail) tail = prev;
                delete cur;
                --size;
                return true;
            }
            prev = cur; cur = cur->next;
        }
        return false;
    }

    // Pehla participant nikalna (Waiting list se Registered me move karne ke liye)
    
    
    Participant* popFront() {
        if (!head) return NULL;
        Participant* node = head;
        head = head->next;
        if (!head) tail = NULL;
        node->next = NULL;
        --size;
        return node;
    }

    // Email se search karna
    
    
    Participant* findByEmail(const string& email) {
        Participant* cur = head;
        while (cur) {
            if (cur->email == email) return cur;
            cur = cur->next;
        }
        return NULL;
    }

    // Sab participants show karna
    
    
    void displayAll() const {
        Participant* cur = head;
        if (!cur) {
            cout << "  [Empty]\n";
            return;
        }
        cout << left << setw(6) << "ID" << setw(20) << "Name" << setw(30) << "Email" << '\n';
        cout << string(60, '-') << '\n';
        while (cur) {
            cout << setw(6) << cur->regID << setw(20) << cur->name << setw(30) << cur->email << '\n';
            cur = cur->next;
        }
    }

    // Saari list clear karna (memory free karna)
    
    
    void clear() {
        while (head) {
            Participant* tmp = head;
            head = head->next;
            delete tmp;
        }
        head = tail = NULL; size = 0;
    }
};

// =========================
// Menu show karna user ke liye
// =========================


void showMenu() {
    cout << "\n=== Event Management System ===\n";
    cout << "1. Register participant\n";
    cout << "2. Cancel registration (by ID)\n";
    cout << "3. Display all registered participants\n";
    cout << "4. Display waiting list\n";
    cout << "5. Search by email\n";
    cout << "6. Clear all data\n";
    cout << "7. Exit\n";
    cout << "Choose option: ";
}

int main() {
    SinglyList registered, waiting;   // do lists: registered aur waiting
    const int MAX_REGISTERED = 10;    // max 50 log register ho sakte hain
    int nextRegID = 1001;             // IDs 1001 se shuru hongi
    int choice;

    while (true) {
        showMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // -------------------
        // OPTION 1: Register participant
        // -------------------
        
        
        if (choice == 1) {
            string name, email;
            cout << "Enter participant name: ";
            getline(cin, name);
            cout << "Enter email: ";
            getline(cin, email);

            // Duplicate check: agar email already registered ya waiting list me hai
            
            
            if (registered.findByEmail(email) || waiting.findByEmail(email)) {
                cout << "This email is already registered or in waiting list.\n";
                continue;
            }

            // Agar jagah hai to registered me daalo, warna waiting me
            
            
            if (registered.getSize() < MAX_REGISTERED) {
                registered.pushBack(nextRegID, name, email);
                cout << "Registered with ID: " << nextRegID << " (Registered)\n";
            } else {
                waiting.pushBack(nextRegID, name, email);
                cout << "Event full. Added to waiting list with ID: " << nextRegID << " (Waiting)\n";
            }
            ++nextRegID;
        }

        // -------------------
        // OPTION 2: Cancel registration
        // -------------------
        
        
        else if (choice == 2) {
            int id;
            cout << "Enter Registration ID to cancel: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Registered list se remove karne ki koshish
            
            
            bool removedFromRegistered = registered.removeByID(id);
            if (removedFromRegistered) {
                cout << "Removed from registered list.\n";
                
                
                // Agar waiting list me koi hai to usse registered me move karo
                
                
                Participant* p = waiting.popFront();
                if (p) {
                    registered.pushBack(p->regID, p->name, p->email);
                    cout << "Moved from waiting into registered: ID " << p->regID << '\n';
                    delete p;
                }
            } else {
            	
                // Waiting list se remove karne ki koshish
                
                
                bool removedFromWaiting = waiting.removeByID(id);
                if (removedFromWaiting) cout << "Removed from waiting list.\n";
                else cout << "ID not found in either list.\n";
            }
        }

        // -------------------
        // OPTION 3: Show Registered participants
        // -------------------
        
        
        else if (choice == 3) {
            cout << "\n-- Registered Participants (" << registered.getSize() << ") --\n";
            registered.displayAll();
        }

        // -------------------
        // OPTION 4: Show Waiting list
        // -------------------
        
        
        else if (choice == 4) {
            cout << "\n-- Waiting List (" << waiting.getSize() << ") --\n";
            waiting.displayAll();
        }

        // -------------------
        // OPTION 5: Search by Email
        // -------------------
        
        
        else if (choice == 5) {
            string email;
            cout << "Enter email to search: ";
            getline(cin, email);
            Participant* p = registered.findByEmail(email);
            if (p) {
                cout << "Found in Registered: ID " << p->regID << ", Name: " << p->name << '\n';
            } else {
                p = waiting.findByEmail(email);
                if (p) cout << "Found in Waiting list: ID " << p->regID << ", Name: " << p->name << '\n';
                else cout << "Not found.\n";
            }
        }

        // -------------------
        // OPTION 6: Clear all data
        // -------------------
        
        
        else if (choice == 6) {
            registered.clear();
            waiting.clear();
            cout << "All data cleared.\n";
        }

        // -------------------
        // OPTION 7: Exit
        // -------------------
        
        
        else if (choice == 7) {
            cout << "Exiting. Goodbye!\n";
            break;
        }

        else {
            cout << "Invalid option. Try again.\n";
        }
    }
    return 0;
}
