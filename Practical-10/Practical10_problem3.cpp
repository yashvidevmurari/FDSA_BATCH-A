#include <iostream>
using namespace std;

int main() {
    int table[10];

    for (int i = 0; i < 10; i++) {
        table[i] = -1;
    }

    int ids[] = {23, 43, 13, 27, 37, 57};
    int n = 6;

    for (int i = 0; i < n; i++) {
        int id = ids[i];

        int index = id % 10;


        int jump = 7 - (id % 7);

        while (table[index] != -1) {
            index = (index + jump) % 10;
        }

        table[index] = id;
    }

    cout << "Final Hash Table:\n";

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
