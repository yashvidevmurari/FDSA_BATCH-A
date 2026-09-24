#include<iostream>
using namespace std;

class Queue {
private:
    int rear;
    int front;
    int* queue;
    int size;

public:
    Queue(int s) {
        size = s;
        front = -1;
        rear = -1;
        queue = new int[size];
    }

    void join(int value)
    {
        if((rear+1)%size==front)
        {
            cout<<"Queue is full.\n Token "<<value<<"  cannot be added."<<endl;
            return;
        }

        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            rear=(rear+1)%size;
        }
        queue[rear]=value;

        cout<<"Token "<<value<<" joined.\n";
        cout<<"Front Token:"<<queue[front]<<endl;
    }

    void serve()
    {
        if(front==-1)
        {
            cout<<"Queue is empty. No token to serve."<<endl;
            return;
        }

        cout<<"Token "<<queue[front]<<" served.\n";

        if(front== rear)
        {
            front = -1;
            rear=-1;

        }
        else
        {
            front=(front+1)%size;
        }

        if(front != -1)
        {
            cout<<"Front Token:"<<queue[front]<<endl;
        }

    else
    cout<<"Queue is empty. No front token."<<endl;
    }



};

int main()
{
    int  n;
    cout<<"Enter the Queue Capacity: ";
    cin>>n;
    Queue q(n);

    int operations;
    cout<<"Enter the number of operations: ";
    cin>>operations;

    for(int i=0; i<operations; i++)
    {
        int choice;
        cout<<"Enter 1. to join a token, 2. to serve a token: ";
        cin>>choice;

        if(choice==1)
        {
            int token;
            cout<<"Enter token number:";
            cin>>token;
            q.join(token);

        }
        else if(choice==2)
        {
            q.serve();
        }
        else
        {
            cout<<"Invalid choice. Please enter 1 or 2."<<endl;
        }

    }
       return 0;

}
