
#include <iostream>
using namespace std;

int main() {
    const int n = 12;
    int a[n] = {2, 5, 8, 3, 10, 12, 7, 4, 6, 9, 14, 16};
    double b[n];

    int count = 0;
    int secondOdd = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            count++;
            if (count == 2) {
                secondOdd = i;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        b[i] = a[i];

        if (secondOdd != -1 && i >= secondOdd) {
            b[i] = (double)a[i] / a[secondOdd];
        }
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << "\nNew array: ";
    for (int i = 0; i < n; i++) {s
        cout << b[i] << " ";
    }

    if (secondOdd == -1) {
        cout << "\nLess than two odd elements!";
    }

    cout << endl;
    return 0;
}
