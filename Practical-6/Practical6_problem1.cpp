#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int size;

public:

    Stack(int n)
    {
        size = n;
        arr = new int[size];
        top = -1;
    }

    void push(int x)
    {
        if (top == size - 1)
        {
            cout << "Counter is full. No more tray will be added." << endl;
            return;
        }

        top++;
        arr[top] = x;

        cout << "Tray " << x << " added to counter." << endl;
        cout << "Top tray: " << arr[top] << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Counter is empty. No tray to remove." << endl;
            return;
        }

        cout << "Tray " << arr[top] << " removed from counter." << endl;
        top--;

        if (top == -1)
            cout << "Top tray: None" << endl;
        else
            cout << "Top tray: " << arr[top] << endl;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Counter is empty. No tray to display." << endl;
            return;
        }

        cout << "Trays in counter: ";

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
        cout << "Top tray: " << arr[top] << endl;
    }
};


int main()
{
    int n;

    cout << "Enter the size of the counter: ";
    cin >> n;

    Stack s(n);

    int choice;

    do
    {
        cout << "\n1. Add tray to counter" << endl;
        cout << "2. Remove tray from counter" << endl;
        cout << "3. Display trays in counter" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int x;

                cout << "Enter tray number to add: ";
                cin >> x;

                s.push(x);
                break;
            }

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while(choice != 4);

    return 0;
}
