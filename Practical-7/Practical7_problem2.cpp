#include <iostream>
using namespace std;

struct Node
{
    int patient;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;


void arrive(int patient)
{
    Node *newNode = new Node();

    newNode->patient = patient;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Patient " << patient << " arrived.\n";
    cout << "Front patient: " << front->patient << endl;
}


void attend()
{

    if (front == NULL)
    {
        cout << "Queue is empty. No patient can be attended.\n";
        return;
    }

    Node *temp = front;

    cout << "Patient " << front->patient << " attended.\n";

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    delete temp;

    if (front != NULL)
        cout << "Front patient: " << front->patient << endl;
    else
        cout << "No patients waiting.\n";
}

int main()
{
    int operations;

    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++)
    {
        int choice;

        cout << "\n1. Arrive";
        cout << "\n2. Attend";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int patient;

            cout << "Enter patient number: ";
            cin >> patient;

            arrive(patient);
        }
        else if (choice == 2)
        {
            attend();
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

