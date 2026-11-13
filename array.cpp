
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    vector<int> a(n);
    vector<double> b(n);

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
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
