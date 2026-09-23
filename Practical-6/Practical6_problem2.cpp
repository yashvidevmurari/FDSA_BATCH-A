#include <iostream>
using namespace std;

class Stack
{
    struct Node
    {
        string page;
        Node* next;

        Node(string p)
        {
            page = p;
            next = NULL;
        }
    };

    Node* top;

public:

    Stack()
    {
        top = NULL;
    }

    void visit(string page)
    {
        Node* newNode = new Node(page);

        newNode->next = top;
        top = newNode;

        cout << "Visited page: " << page << endl;
        cout << "Current page: " << top->page << endl;
    }

    void back()
    {
        if (top == NULL)
        {
            cout << "No history left. Cannot go back." << endl;
            return;
        }

        cout << "Going back from: " << top->page << endl;

        Node* temp = top;
        top = top->next;

        delete temp;

        if (top == NULL)
            cout << "No page left." << endl;
        else
            cout << "Current page: " << top->page << endl;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "No page is currently open." << endl;
        }
        else
        {
            cout << "Current page: " << top->page << endl;
        }
    }
};


int main()
{
    Stack browser;

    int choice;

    do
    {
        cout << "\n1. Visit page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Current page" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                string page;

                cout << "Enter page name: ";
                cin >> page;

                browser.visit(page);
                break;
            }

            case 2:
                browser.back();
                break;

            case 3:
                browser.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 4);

    return 0;
}

