#include <iostream>
using namespace std;

int main() {
    int n, base;
    int rem[100], i = 0;

    cout << "Enter decimal number: ";
    cin >> n;

    cout << "Enter base: ";
    cin >> base;

    while (n > 0) {
        rem[i] = n % base;
        n = n / base;
        i++;
    }

    cout << "Converted number: ";

    for (int j = i - 1; j >= 0; j--) {
        if (rem[j] < 10)
            cout << rem[j];
        else
            cout << char('A' + rem[j] - 10);
    }

    return 0;
}