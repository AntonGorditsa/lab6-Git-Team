#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int n = 14;

    int a[n] = {
        -4, 8, -6, 10, -2, 12, -8,
        14, -10, 16, -12, 18, -14, 20
    };

    double b[n];

    double sumNegative = 0;
    double sumPositive = 0;

    int countNegative = 0;
    int countPositive = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            sumNegative += a[i];
            countNegative++;
        }

        if (a[i] > 0) {
            sumPositive += a[i];
            countPositive++;
        }
    }

    double avgNegative = countNegative > 0
        ? sumNegative / countNegative : 1.0;

    double avgPositive = countPositive > 0
        ? sumPositive / countPositive : 0.0;

    for (int i = 0; i < n; i++) {
        b[i] = a[i];

        if ((i + 1) % 2 == 0 && a[i] < 0) {
            b[i] = avgNegative;
        }

        if ((i + 1) % 2 != 0) {
            b[i] = avgPositive;
        }
    }

    cout << fixed << setprecision(2);

    cout << "Original array: ";

    int i = 0;

    while (i < n) {
        cout << a[i] << " ";
        i++;
    }

    cout << "\nModified array: ";

    i = 0;

    while (i < n) {
        cout << b[i] << " ";
        i++;
    }

    cout << "\nAverage negative: "
         << avgNegative;

    cout << "\nAverage positive: "
         << avgPositive << endl;

    return 0;
}
