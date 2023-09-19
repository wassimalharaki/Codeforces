#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n % 2 == 0)
            cout << n / 2 - 1;
        else
            cout << n / 2;
        cout << endl;
    }

    return 0;
}