#include <iostream>
using namespace std;

int main() {
    int table[10];

    for (int i = 0; i < 10; i++) {
        table[i] = -1;
    }

    int vehicles[] = {123, 456, 789, 234, 564, 894, 324};
    int n = 7;

    for (int i = 0; i < n; i++) {
        int number = vehicles[i];

        int index = number % 10;

        while (table[index] != -1) {
            index = (index + 1) % 10;
        }

        table[index] = number;
    }

    cout << "Final Parking Slots:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }

    return 0;
}