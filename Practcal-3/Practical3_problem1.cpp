#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of Students :";
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the marks of student "<<i+1<<" : ";
        cin>>arr[i];
    }
    //Selection Sort
    cout<<"The marks of students(Selection sort): ";
    for(int i=0;i<n-1;i++)
{
    int min = i;

    for(int j=i+1;j<n;j++)
    {
        if(arr[j] < arr[min])
        {
            min = j;
        }
    }

    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
}
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    //Bubble Sort
    cout<<"The marks of students(Bubble Sort): ";
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    //Insertion Sort
    cout<<"The marks of students(Insertion Sort): ";
    for(int i=0;i<n;i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

   for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;


}
