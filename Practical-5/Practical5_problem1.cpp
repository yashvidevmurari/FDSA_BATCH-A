#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    void addBeginning(string song)
     {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } 
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        count++;
        cout << "Added at beginning: " << song << endl;
        display();
    }

   
    void addEnd(string song) {
        Node* newNode = new Node(song);

        if (tail == NULL) {
            head = tail = newNode;
        } 
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        count++;
        cout << "Added at end: " << song << endl;
        display();
    }

   
    void insertAfter(string giveSong, string newSong) {
        Node* current = head;

        while (current != NULL && current->song != giveSong) {
            current = current->next;
        }

       
        if (current == NULL) {
            cout << "Song not found: " << giveSong << endl;
            display();
            return;
        }

        Node* newNode = new Node(newSong);

        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != NULL) {
            current->next->prev = newNode;
        } 
        else {
        
            tail = newNode;
        }

        current->next = newNode;

        count++;

        cout << "Inserted " << newSong
             << " after " << giveSong << endl;

        display();
    }

    
    void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node* temp = head;

        if (head == tail) {
            head = tail = NULL;
        } 
        else {
            head = head->next;
            head->prev = NULL;
        }

        cout << "Removed: " << temp->song << endl;

        delete temp;
        count--;

        display();
    }

    void showCount() {
        cout << "Number of songs: " << count << endl;
    }

    void display() {
        Node* current = head;

        cout << "Playlist: ";

        if (current == NULL) {
            cout << "Empty";
        }

        while (current != NULL) {
            cout << current->song;

            if (current->next != NULL) {
                cout << " <-> ";
            }

            current = current->next;
        }

        cout << endl;
    }
};

int main() {

    Playlist p;

    p.addEnd("Shape of You");

    p.addEnd("Perfect");

    p.addBeginning("Believer");

    p.insertAfter("Perfect", "Daylight");

    p.insertAfter("Believer", "Senorita");

    p.showCount();

    p.removeFirst();

    p.showCount();

    p.insertAfter("Pretty,Women!", "Chery Chery Lady");

    return 0;
}