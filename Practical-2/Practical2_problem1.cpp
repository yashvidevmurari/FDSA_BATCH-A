#include<iostream>
#include<string>
using namespace std;
int iterativeSearch(string arr[], int n, string x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int recursiveSearch(string arr[], int n, string x) {
    if (n <= 0) {
        return -1;
    }
    if (arr[n - 1] == x) {
        return n - 1;
    }
    return recursiveSearch(arr, n - 1, x);
}

int main()
{
    int n;
    cout<<"Enter the no. of vehicle: ";
    cin>>n;

    string arr[n];
    cout<<"Enter the vehicle number(plate no.): ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    string target;
    cout<<"Enter the vehicle number to search(plate no.): ";
    cin>>target;

    int r1= iterativeSearch(arr, n, target);
    if(r1 != -1)
    {
        cout<<"Vehicle number found at index(iterative search): "<<r1<<endl;
    }
    else
    {
        cout<<"Vehicle number not found in iterative search."<<endl;
    }

    int r2= recursiveSearch(arr, n, target);
    if(r2 != -1)
    {
        cout<<"Vehicle number found at index(recursive search): "<<r2<<endl;
    }
    else
    {
        cout<<"Vehicle number not found in recursive search."<<endl;
    }

    return 0;

}
