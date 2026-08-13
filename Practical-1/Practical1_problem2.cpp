#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the record of book:";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"\nBorrow book which is more than one:";


    for(int i=0;i<n;i++)
    {
        bool printed = false;

        for(int k = 0; k < i; k++)
        {
            if(arr[i] == arr[k])
            {
                printed = true;
                break;
            }
        }

        if(printed)
            continue;

        int count=1;
        for(int j=i+1; j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;

            }
        }
         if(count > 1)
        {
            cout << arr[i] << " = " << count << endl;
        }

    }

    return 0;
}
