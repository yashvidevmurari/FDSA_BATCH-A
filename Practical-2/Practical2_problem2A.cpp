#include <iostream>
#include <string>
using namespace std;

// Iterative Linear Search
int iterativeLinearSearch(string arr[], int n, string target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// Recursive Linear Search
int recursiveLinearSearch(string arr[], int n, string target, int index)
{
    if (index == n)
        return -1;

    if (arr[index] == target)
        return index;

    return recursiveLinearSearch(arr, n, target, index + 1);
}

int main()
{
    int n;

    cout << "Enter number of book codes: ";
    cin >> n;

    string books[n];

    cout << "Enter book codes:\n";
    for (int i = 0; i < n; i++)
        cin >> books[i];

    string target;
    cout << "Enter target book code: ";
    cin >> target;

    int result1 = iterativeLinearSearch(books, n, target);

    if (result1 != -1)
        cout << "Iterative Linear Search: Found at position " << result1 + 1 << endl;
    else
        cout << "Book code not found." << endl;

    int result2 = recursiveLinearSearch(books, n, target, 0);

    if (result2 != -1)
        cout << "Recursive Linear Search: Found at position " << result2 + 1 << endl;
    else
        cout << "Book code not found." << endl;

    return 0;
}