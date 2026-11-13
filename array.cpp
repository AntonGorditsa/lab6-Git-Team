#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    if (!cin || n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    vector<int> a(n);
    vector<double> b(n);

    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100 + 1;
    }

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
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    if (secondOdd == -1) {
        cout << "\nLess than two odd elements!";
    }

    cout << endl;
    return 0;
}