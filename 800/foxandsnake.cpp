#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string fill(m, '#'), empty(m - 1, '.');

    int left = false;

    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            cout << fill << "\n";
        else if (left) {
            cout << '#' << empty << "\n";
            left = !left;
        }
        else {
            cout << empty << '#' << "\n";
            left = !left;
        }

    return 0;
}