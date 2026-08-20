#include <iostream>
using namespace std;

void printBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Binary (32-bit 2's complement) of " << n << " is: ";
    printBinary(n);

    return 0;
}
