#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> table[10];

    int books[] = {25, 35, 42, 52, 63, 73, 84, 94};
    int n = 8;

    
    for (int i = 0; i < n; i++) {
        int code = books[i];

        int index = code % 10;

        
        table[index].push_back(code);
    }

    cout << "Final Shelf Contents:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";

        if (table[i].empty()) {
            cout << "Empty";
        } else {
            for (int book : table[i]) {
                cout << book << " ";
            }
        }

        cout << endl;
    }

    return 0;
}