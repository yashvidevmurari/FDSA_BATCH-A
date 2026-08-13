#include <iostream>
#include <string>
using namespace std;

int binaryIterative(string arr[], int n, string target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int binaryRecursive(string arr[], int low, int high, string target)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binaryRecursive(arr, mid + 1, high, target);
    else
        return binaryRecursive(arr, low, mid - 1, target);
}

int main()
{
    int n;

    cout << "Enter number of license plates: ";
    cin >> n;

    string plates[n];

    cout << "Enter license plates (in sorted order):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> plates[i];
    }

    string target;
    cout << "Enter target plate: ";
    cin >> target;

    int pos1 = binaryIterative(plates, n, target);

    if (pos1 != -1)
        cout << "Iterative Binary Search: Plate found at position " << pos1 + 1 << endl;
    else
        cout << "Plate not found." << endl;

    int pos2 = binaryRecursive(plates, 0, n - 1, target);

    if (pos2 != -1)
        cout << "Recursive Binary Search: Plate found at position " << pos2 + 1 << endl;
    else
        cout << "Plate not found." << endl;

    return 0;
}