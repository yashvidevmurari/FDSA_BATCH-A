#include <iostream>
#include <string>
using namespace std;

// Iterative Binary Search
int iterativeBinarySearch(string arr[], int n, string target)
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

// Recursive Binary Search
int recursiveBinarySearch(string arr[], int low, int high, string target)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return recursiveBinarySearch(arr, mid + 1, high, target);
    else
        return recursiveBinarySearch(arr, low, mid - 1, target);
}

int main()
{
    int n;

    cout << "Enter number of book codes: ";
    cin >> n;

    string books[n];

    cout << "Enter SORTED book codes:\n";
    for (int i = 0; i < n; i++)
        cin >> books[i];

    string target;
    cout << "Enter target book code: ";
    cin >> target;

    int result1 = iterativeBinarySearch(books, n, target);

    if (result1 != -1)
        cout << "Iterative Binary Search: Found at position " << result1 + 1 << endl;
    else
        cout << "Book code not found." << endl;

    int result2 = recursiveBinarySearch(books, 0, n - 1, target);

    if (result2 != -1)
        cout << "Recursive Binary Search: Found at position " << result2 + 1 << endl;
    else
        cout << "Book code not found." << endl;

    return 0;
}