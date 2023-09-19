#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int counter = 0;

    while (n >= 100) {
        n -= 100;
        counter++;
    }
    while (n >= 20) {
        n -= 20;
        counter++;
    }
    while (n >= 10) {
        n -= 10;
        counter++;
    }
    while (n >= 5) {
        n -= 5;
        counter++;
    }
    while (n >= 1) {
        n -= 1;
        counter++;
    }

    cout << counter;

    return 0;
}