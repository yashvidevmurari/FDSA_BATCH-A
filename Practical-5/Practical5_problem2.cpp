#include <iostream>
using namespace std;

class SinglyCircular {
    struct Node {
        string name;
        Node* next;

        Node(string n) {
            name = n;
            next = NULL;
        }
    };

    Node* head;

public:

    SinglyCircular() {
        head = NULL;
    }

    void add(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    void remove(string name) {
        if (head == NULL)
            return;

        Node* current = head;
        Node* previous = NULL;

        do {
            if (current->name == name) {

                if (current->next == head) {
                    head = NULL;
                    delete current;
                    return;
                }

                if (current == head) {
                    Node* last = head;

                    while (last->next != head) {
                        last = last->next;
                    }

                    head = head->next;
                    last->next = head;

                    delete current;
                    return;
                }


                previous->next = current->next;
                delete current;
                return;
            }

            previous = current;
            current = current->next;

        } while (current != head);
    }

    // Display
    void display() {
        if (head == NULL) {
            cout << "Singly: Empty" << endl;
            return;
        }

        Node* temp = head;

        cout << "Singly: ";

        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to " << head->name << ")" << endl;
    }
};

class DoublyCircular {
    struct Node {
        string name;
        Node* next;
        Node* prev;

        Node(string n) {
            name = n;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head;

public:

    DoublyCircular() {
        head = NULL;
    }

    void add(string name) {
        Node* newNode = new Node(name);


        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }


    void remove(string name) {
        if (head == NULL)
            return;

        Node* current = head;

        do {
            if (current->name == name) {


                if (current->next == head) {
                    head = NULL;
                    delete current;
                    return;
                }


                if (current == head) {
                    head = head->next;
                }


                current->prev->next = current->next;
                current->next->prev = current->prev;

                delete current;
                return;
            }

            current = current->next;

        } while (current != head);
    }


    void display() {
        if (head == NULL) {
            cout << "Doubly: Empty" << endl;
            return;
        }

        Node* temp = head;

        cout << "Doubly: ";

        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to " << head->name << ")" << endl;
    }
};


int main() {

    SinglyCircular singly;
    DoublyCircular doubly;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        int choice;
        cout << "\n1. Join";
        cout << "\n2. Leave";
        cout << "\n3. Display";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {

            string name;
            cout << "Enter student name: ";
            cin >> name;

            singly.add(name);
            doubly.add(name);

            cout << "Student joined: " << name << endl;

            singly.display();
            doubly.display();
        }

        else if (choice == 2) {

            string name;
            cout << "Enter student name: ";
            cin >> name;

            singly.remove(name);
            doubly.remove(name);

            cout << "Student left: " << name << endl;

            singly.display();
            doubly.display();
        }

        else if (choice == 3) {

            singly.display();
            doubly.display();
        }

        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
